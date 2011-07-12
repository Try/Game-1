#ifndef UNITBUTTON_H
#define UNITBUTTON_H

#include <QToolButton>

class GLObject;

class UnitButton:public QToolButton{
  Q_OBJECT
  public:
    UnitButton( GLObject *obj );

    GLObject *object;
  public slots:
    void mouseClick();
  };

#endif // UNITBUTTON_H
