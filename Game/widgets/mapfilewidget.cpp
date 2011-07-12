#include "mapfilewidget.h"

#include "startffawidget.h"
#include <QPainter>

#include <QStyle>
#include <QStyleOptionFrame>

MapFileWidget::MapFileWidget(QString file, StartFFAWidget *p) :
              QWidget(p){
    img.load( "./bmp/" +file );
    m_name = file;
    parent = p;

    setMinimumSize(128, 128+20);
    setMaximumSize(128, 128+20);
    }

MapFileWidget::~MapFileWidget(){

    }

void MapFileWidget::set( MapFileWidget* other ){
    img    = other->img;
    m_name = other->m_name;
    }

void MapFileWidget::paintEvent(QPaintEvent *){
    QPainter p(this);

    QStyleOptionFrame option;
    option.initFrom(this);

    style()->drawPrimitive( QStyle::PE_Frame, &option, &p, this);

    p.drawPixmap(10, 10, width()-20, height()-20-20, img);
    p.drawText(0, height()-24, width(), height(), Qt::AlignHCenter, name() );
    }

void MapFileWidget::mouseReleaseEvent(QMouseEvent *){
    parent->upsetInform( this );
    }

QString MapFileWidget::name() const{
    return m_name;
    }

const QPixmap& MapFileWidget::image() const{
    return img;
    }
