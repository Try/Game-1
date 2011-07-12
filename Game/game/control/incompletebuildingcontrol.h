#ifndef INCOMPLETEBUILDINGCONTROL_H
#define INCOMPLETEBUILDINGCONTROL_H

#include <QWidget>
#include "unitctrl.h"

#include "runtime/hotkeys.h"

namespace Ui {
    class IncompleteBuildingControl;
}


class GLObject;
class IncompleteBuildingBehavior;

#include <QTimer>

class IncompleteBuildingControl : public QWidget {
    Q_OBJECT

  public:
    explicit IncompleteBuildingControl( IncompleteBuildingBehavior *owner );
    ~IncompleteBuildingControl();

    class Controller:public IController{
      public:
        Controller( IncompleteBuildingBehavior *owner );
        ~Controller();

        void rectEvent(QRectF);

        void mouseLClick(float x, float y);
        void mouseRClick(float x, float y);

        void mouseMoveEvent(float x, float y, float z);

        QWidget * createGUI( QLayout * lay );

        void build(const std::string &s);
      private:
        IncompleteBuildingControl *gui;
        IncompleteBuildingBehavior *owner;

        void caselBuild();
      };
  private slots:
    void updateGui();
    void canselBuild();
  private:
    Ui::IncompleteBuildingControl *ui;
    QTimer timer;

    IncompleteBuildingBehavior *owner;

  };

#endif // INCOMPLETEBUILDINGCONTROL_H
