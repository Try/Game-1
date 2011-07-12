#ifndef MAPFILEWIDGET_H
#define MAPFILEWIDGET_H

#include <QWidget>
#include <QPixmap>

class StartFFAWidget;

class MapFileWidget : public QWidget{
    Q_OBJECT
  public:
    explicit MapFileWidget(QString file, StartFFAWidget *parent = 0);
    ~MapFileWidget();

    void set( MapFileWidget* other );
    QString name() const;
    const QPixmap& image() const;
  private:
    QPixmap img;

    virtual void paintEvent(QPaintEvent *);
    virtual void mouseReleaseEvent(QMouseEvent *);
    StartFFAWidget *parent;
    QString m_name;
  };

#endif // MAPFILEWIDGET_H
