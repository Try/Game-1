#ifndef CASTLECONTROL_H
#define CASTLECONTROL_H

#include <QWidget>
#include "icontroller.h"

namespace Ui {
    class CastleControl;
}

#include <QTimer>
#include <vector>

class BuildingBehavior;
class QToolButton;

class GLObject;

class CastleControl : public QWidget{
    Q_OBJECT

  public:
    explicit CastleControl( BuildingBehavior *owner );
    ~CastleControl();

    class Controller:public IController{
      public:
        Controller( BuildingBehavior * owner );
        ~Controller();
        void rectEvent(QRectF);

        void mouseLClick(float x, float y);
        void mouseRClick(float x, float y);

        QWidget * createGUI( QLayout * lay );

      private:
        CastleControl *gui;
        BuildingBehavior *owner;
      };

    void recrut( const std::string &str );

  private slots:
    void updateGUI();

  private:
    Ui::CastleControl *ui;
    BuildingBehavior *owner;

    QTimer timer;
    std::vector<QToolButton*> btn;

    class UnitBtn;

    UnitBtn* creteButton( QLayout * l );

    void removeFromQueue( UnitBtn* );
  };

#endif // CASTLECONTROL_H
