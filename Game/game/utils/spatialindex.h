#ifndef SPATIALINDEX_H
#define SPATIALINDEX_H

class GLObject;

class SpatialIndex {
  public:
    SpatialIndex();
    ~SpatialIndex();

    void clear(int w, int h);
    void add( GLObject* );

    typedef bool (*filterFunc)(GLObject* tst, GLObject *caller);

    GLObject* findNearest(GLObject*, filterFunc);
    GLObject* findNearest(GLObject*);
    static SpatialIndex *instance();
  private:
    class Data;

    static SpatialIndex *inst;
    static bool filterFuncDef (GLObject* a, GLObject *b){
      return a!=b;
      }
  };

#endif // SPATIALINDEX_H
