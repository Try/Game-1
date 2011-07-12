#ifndef FALAGOWNERBAHAVIOR_H
#define FALAGOWNERBAHAVIOR_H

#include "abstractbehavior.h"

class FalagOwnerBahavior: public AbstractBehavior{
  public:
    FalagOwnerBahavior( GLObject *m_owner );
    ~FalagOwnerBahavior();


    void selectEvent( bool s );
    GLObject *owner() const;

    void command( GLObject * obj );
    void deleteUnitEvent(const GLObject *);

    void serialize(FileStream &f);
  protected:
    GLObject *point_flag;
    virtual void upsetPointFlagPos(){}

    struct MvInfo{
      float tgPos[2];
      bool  fakeMove;
      GLObject *taget;
      } move;

    void serialize_flag(FileStream &f);
  private:
    GLObject *m_owner;
  };

#endif // FALAGOWNERBAHAVIOR_H
