#ifndef NORWEGIANWOODSTYLE_H
#define NORWEGIANWOODSTYLE_H

#include <QMotifStyle>
#include <QPalette>

QT_BEGIN_NAMESPACE
class QPainterPath;
class QPushButton;
QT_END_NAMESPACE

class NorwegianWoodStyle : public QMotifStyle
{
    Q_OBJECT

public:
    NorwegianWoodStyle();

    void polish(QPalette &palette);
    void polish(QWidget *widget);
    void unpolish(QWidget *widget);
    int pixelMetric(PixelMetric metric, const QStyleOption *option,
                    const QWidget *widget) const;
    int styleHint(StyleHint hint, const QStyleOption *option,
                  const QWidget *widget, QStyleHintReturn *returnData) const;
    void drawPrimitive(PrimitiveElement element, const QStyleOption *option,
                       QPainter *painter, const QWidget *widget) const;
    void drawControl(ControlElement control, const QStyleOption *option,
                     QPainter *painter, const QWidget *widget) const;

private:
    static void setTexture(QPalette &palette, QPalette::ColorRole role,
                           const QPixmap &pixmap);
    static void setBrush(QPalette &palette, QPalette::ColorRole role,
                           const QBrush &pixmap);

    void drawButton( PrimitiveElement element, const QStyleOption *option,
                     QPainter *painter, const QWidget *widget) const;
    void drawFrame( PrimitiveElement element, const QStyleOption *option,
                    QPainter *painter, const QWidget *widget,
                    const QPixmap &border ) const;

    void drawTab(  const QStyleOption *option,
                     QPainter *painter, const QWidget *widget) const;

    void drawRect( QPainter* p, QRect r, const QPixmap &pix) const;
    void drawCBox( ControlElement element, const QStyleOption *option,
                     QPainter *painter, const QWidget *widget) const;

    QPixmap buttonBase, buttonBack[2],
            frmBase, frameBack, ckBoxCheck, paperBack;

    void drawMWidget(const QStyleOption *option,
                     QPainter *painter, const QWidget *widget) const;
};

#endif
