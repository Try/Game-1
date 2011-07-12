#include "map.h"

#include "game.h"

#include "movealgo.h"
#include "hud/minimap.h"
#include "dataCtrl/filestream.h"

#include <QDebug>

Map::Map(){
    tdCalc = 0;

    w = 0;
    h = 0;
    }

Map::~Map(){

    }

void Map::freeGPUData(){
    delete land;
    }

void Map::resize(int x, int y){
    w = x*2;
    h = y*2;

    quads.resize(x*y*4);// x4

    clearMap();

    land->resize(x, y);
    calcGroups();
    }

void Map::clearMap(){
    for(unsigned i=0; i<quads.size(); ++i){
      quads[i].enable    = 0;
      quads[i].group     = 0;
      quads[i].resCount  = 0;
      quads[i].hMap      = 0;
      quads[i].exclude   = 1;
      }

    }


int Map::width(){
    return w;
    }

int Map::height(){
    return h;
    }

float Map::widthf(){
    return coordWX(width());
    }

float Map::heightf(){
    return coordWY(height());
    }

void Map::initializeGL(MyGL::IScene &scene){
    land = new CLandObject( scene, "land" );
    }

Map::Quad& Map::at(int x, int y){
    return quads[x+y*w];
    }

bool Map::exist(int x, int y){
    return (0<=x && x<w && 0<=y && y<h);
    }

bool Map::existf(float x, float y){
    return exist( coordX(x), coordY(y) );
    }

bool Map::isEnablef(float x, float y){
    return isEnable( coordX(x), coordY(y) );
    }

void Map::editEnable(int x, int y, bool e){
    static const int ex[] = {-1, 1};
    at(x,y).enable += ex[e];

    tdCalc = 1;
    }

void Map::excludeQuad(int x, int y, bool e){
    if( at(x,y).exclude == e )
      return;

    at(x,y).exclude = e;
    editEnable(x,y, !e);
    }

void Map::editResCount(int x, int y, int c){
    if( exist(x, y) )
      at(x,y).resCount += c;
    }

int Map::resCountf(float x, float y){
    return resCount( coordX(x), coordY(y) );
    }

int  Map::resCount(int x, int y){
    if( exist(x, y) )
      return at(x,y).resCount; else
      return 0;
    }

bool Map::isEnable(int x, int y){
    if( exist(x,y) )
      return (at(x,y).enable==0); else
      return 0;
    }

int Map::coordX(float wx){
    return int(wx*2);
    }

int Map::coordY(float wy){
    return int(wy*2);
    }

float Map::coordXf(float wx){
    return (wx*2.0);
    }

float Map::coordYf(float wy){
    return (wy*2.0);
    }

float Map::coordWX(int wX){
    return wX*0.5;
    }

float Map::coordWY(int wY){
    return wY*0.5;
    }

void Map::refreshMiniMap(){
    MiniMap::instance().updateMiniMap( Game::instance() );
    }

void Map::calcGroups(){
    MoveAlgo::resetCash();

    for(int i=0; i<width(); ++i)
      at(i, 0).minSQ = 0;

    for(int i=0; i<height(); ++i)
      at(0, i).minSQ = 0;

    for(int i=0; i<width(); ++i)
      for(int r=0; r<height(); ++r)
        at(i,r).group = 0;

    for(int i=1; i<width(); ++i)
      for(int r=1; r<height(); ++r){
        if( isEnable(i,r) ){
          at(i,r).minSQ = std::min( at(i-1,r).minSQ, at(i  ,r-1).minSQ );
          at(i,r).minSQ = std::min( at(i  ,r).minSQ, at(i-1,r-1).minSQ );
          ++at(i,r).minSQ;
          } else {
          at(i,r).minSQ = 0;
          }
        }

    unsigned gr = 0;
    int maxSize = 0;
    for(int i=width()-1; i>=0; --i)
      for(int r=height()-1; r>=0; --r){
        if( maxSize< at(i,r).minSQ)
          maxSize = at(i,r).minSQ;
        }

    fillGroups(gr);
    }

