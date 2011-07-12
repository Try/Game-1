#ifndef UNITCTRL_H
#define UNITCTRL_H

#include <QWidget>
#include "icontroller.h"

#include "runtime/hotkeys.h"

namespace Ui {
    class UnitCtrl;
}

class UnitCtrl : public QWidget {
    Q_OBJECT

  public:
    explicit UnitCtrl(QWidget *parent = 0);
    ~UnitCtrl();

  class Controller:public IController{
    public:
      Controller();
      ~Controller();
      void rectEvent(QRectF);

      void mouseLClick(float x, float y);
      void mouseRClick(float x, float y);

      QWidget * createGUI( QLayout * lay );

    private:
      UnitCtrl *gui;
    };

    Ui::UnitCtrl *getUi();

  private slots:
    void setMove();
    void setAtack();
    void stopMove();
  private:
    Ui::UnitCtrl *ui;
    HotKeys::Key<UnitCtrl> atack;

    enum State{
      Normal,
      Move,
      Atack,
      Count
      } state;
  };

#endif // UNITCTRL_H
