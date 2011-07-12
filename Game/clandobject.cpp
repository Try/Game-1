#include "clandobject.h"

#include <MyGL/IScene>
#include <MyGL/IData>

#include <MyGL/Model>
#include <MyGL/IOModel>

#include <MyGL/TextureRectangle>

#include "dataCtrl/materials.h"
#include "game/game.h"

#include <QDebug>
#include <QPainter>
#include <cmath>

#include "graphis/landtechnicue.h"
#include "graphis/virtualtexturingpass.h"

using namespace MyGL;
using namespace std;

std::vector<CLandObject::Tail> CLandObject::m_tailMask;
std::vector<QImage>            CLandObject::m_tailData;

int CLandObject::tailMapResolution = 2;

CLandObject::CLandObject(IScene &scene,
												 const std::string &src)
						:object(scene){
		object.setAlvaysVisible(1);

		model    = new MyGL::Model( scene.render() );
		model->unsetCullInfo();

		material = new MyGL::StdMaterial( scene, new LandTechnicue(scene) );

		material->setDiffuseTexture ( scene.dataControl()->
																 texture( src + ".diff") );
		material->setSpecularTexture( scene.dataControl()->
																 texture( src + ".spec") );
		material->setNormalTexture  ( scene.dataControl()->
																 texture( src + ".norm") );

		material->setGlowTexture    ( 0 );
		material->useGlow(0);

		material->setShadowTexture(
					scene.dataControl()->texture("MyGL::shadow_map_texture") );

		std::set< std::string > macro;
		macro.insert("LAMBERT");
		macro.insert("NORMAL");
		macro.insert("VIRTUAL"); //!

		IShader * sh =  Materials::instance().get( macro, 1 );
		material->setShader      ( sh );
		material->setShadowShader( Materials::instance().getShadowShader() );

		material->setDepthShader ( scene.dataControl()->shader ("depth")  );
		material->setGlowShader  ( scene.dataControl()->shader ("glow")  );

		object.setModel( model );
		object.setMaterial( material );
		object.setPosition(0,0,0);

		material->useDepthPass(0);

		m_tailMask.resize(3);
		m_tailMask[0].texture = scene.dataControl()->texture( "land.diff");
		m_tailMask[1].texture = scene.dataControl()->texture( "sand.diff");
		m_tailMask[2].texture = scene.dataControl()->texture( "ggrass.diff");

		for(size_t i=0; i<m_tailMask.size(); ++i){
			m_tailMask[i].mask = new MyGL::TextureRectangle(scene.render());
			m_tailMask[i].mask->setFiltration( MyGL::ITexture::FilterType::Linear,
																				 MyGL::ITexture::FilterType::Linear );
			}

		m_tailData.resize( m_tailMask.size() );


		allock(64, 64);
		}

CLandObject::~CLandObject(){
		for(size_t i=0; i<m_tailMask.size(); ++i)
			delete m_tailMask[i].mask;

		delete model;
		delete material;
		}

void CLandObject::resize(int x, int y){
		allock(x,y);
		VirtualTexturingPass::setMapSize(x, y,
																		 w*tailMapResolution,
																		 h*tailMapResolution);
		}

void CLandObject::setPosition(float x, float y, float z){
		object.setPosition(x,y,z);
		}

void CLandObject::setPoint(int px, int py, float x, float y, float z){

		setVertex(model->vertexBuffer(), px, py, 0,
							x,y,z);
		setVertex(model->vertexBuffer(), px-1, py, 1,
							x,y,z);
		setVertex(model->vertexBuffer(), px, py-1, 2,
							x,y,z);
		setVertex(model->vertexBuffer(), px-1, py-1, 3,
							x,y,z);
		}

void CLandObject::setVertex(MyGL::IVBO &vbo,
														int  px, int  py, int   c,
														float x, float y, float z){
		if( px<0 || px>=w ||
				py<0 || py>=h )
			return;

		size_t size = (( px+(py*w) )*4+c)*3*sizeof(float);

		float xyz[] = {x,y,z};

		vbo.subData(size, 3*sizeof(float), xyz);
		}

void CLandObject::allock(int width, int height){
		w = width  + 30;
		h = height + 30;

		size_t size = w*h*4;

		model->allocate(size);
		build();
		model->setPrimitivesType( IVBO::PrimitiveType::Quads );

		for(size_t i=0; i<m_tailData.size(); ++i)
			m_tailData[i] = QImage(w*tailMapResolution,
														 h*tailMapResolution, QImage::Format_ARGB32);

		{
			QPainter p( &m_tailData[0] );
			p.fillRect( QRect(0,0, w*tailMapResolution,
														 h*tailMapResolution ), Qt::white );
			}
		normalize(0);

		// drawTail(1, 10, 10, 2);
		}