void Map::fillGroups(unsigned &gr){
  for(int i=width()-1; i>=0; --i)
    for(int r=height()-1; r>=0; --r){
      int size = at(i,r).minSQ;

      if(size){
        gr++;

        for(int x = 0; x<size; ++x)
          for(int y = 0; y<size; ++y){
            if( exist(i-x, r-y) ){
              at(i-x,r-y).minSQ = 0;
              at(i-x,r-y).group = gr;
              }
            }
        }
      }
    }

void Map::fillGroups(int s, unsigned &gr){
    for(int i=width()-1; i>=0; --i)
      for(int r=height()-1; r>=0; --r){
        int size = at(i,r).minSQ;

        if(size==s){
          gr++;

          for(int x = 0; x<size; ++x)
            for(int y = 0; y<size; ++y){
              if( exist(i-x, r-y) ){
                at(i-x,r-y).minSQ = 0;
                at(i-x,r-y).group = gr;
                }
              }
          }
        }
    }

unsigned Map::group(int x, int y){
    if( tdCalc ){
      calcGroups();
      tdCalc = 0;
      }

    if( exist(x,y) )
      return at(x,y).group; else
      return 0;
    }

void Map::setHeight(int x, int y, float v){
    at( x, y ).hMap = v;
    }

void Map::setHeightf(float x, float y, float v){
    at( coordX(x), coordY(y) ).hMap = v;
    }

float Map::heightf(float x, float y){
    return height(coordX(x), coordY(y));
    }

float Map::height (int   x, int   y){
    x = std::max(0, std::min(x, w-1) );
    y = std::max(0, std::min(y, h-1) );
    if( exist(x, y) )
      return at(x,y).hMap; else
      return 0;
    }

unsigned Map::groupf(float x, float y){
    return group( coordX(x), coordY(y) );
    }

bool Map::findNearest(int &cx, int &cy){
    return findNearest(cx, cy, cx, cy);
    }

void Map::checkNearest(int i, int r, int &rx, int &ry, int &l,
                       int &cx, int &cy,
                       int ux, int uy){
    if( exist( cx+i, cy+r ) &&
        isEnable( cx+i, cy+r ) ){
      int len = abs(cx+i-ux) + abs(cy+r-uy);

      if( l<0 || len<l){
        rx = cx+i;
        ry = cy+r;
        l  = len;
        }

      }
    }

bool Map::findNearest(int &cx, int &cy, int ux, int uy){
    int maxSize = std::max( Game::instance().map.width(),
                            Game::instance().map.height() );

    int l = -1, rx = 0, ry = 0;

    for(int size = 0; size<maxSize; ++size){
      for(int i=-size; i<=size; i++){
        checkNearest( i, -size, rx, ry, l, cx, cy, ux, uy );
        checkNearest( i,  size, rx, ry, l, cx, cy, ux, uy );
        }
      for(int r=-size; r<=size; r++){
        checkNearest( -size, r, rx, ry, l, cx, cy, ux, uy );
        checkNearest(  size, r, rx, ry, l, cx, cy, ux, uy );
        }
      if( l>=0 ){
        cx = rx;
        cy = ry;
        return 1;
        }
      }
    return 0;
    }

bool Map::findNearestf(float &x, float &y, float ux, float uy){
    int cx = coordX(x),
        cy = coordY(y);

    bool ok = findNearest(cx, cy, coordX(ux), coordY(uy) );

    x = coordWX(cx);
    y = coordWY(cy);
    return ok;
    }

void Map::drawTail(int id, int x, int y, float size){
    land->drawTail(id, x, y, size);
    }

void Map::rebuildPaintData(){
    land->build();
    }

void Map::serialize( FileStream &f ){
    //f + w + h;

    //if( f.isOut() ){
      for(int i=0; i<width(); ++i)
        for(int r=0; r<height(); ++r){
          f + at(i,r).hMap + at(i,r).enable + at(i,r).exclude;

          if( at(i,r).exclude )
            excludeQuad(i,r, 1);
          }
      rebuildPaintData();
    //  }
    }
