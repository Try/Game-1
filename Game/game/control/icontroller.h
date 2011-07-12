#ifndef ICONTROLLER_H
#define ICONTROLLER_H

#include <QRectF>

class QWidget;
class QLayout;

class IController{
  public:
    virtual ~IController(){}

    virtual void rectEvent(QRectF) = 0;

    virtual void mouseLClick(float x, float y) = 0;
    virtual void mouseRClick(float x, float y) = 0;

    virtual void mouseMoveEvent(float /*x*/, float /*y*/, float /*z*/){}

    virtual QWidget * createGUI( QLayout * lay ) = 0;
  };

#endif // ICONTROLLER_H