void CLandObject::drawTail(int id, int x, int y,  float size){
		x = x+15;
		y = y+15;

		x*=tailMapResolution;
		y*=tailMapResolution;

		id = min( (int)m_tailData.size(), max(id, 0) );

		QPainter p(&m_tailData[id]);

		p.setBrush( Qt::white );
		p.setPen( Qt::NoPen );
		p.drawEllipse( QPoint(x,y), int(size), int(size) );
		normalize(id);
		}

void CLandObject::normalize(int id){
		for(int x=0; x<w*tailMapResolution; ++x)
			for(int y=0; y<h*tailMapResolution; ++y){
				int l = QColor(m_tailData[id].pixel(x,y)).red();
				double s = 0;

				for(size_t i=0; i<m_tailData.size(); ++i){
					s += QColor(m_tailData[i].pixel(x,y)).red();
					}
				s = std::min(255.0, s);

				double k = 0.0;
				if( s-l > 0.0 )
					k = 255.0/(s-l);

				for(size_t i=0; i<m_tailData.size(); ++i)
					if( (int)i!=id ){
						int r = QColor(m_tailData[i].pixel(x,y)).red()*k;
						m_tailData[i].setPixel(x,y, QColor(r,r,r,255).rgba() );
						}
				}

		for(size_t i = 0; i<m_tailMask.size(); ++i){
			MyGL::TextureRectangle *t = m_tailMask[i].mask;
			QImage &image = m_tailData[i];//.rgbSwapped();
			// image.save("./result["+QString::number(i)+"].png", "PNG");

			t->load
					( image.bits(),
						MyGL::ITexture::InputFormat::RGBA8,
						image.width(), image.height(),
						MyGL::ITexture::Format::RGBA_DXT5 );
			}
		}

void CLandObject::build(){
		float v[] = { 0 , 0, 0,
									1 , 0, 0,
									1 , 1, 0,
									0 , 1, 0,
									0 , 0, 0};

		IVBO::IPointer* p = model->vertexBuffer(). pointerToData();
		IVBO::IPointer* t = model->textureBuffer().pointerToData();
		IVBO::IPointer* n = model->normalBuffer(). pointerToData();
		IVBO::IPointer* b = model->extraBuffer().  pointerToData();

		for(int i=0; i<w; ++i)
			for(int r=0; r<h; ++r){
				float *vert = & (*p)[ (i+r*w)*4*3 ];
				float *tex  = & (*t)[ (i+r*w)*4*2 ];
				float *norm = & (*n)[ (i+r*w)*4*3 ];
				float *bi   = & (*b)[ (i+r*w)*4*4 ];

				for(int c=0; c<4; ++c){
					float x = v[c*3+0]+i-15,
								y = v[c*3+1]+r-15;
					vert[c*3  ] = x;
					vert[c*3+1] = y;

					vert[c*3+2] = getHeight(x,y);

					tex[c*2  ] = (vert[c*3+0]+15)/w;
					tex[c*2+1] = (vert[c*3+1]+15)/h;
					/*
					tex[c*2  ] = vert[c*3+0]*0.25;///w;
					tex[c*2+1] = vert[c*3+1]*0.25;///h;*/

					norm[c*3  ] = (getHeight(x-1,y)-getHeight(x+1,y));
					norm[c*3+1] = (getHeight(x,y-1)-getHeight(x,y-1));
					norm[c*3+2] = 1;
					float l = sqrt( norm[c*3  ]*norm[c*3  ] +
													norm[c*3+1]*norm[c*3+1] +
													norm[c*3+2]*norm[c*3+2]);

					for(int i=0; i<3; ++i)
						norm[c*3+i] /= l;

					bi[c*4  ] = 1;
					bi[c*4+1] = 0;
					bi[c*4+2] = 0;
					bi[c*4+3] = 0;
					}
				}

		delete p;
		delete t;
		delete n;
		delete b;
		}

float CLandObject::getHeight(float x, float y){
		return Game::instance().map.heightf( x,y );
		}

void CLandObject::setPoint(float *p, float x, float y){
    p[0] = x;
    p[1] = y;
    }

void CLandObject::setPoint(float *p, float x, float y, float z){
    p[0] = x;
    p[1] = y;
    p[2] = z;
    }

std::vector<CLandObject::Tail>& CLandObject::tailMask(){
    return m_tailMask;
    }
