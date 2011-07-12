#ifndef MOVEALGO_H
#define MOVEALGO_H

#include <vector>
#include "map.h"

class MoveAlgo{
  public:
    MoveAlgo( Map &map );

    class Point{
      public:
        int x,y;
        Point(){
          x = 0;
          y = 0;
          }

        Point(int a, int b){
          x = a;
          y = b;
          }
        Point(float a, float b){
          x = Map::coordXf(a);
          y = Map::coordYf(b);
          }
      };

    typedef std::vector<Point> WayType;

    void way ( int   sx, int   sy,
               int   ex, int   ey,
               int sq = 0 );
    void wayf( float sx, float sy,
               float ex, float ey,
               int sq = 0 );

    void getWay (WayType &w, int   ex, int   ey);
    void getWayf(WayType &w, float ex, float ey);

    void releace(WayType &w);

    static void resetCash();
    static void tick();
    void correctInput(int &x, int &y);
  private:
    Map &map;

    static const int dx[8], dy[8], dsize;

    static std::vector<int> buf, moveCorrector;
    static int cash[2];
    static std::vector<Point> stk1, stk2, *curr, *tail;

    int &at(int x, int y);
    int &crVal(int x, int y);
    void rad( int x, int y,
              std::vector<Point> &out);

    bool nextPoint(int ex, int ey,
                   int &tgX, int &tgY);

  };

#endif // MOVEALGO_H
