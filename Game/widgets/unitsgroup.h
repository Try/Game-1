#ifndef UNITSGROUP_H
#define UNITSGROUP_H

#include <QWidget>
#include <QVector>

namespace Ui {
    class UnitsGroup;
}

class GLObject;
class QGridLayout;
class UnitButton;


#include "runtime/hotkeys.h"

class UnitsGroup : public QWidget{
    Q_OBJECT
  public:
    explicit UnitsGroup(QWidget *parent = 0);
    ~UnitsGroup();

    static void removeUnit( GLObject *obj );
    static void lock();

  public slots:
    static void rebuildData();

  private:
    Ui::UnitsGroup *ui;
    QGridLayout    *layOut;

    void addButton(UnitButton*);

    static UnitsGroup *inst;

    QVector<UnitButton*> buttons;

    HotKeys::Key<UnitsGroup> kControl;

    void updateAvatar();
  };

#endif // UNITSGROUP_H
