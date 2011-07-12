#include "movealgo.h"

#include "map.h"
#include <cstring>
#include <iostream>

#include <QDebug>
#include "game/game.h"

std::vector<int> MoveAlgo::buf,
                 MoveAlgo::moveCorrector;

const int MoveAlgo::dx[8] = {-1, 1, 0, 0, 0, 0, 0, 0},
          MoveAlgo::dy[8] = { 0, 0,-1, 1, 0, 0, 0, 0},
          MoveAlgo::dsize = 4;

int MoveAlgo::cash[2] = {-1, -1};

std::vector<MoveAlgo::Point>
  MoveAlgo::stk1,
  MoveAlgo::stk2,
  *MoveAlgo::curr,
  *MoveAlgo::tail;

MoveAlgo::MoveAlgo( Map &m):map(m){
    buf.resize( m.width()*m.height() );
    moveCorrector.resize( buf.size() );
    }

void MoveAlgo::tick(){
    for(size_t i=0; i<moveCorrector.size(); ++i)
      moveCorrector[i] = std::max(moveCorrector[i]/2, 0);
    }

int &MoveAlgo::at(int x, int y){
    return buf[x + y*map.width() ];
    }

int &MoveAlgo::crVal(int x, int y){
    return moveCorrector[x + y*map.width() ];
    }

void MoveAlgo::correctInput(int &x, int &y){
    map.findNearest(x, y);
    }

void MoveAlgo::rad( int x, int y,
                    std::vector<Point> &out){
    for(int i=0; i<dsize; ++i){
      int rx = x + dx[i];
      int ry = y + dy[i] ;

      if( map.exist(rx, ry) ){
        if( map.isEnable( rx, ry ) &&
            ( at(rx, ry) > at(x,y)+crVal(rx, ry)/3+1 ||
              at(rx, ry)==0 ) ){
          out.push_back( Point( rx, ry ) );
          at(rx, ry) = at(x,y)+crVal(rx, ry)/3+1;
          }
        }

      }
    }

void MoveAlgo::wayf( float sx, float sy,
                     float ex, float ey, int sq ){
    way( Map::coordX(sx), Map::coordY(sy),
         Map::coordX(ex), Map::coordY(ey), sq );
    }

void MoveAlgo::way( int sx, int sy,
                    int ex, int ey, int sq ){
    if( !map.exist(sx, sy) ||
        !map.isEnable(sx, sy) ){
      correctInput(sx, sy);
      //return;
      }

    qDebug() << "way";

    if( cash[0]==sx && cash[1]==sy ){
      if( at(ex, ey) ){
        //qDebug() << "cash 2";
        return;
        }
      //qDebug() << "cash 1";
      } else {
      //qDebug() << "cash 0";
      cash[0] = sx;
      cash[1] = sy;

      memset( buf.data(), 0x0, sizeof(int)*buf.size() );

      stk1.clear();
      // stk2.clear();

      curr = &stk1;
      tail = &stk2;

      for(int i=-sq; i<=sq; ++i)
        for(int r=-sq; r<=sq; ++r)
          if( map.exist(sx+i, sy+r) &&
              map.isEnable(sx+i, sy+r) ){
            at(sx+i, sy+r) = 1;
            stk1.push_back( Point(sx+i, sy+r) );
            }
      }

    while( curr->size() &&
           (at(ex, ey)==0) ){
      tail->clear();
      for(unsigned i=0; i<curr->size(); ++i){
        rad( (*curr)[i].x, (*curr)[i].y, *tail );
        }

      std::swap( curr, tail );
      }

    if( at(ex, ey)==0 ){
      qDebug() << "way not found!";
      }
/*
    std::cout << std::endl;
    for(int i=0; i<map.width(); ++i){
      for(int r=0; r<map.height(); ++r){
        if( at(i,r) )
          std::cout << std::min(9, at(i,r) ); else
          std::cout << 'x';
        }
      std::cout << std::endl;
      }
    std::cout << std::endl;*/
    }

void MoveAlgo::getWayf(WayType &w, float ex, float ey){
    getWay (w, Map::coordX(ex), Map::coordY(ey) );

    if( w.size() ){/*
      w.pop_back();
      w.back().x = Map::coordXf(ex);
      w.back().y = Map::coordYf(ey);*/
      }
    }

bool MoveAlgo::nextPoint( int ex,   int ey,
                          int &tgX, int &tgY){
    bool ok = 0;

    for(int i=0; i<dsize; ++i){
      int rx = ex + dx[i];
      int ry = ey + dy[i];

      if( map.exist(rx, ry) &&
          map.isEnable( rx, ry ) &&
            at(rx, ry) < at(ex,ey) &&
            at(rx, ry)!=0 ){
        if( !ok ){
          ok = 1;
          tgX = rx;
          tgY = ry;
          }
        }
      }

    return ok;
    }

void MoveAlgo::getWay(WayType &w, int ex, int ey){
    w.clear();

    int sx = ex,
        sy = ey;

    if( !map.exist(ex, ey) )
      return;

    if( !map.isEnable(ex, ey) ){
      return;//correctInput(ex, ey);
      }

    // w.push_back( Point(ex,ey) );
    qDebug() << at(ex, ey);
    while( at(ex, ey)>1 ){
      int tgX = ex, tgY = ey;
      bool ok = nextPoint(ex, ey, tgX, tgY);

      if( ok ){
        w.push_back( Point( tgX, tgY ) );
        ex = tgX;
        ey = tgY;
        } else {
        w.clear();
        qDebug() << "no way!!!";
        return;
        }

      }

    for(size_t i=w.size()/2; i<w.size(); ++i){
      std::swap( w[i], w[w.size()-1-i] );
      }
    w.push_back( Point( sx, sy ) );

    for(size_t i=0; i<w.size(); ++i){
      crVal( w[i].x, w[i].y ) = crVal( w[i].x, w[i].y ) + 3 -
                                std::min(3, crVal( w[i].x, w[i].y )/2 );
      }

    if( w.size() >=3 ){
      int nsize = 1;
      for(size_t i=1; i<w.size()-1; ++i){
        if( (map.group( w[i-1].x, w[i-1].y)!=
             map.group( w[i].x, w[i].y)) ||

            (map.group( w[i+1].x, w[i+1].y)!=
                       map.group( w[i].x, w[i].y))){
          w[nsize] = w[i];
          ++nsize;
          }
        }
      w[nsize] = w.back();
      if( map.group( w[nsize-1].x, w[nsize-1].y)!=
          map.group( w[nsize  ].x, w[nsize  ].y) ){
        nsize++;
        }

      w.resize( nsize );
      }

    qDebug() << "way.size = " << w.size();
    }

void MoveAlgo::releace(WayType &w){
    for(size_t i=0; i<w.size(); ++i){
      if( map.exist(w[i].x, w[i].y) )
        crVal( w[i].x, w[i].y ) = std::max(crVal( w[i].x, w[i].y )-1, 0);
      }

    w.clear();
    }


void MoveAlgo::resetCash(){
    cash[0] = -1;
    cash[1] = -1;
    }
