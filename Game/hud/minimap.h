#ifndef MINIMAP_H
#define MINIMAP_H

#include <QWidget>

#include <QPixmap>
#include <QImage>

namespace Ui {
    class MiniMap;
}

class Game;
class Map;

class MiniMap : public QWidget {
    Q_OBJECT
  public:
    explicit MiniMap(QWidget *parent = 0);
    ~MiniMap();

    void paintEvent(QPaintEvent *);
    void updateMiniMap( Game& game );

    static MiniMap& instance();

  private:
    Ui::MiniMap *ui;
    static MiniMap *inst;

    QPixmap surface;
    QImage  imgMinimap, imgFog;

    void updateBackground( Map &m );
    void smallStep( Game& game );
    size_t step;

    bool mouse;
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
  };

#endif // MINIMAP_H
