#ifndef WORKERCONTROLLER_H
#define WORKERCONTROLLER_H

#include <QWidget>
#include "unitctrl.h"

#include "runtime/hotkeys.h"

namespace Ui {
    class WorkerController;
}

class GLObject;
class WorkerBehavior;

class WorkerController : public QWidget {
    Q_OBJECT
  public:
    explicit WorkerController(QWidget *parent = 0);
    ~WorkerController();

    class Controller:public IController{
      public:
        Controller( GLObject *owner, WorkerBehavior *worker );
        ~Controller();

        void rectEvent(QRectF);

        void mouseLClick(float x, float y);
        void mouseRClick(float x, float y);

        void mouseMoveEvent(float x, float y, float z);

        QWidget * createGUI( QLayout * lay );

        void build(const std::string &s);
      private:
        UnitCtrl *gui;

        UnitCtrl::Controller uCtrl;

        GLObject *owner;
        WorkerBehavior *worker;
        WorkerController *wrkGui;

        GLObject *buildable;

        void caselBuild();
      };

  private slots:
    void showBuildPage();

  private:
    Ui::WorkerController *ui;
    HotKeys::Key<WorkerController> hKey;

  };

#endif // WORKERCONTROLLER_H
