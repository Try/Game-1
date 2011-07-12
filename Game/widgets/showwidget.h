#ifndef SHOWWIDGET_H
#define SHOWWIDGET_H

#include <QWidget>
#include <QImage>
#include <QPixmap>

class ShowWidget : public QWidget{
    Q_OBJECT
  public:
    ShowWidget();
    virtual ~ShowWidget();

    void setImage( const QImage &i );
    void setImage( const QString &i );
  private:
    virtual void paintEvent(QPaintEvent *);

    QPixmap img;
  };

#endif // SHOWWIDGET_H
