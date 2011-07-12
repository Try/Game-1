#ifndef UNITAVATAR_H
#define UNITAVATAR_H

#include <QWidget>

namespace Ui {
    class UnitAvatar;
}

class GLObject;
#include <QTimer>

class UnitAvatar : public QWidget {
    Q_OBJECT
  public:
    explicit UnitAvatar(QWidget *parent = 0);
    ~UnitAvatar();

    static UnitAvatar& instance();
    void   update( GLObject* s );

  public slots:
    void   updateT();
    void   setCamera();
    void unsetCamera();
  private:
    Ui::UnitAvatar *ui;

    static UnitAvatar* inst;
    QTimer timer;

    GLObject* object;
    bool cameraCtrl;
  };

#endif // UNITAVATAR_H
