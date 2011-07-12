#ifndef MAP_H
#define MAP_H

#include <vector>
#include "../clandobject.h"

#include <QPixmap>
#include <QImage>

class GLObject;

namespace MyGL{
  class IScene;
  }

class FileStream;

class Map{
  public:
    Map();
    ~Map();

    void resize(int x, int y);

    void initializeGL(MyGL::IScene &);
    void freeGPUData();

    void excludeQuad(int x, int y, bool e);

    class Quad{
      public:
        int enable;
        int group;
        unsigned resCount;

        float hMap;
        bool  exclude;
      private:
        int minSQ;

      friend class Map;
      };

    unsigned group(int x, int y);
    unsigned groupf(float x, float y);

    float height (int   x, int   y);
    float heightf(float x, float y);
    void setHeightf(float x, float y, float v);
    void setHeight(int x, int y, float v);

    void editEnable(int x, int y, bool e);
    void editResCount(int x, int y, int c);
    int  resCount(int x, int y);
    int  resCountf(float x, float y);

    bool exist(int x, int y);
    bool isEnable(int x, int y);

    bool existf(float x, float y);
    bool isEnablef(float x, float y);

    static int  coordX(float wX);
    static int  coordY(float wY);

    static float  coordXf(float wX);
    static float  coordYf(float wY);

    static float  coordWX(int wX);
    static float  coordWY(int wY);

    int width();
    int height();

    float widthf();
    float heightf();

    void refreshMiniMap();

    void calcGroups();

    bool findNearest(int &x, int &y);
    bool findNearest(int &x, int &y, int ux, int uy);
    bool findNearestf(float &x, float &y, float ux, float uy);

    void rebuildPaintData();
    void serialize( FileStream &f );

    void drawTail(int id, int x, int y, float size);
  private:
    std::vector<Quad> quads;

    CLandObject *land;
    int w,h;

    bool tdCalc;

    Quad& at(int x, int y);

    QImage  imgMinimap;

    void clearMap();
    void fillGroups(unsigned &gr);
    void fillGroups(int size, unsigned &gr);

    void checkNearest( int i, int r, int &rx, int &ry,
                       int &l, int &cx, int &cy,
                       int ux, int uy );
  };

#endif // MAP_H
