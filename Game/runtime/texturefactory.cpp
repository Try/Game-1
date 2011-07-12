#include "texturefactory.h"

#include "dataCtrl/pixmaps.h"

#include <MyGL/IData>
#include <MyGL/Texture2d>

#include <MyGL/Color>

#include <QImage>
#include <QColor>

#include <QDebug>

TextureFactory *TextureFactory::instance = 0;

TextureFactory::TextureFactory( MyGL::IScene &s ):scene(s){
    instance = this;
    }

TextureFactory::~TextureFactory(){
    for( Cash::iterator i=cash.begin(); i!=cash.end(); ++i){
      // delete i->second;
      }
    }

MyGL::ITexture2d* TextureFactory::genTexture( const std::string& name,
                                              const std::string& base,
                                              const std::string& mask,
                                              const QColor &color){
    Cash::iterator i=instance->cash.find(name);

    if( i==instance->cash.end() ){
      //return Pixmaps::get(name);
      QImage imgTex;
      buildTexture( imgTex, color,
                    Pixmaps::get(base), Pixmaps::get(mask));

      MyGL::ITexture2d *tex =
               instance->scene.dataControl()->
                    addTexture( name.data(),
                                instance->creteTexture(imgTex) );
      instance->cash[name] = tex;
      return tex;
      } else {
      return i->second;
      }
    }

MyGL::ITexture2d* TextureFactory::creteTexture( QImage &img ){
		QImage image;
		image      = img.rgbSwapped();

		MyGL::Texture2d *tex = new MyGL::Texture2d( scene.render() );

		tex->loadMipMaps
							 ( image.bits(),
								 MyGL::ITexture::InputFormat::RGBA8,
								 image.width(), image.height(),
								 MyGL::ITexture::Format::RGBA_DXT5 );
		return tex;
		}

void TextureFactory::buildTexture(QImage &tex,
																	const QColor &color,
																	QImage *base,
																	QImage *mask){
		if( mask==0 ){
			if( base )
				tex = *base;
			return;
			}

		if( base==0 )
			return;

		tex = *base;

		if( base->width() != mask->width() ||
				base->height()!= mask->height() )
			return;

		// qDebug() << color;

		for(int i=0; i<base->width(); ++i)
			for(int r=0; r<base->height(); ++r){
				if( QColor(mask->pixel(i,r)).blue()>0 ){
					float a  = QColor(mask->pixel(i,r)).blue()/255.0,
								a1 = 1.0-a;

					QColor re = QColor(tex.pixel(i,r)),
								 de = color;

					re = QColor(re.red()*a1, re.green()*a1, re.blue()*a1);
					de = QColor(de.red()*a,  de.green()*a,  de.blue()*a );

					re = QColor( re.red() + de.red(),
											 re.green() + de.green(),
											 re.blue() + de.blue(), 255);

					tex.setPixel(i,r, re.rgba() );
					}
				}
		}
