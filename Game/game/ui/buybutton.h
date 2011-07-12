#ifndef BUYBUTTON_H
#define BUYBUTTON_H

#include <QToolButton>

class CastleControl;

#include "game/control/workercontroller.h"
#include "runtime/hotkeys.h"

#include <QShortcut>

class BuyButton : public QToolButton{
  Q_OBJECT
  public:
    BuyButton(CastleControl *ctrl,
              const std::string & str);
    BuyButton(WorkerController::Controller *ctrl,
              const std::string & str );
    ~BuyButton();

    void setHotKey( const std::string& k );
  private slots:
    void pressEvent();
    void buildSome();

  private:
    void init();
    CastleControl *owner;
    WorkerController::Controller *wowner;

    const std::string & name;

    HotKeys::Key<BuyButton> hKey;

    bool event(QEvent *e);

  };

#endif // BUYBUTTON_H
