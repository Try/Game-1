#include "showwidget.h"

#include <QPainter>
#include <QStyleOptionFrame>

using namespace std;

ShowWidget::ShowWidget(){

    }

ShowWidget::~ShowWidget(){

    }

void ShowWidget::setImage( const QString &i ){
    img.load(i);
    }

void ShowWidget::setImage( const QImage &i ){
    img = QPixmap::fromImage(i);
    }

void ShowWidget::paintEvent(QPaintEvent *){
    QPainter p(this);
    // p.setRenderHint( QPainter::Antialiasing, true);

    float w  = width()-20, h = height()-20;

    float k = min( img.width() /w,
                   img.height()/h );
    k = 1;

    int nW = img.width()/k,
        nH = img.height()/k;

    int dX = (width() - nW)/2,
        dY = (height() - nH)/2;

    QStyleOptionFrame option;
    option.initFrom(this);

    p.drawPixmap( dX, dY, nW, nH, img);

    style()->drawPrimitive( QStyle::PE_Frame, &option, &p, this);
    }
