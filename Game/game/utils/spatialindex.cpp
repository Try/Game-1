#include "spatialindex.h"

#include <vector>

#include "globject.h"

#include <cmath>

#include <QDebug>

SpatialIndex *SpatialIndex::inst = 0;

class SpatialIndex::Data{
  public:
    Data(){
      for(int i=0; i<2; ++i)
        for(int r=0; r<2; ++r)
          data[i][r] = -1;

      object = 0;
      w = 0;
      h = 0;
      }

    Data(const Data &other){
      *this = other;
      }

    static std::vector<Data> objects;
    static int  objCount;

    static int allock(){
      if( (unsigned)objCount>=objects.size() )
        objects.push_back( Data() );

      objects[objCount] = Data();
      ++objCount;
      return objCount-1;
      }

    int data[2][2];
    GLObject* object;

    float w, h;

    void add( GLObject* obj, float x, float y, int depth);
    GLObject* findNearest(GLObject*, float x, float y, filterFunc);
    bool      findNearestByCoord(GLObject *&re, int x, int y,
                                 GLObject *obj, float rx, float ry,
                                 filterFunc f);

    GLObject* findValidate( GLObject*, GLObject* , GLObject*, filterFunc);
    GLObject* nearestTo( GLObject*, GLObject* , GLObject*);
  };

std::vector<SpatialIndex::Data> SpatialIndex::Data::objects;
int SpatialIndex::Data::objCount = 0;

SpatialIndex::SpatialIndex() {
    inst = this;
    }

SpatialIndex::~SpatialIndex(){
    inst = 0;
    }

void SpatialIndex::clear(int w, int h){
    //Data::objects.clear();
    Data::objects.resize(w*h);//push_back( Data() );
    Data::objCount = 1;

    Data::objects[0] = Data();
    Data::objects[0].w = w;
    Data::objects[0].h = h;
    }

void SpatialIndex::add( GLObject* obj ){
    // qDebug() << obj->getClass()->name.data();
    Data::objects[0].add(obj, obj->x(), obj->y(), 128 );
    }

void SpatialIndex::Data::add( GLObject* obj, float rx, float ry, int depth){
    int x = (rx > w/2),
        y = (ry > h/2);

    if( object /*&& depth>0*/ ){
      int d = -1;

      if( data[x][y]<0 ) {
        d = Data::objCount;
        data[x][y] = d;

        d = allock();
        Data *dat = &objects[d];

        dat->w = w/2;
        dat->h = h/2;
        dat->object = 0;
        } else {
        d = data[x][y];
        }

      objects[d].add(obj, rx-x*w/2, ry-y*h/2, depth-1 );
      } else {
      object = obj;
      //if(depth==0)
       //qDebug() << "depth = 0";
      }
    }

GLObject* SpatialIndex::findNearest(GLObject* obj){
    return findNearest(obj, filterFuncDef);
    }

GLObject* SpatialIndex::findNearest( GLObject *object, filterFunc f){
    return Data::objects[0].findNearest(object, object->x(), object->y(), f );
    }

GLObject* SpatialIndex::Data::findNearest( GLObject *obj, float rx, float ry,
                                           filterFunc f){
    int x = (rx > w/2),
        y = (ry > h/2);
    GLObject *re  = 0;

    if( rx<=w && ry<=h && rx>=0 && ry>=0 ){
      GLObject *ob = 0;
      re = findValidate(0, object, obj, f);

      findNearestByCoord(ob,  0,  0, obj, rx, ry, f);
      re = nearestTo(re, ob, obj);

      findNearestByCoord(ob,  1,  0, obj, rx, ry, f);
      re = nearestTo(re, ob, obj);

      findNearestByCoord(ob,  0,  1, obj, rx, ry, f);
      re = nearestTo(re, ob, obj);

      findNearestByCoord(ob,  1,  1, obj, rx, ry, f);
      re = nearestTo(re, ob, obj);
      } else {

      findNearestByCoord(re,  x,  y, obj, rx, ry, f) ||
      findNearestByCoord(re, !x,  y, obj, rx, ry, f) ||
      findNearestByCoord(re,  x, !y, obj, rx, ry, f) ||
      findNearestByCoord(re, !x, !y, obj, rx, ry, f);
      }

    return findValidate( findValidate(0, object, obj, f) , re, obj, f);
    }

bool SpatialIndex::Data::findNearestByCoord( GLObject *&re, int x, int y,
                                             GLObject *obj,
                                             float rx, float ry,
                                             filterFunc f){
    if( data[x][y]>=0 ) {
      GLObject *tmp;
      tmp = objects[ data[x][y] ].findNearest(obj, rx-x*w/2, ry-y*h/2, f );
      if( tmp ){
        re = tmp;
        return 1;
        }
      }

    return 0;
    }

GLObject* SpatialIndex::Data::nearestTo( GLObject *obj1,
                                         GLObject *obj2 , GLObject* ideal){
    if( !obj1 ){
      return obj2;
      }

    float d = fabs(obj1->x() - ideal->x())+fabs(obj1->y() - ideal->y());

    if( !obj2 ||
        d < fabs(obj2->x() - ideal->x())+fabs(obj2->y() - ideal->y()) ){
      return obj1;
      } else {
      return obj2;
      }
    }

GLObject* SpatialIndex::Data::findValidate( GLObject*obj, GLObject* tst ,
                                            GLObject* ideal, filterFunc f){
    if( tst && f(tst, ideal) )
      return tst;

    return obj;
    }


SpatialIndex *SpatialIndex::instance(){
    return inst;
    }
