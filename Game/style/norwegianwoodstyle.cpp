//#include <QtGui>

#include <QComboBox>
#include <QGroupBox>
#include <QPainter>
#include <QPushButton>
#include <QToolButton>
#include <QDebug>
#include <QMainWindow>

#include <QStyleOptionTab>

#include "norwegianwoodstyle.h"

#include "widgets/showwidget.h"

NorwegianWoodStyle::NorwegianWoodStyle(){
  buttonBase.load("./style/base.png");

  buttonBack[0].load("./style/buttonBack.png");
  buttonBack[1].load("./style/buttonBackD.png");

  frmBase.  load("./style/baseFrame.png");
  frameBack.load("./style/frameBack.png");

  ckBoxCheck.load("./style/ckBox.png");

  paperBack.load("./style/paper.jpg");
  }

void NorwegianWoodStyle::polish(QPalette &palette)
{
    //QColor brown(212, 140, 95);
    //QColor beige(236, 182, 120);

    QColor base( 140, 140, 140);
    QColor dark( 10, 10, 10);

    //QPixmap backgroundImage("./style/backTexture.png");
    //QPixmap buttonImage    ("./style/texture2.png");
    //QPixmap midImage = buttonImage;
/*
    QPainter painter;
    painter.begin(&midImage);
    painter.setPen(Qt::NoPen);
    //painter.fillRect(midImage.rect(), slightlyOpaqueBlack);
    painter.end();*/

    QBrush nullBrush;
    nullBrush.setStyle( Qt::NoBrush );

    palette = QPalette(base, dark);

    palette.setBrush(QPalette::BrightText, nullBrush);
    palette.setBrush(QPalette::Base, nullBrush);
    palette.setBrush(QPalette::Highlight, Qt::darkGreen);

    setBrush(palette, QPalette::Button, nullBrush);
    setBrush(palette, QPalette::Mid,    nullBrush);
    setBrush(palette, QPalette::Window, nullBrush);

    //palette.setBrush( QPalette::);

    palette.setBrush(QPalette::Disabled, QPalette::WindowText, nullBrush);
    palette.setBrush(QPalette::Disabled, QPalette::Text, nullBrush);
    palette.setBrush(QPalette::Disabled, QPalette::ButtonText, nullBrush);
    palette.setBrush(QPalette::Disabled, QPalette::Base,   nullBrush);
    palette.setBrush(QPalette::Disabled, QPalette::Button, nullBrush);
    palette.setBrush(QPalette::Disabled, QPalette::Mid,    nullBrush);

    palette.setColor( QPalette::WindowText, Qt::white );
    palette.setColor( QPalette::Text,       Qt::white );
    palette.setColor( QPalette::ButtonText, Qt::white );
    palette.setColor( QPalette::Highlight,  Qt::blue  );
}

void NorwegianWoodStyle::polish(QWidget *widget){
    if (qobject_cast<QPushButton *>(widget) ||
        qobject_cast<QToolButton *>(widget) ||
        qobject_cast<QComboBox *>(widget))
        widget->setAttribute(Qt::WA_Hover, true);

    if (qobject_cast<QGroupBox *>(widget) ){
      QGroupBox *b = qobject_cast<QGroupBox *>(widget);
      b->setTitle("");
      }
    }

void NorwegianWoodStyle::unpolish(QWidget *widget)
//! [5] //! [6]
{
    if (qobject_cast<QPushButton *>(widget)
            || qobject_cast<QComboBox *>(widget))
        widget->setAttribute(Qt::WA_Hover, false);
}
//! [6]

//! [7]
int NorwegianWoodStyle::pixelMetric(PixelMetric metric,
//! [7] //! [8]
                                    const QStyleOption *option,
                                    const QWidget *widget) const
{
    switch (metric) {
    case PM_ComboBoxFrameWidth:
        return 8;
    case PM_ScrollBarExtent:
        return QMotifStyle::pixelMetric(metric, option, widget) + 4;
    default:
        return QMotifStyle::pixelMetric(metric, option, widget);
    }
}
//! [8]

//! [9]
int NorwegianWoodStyle::styleHint(StyleHint hint,
                                  const QStyleOption *option,
                                  const QWidget *widget,
                                  QStyleHintReturn *returnData) const {
    switch (hint) {
    case SH_DitherDisabledText:
        return int(false);

    case SH_EtchDisabledText:
        return int(true);

//    case SH_GroupBox_TextLabelVerticalAlignment:
//      return 1000;
//    case SH_GroupBox_TextLabelColor:
//      return QColor(100, 200, 255, 0).rgba();

    default:
        return QMotifStyle::styleHint(hint, option, widget, returnData);
        //return 0;
    }
}

void NorwegianWoodStyle::drawPrimitive(PrimitiveElement element,
                                       const QStyleOption *option,
                                       QPainter *painter,
                                       const QWidget *widget) const {
    // qDebug() << "drawPrimitive";

    switch (element) {
      case PE_PanelButtonCommand:
        drawButton(element, option, painter, widget );
        break;

      //case PE_FrameTabBarBase:
      case PE_PanelButtonTool:
      case PE_Frame:
        drawFrame(element, option, painter, widget, buttonBase );
        break;

      case PE_FrameGroupBox:
        drawFrame(element, option, painter, widget, frmBase );
        break;

      case PE_FrameTabBarBase:
        drawFrame(element, option, painter, widget, buttonBase );
        break;

      case PE_FrameTabWidget:
        drawFrame(element, option, painter, widget, frmBase );
        break;

      case PE_FrameLineEdit:
      case PE_Widget:
        drawMWidget( option, painter, widget);
      case PE_IndicatorToolBarHandle:
        break;



    //case QStyle::PE_PanelButtonBevel:
      //break;

    default:
        QMotifStyle::drawPrimitive(element, option, painter, widget);
    }
}

void NorwegianWoodStyle::drawControl(ControlElement element,
                                     const QStyleOption *option,
                                     QPainter *painter,
                                     const QWidget *widget) const {
  switch (element) {
    //case CE_PushButtonLabel:

    case CE_FocusFrame:
      drawPrimitive(PE_PanelButtonCommand, option, painter, widget);
      break;

    case CE_ShapedFrame:
      drawPrimitive(PE_PanelButtonCommand, option, painter, widget);
      break;

    case CE_TabBarTab:
      drawTab( option, painter, widget);
      break;

    case CE_TabBarTabLabel:
      QMotifStyle::drawControl(element, option, painter, widget);
      break;
/*
    case CE_TabBarTabShape:
      drawPrimitive(PE_PanelButtonCommand, option, painter, widget);
      break;*/

    case CE_CheckBox:
    case CE_CheckBoxLabel:
      drawCBox( element, option, painter, widget);
      break;

    case CE_HeaderLabel:
      break;

    case CE_PushButton:
    //case CE_
      drawPrimitive(PE_PanelButtonCommand, option, painter, widget);

      break;

    case CE_PushButtonBevel:
      break;

    default:
        QMotifStyle::drawControl(element, option, painter, widget);
    }
}

void NorwegianWoodStyle::setTexture(QPalette &palette, QPalette::ColorRole role,
                                    const QPixmap &pixmap) {
    for (int i = 0; i < QPalette::NColorGroups; ++i) {
        QColor color = palette.brush(QPalette::ColorGroup(i), role).color();
        palette.setBrush(QPalette::ColorGroup(i), role, QBrush(color, pixmap));
    }
  }

void NorwegianWoodStyle::setBrush(QPalette &palette, QPalette::ColorRole role,
                                    const QBrush &b) {
    for (int i = 0; i < QPalette::NColorGroups; ++i) {
        QColor color = palette.brush(QPalette::ColorGroup(i), role).color();
        palette.setBrush(QPalette::ColorGroup(i), role, b);
    }
  }

void NorwegianWoodStyle::
     drawButton( PrimitiveElement , const QStyleOption *option,
                 QPainter *painter, const QWidget *widget) const{
  const QStyleOptionButton *buttonOption =
          qstyleoption_cast<const QStyleOptionButton *>(option);
  if( !buttonOption )
    return;

  painter->save();

  QRect btnRect = option->rect;
  if( !(buttonOption->features & QStyleOptionButton::Flat &&
      !(buttonOption->state    & (State_Sunken | State_On)) ) ){
    if( buttonOption->state & (State_Sunken | State_On) ){
      int d = 2;
      btnRect = QRect( btnRect.x()+d,
                       btnRect.y()+d,
                       btnRect.width()-2*d,
                       btnRect.height()-2*d );
      }

    QBrush b;
    if( buttonOption->state & (State_Enabled) ){
      b.setTexture( buttonBack[0] );
      } else {
      b.setTexture( buttonBack[1] );
      }

    if( !(buttonOption->state & State_Sunken) )
      painter->fillRect( btnRect, b);

    drawRect(painter, btnRect, buttonBase);
    }

  drawControl( CE_PushButtonLabel, option, painter, widget );
  painter->restore();
  }

void NorwegianWoodStyle::
     drawFrame( PrimitiveElement , const QStyleOption *option,
                 QPainter *painter, const QWidget *w,
                 const QPixmap &border) const{
  painter->save();

  QRect btnRect = option->rect;

    QBrush b;
    if( btnRect.width()*btnRect.height() < 100000  ){
      b.setTexture( frameBack );
      } else {
      b.setTexture( paperBack );
      }

    if( !dynamic_cast<const ShowWidget*>(w) )
      painter->fillRect( btnRect, b);

    drawRect(painter, btnRect, border);

  if( !( option->state & (State_Enabled))  ){
   // painter->setPen( QPen(QColor(150, 150, 150)) );
    }

  painter->restore();
  }

void NorwegianWoodStyle::drawMWidget(const QStyleOption *,
                                     QPainter *, const QWidget *)
                                    const{/*
    if( qobject_cast<const QMainWindow*>(widget) ){
      painter->save();
      QBrush b( QColor(0, 0, 0) );

      painter->setBrush(b);
      painter->drawRect( option->rect );

      painter->restore();
      }*/
    }

void NorwegianWoodStyle::
        drawTab(  const QStyleOption *option,
                 QPainter *painter, const QWidget *widget) const{
    if( qstyleoption_cast<const QStyleOptionTab *>(option) ){/*
      QRect r = option->rect;
      QStyleOptionTab opt = *(QStyleOptionTab*)option;

      if( opt.selectedPosition==QStyleOptionTab::NextIsSelected )
        r.setHeight( r.height()-3 );

      opt.rect = r;*/
      drawPrimitive(PE_Frame, option, painter, widget);
      }

    drawControl( CE_TabBarTabLabel, option, painter, widget );
    }


void NorwegianWoodStyle::
     drawCBox( ControlElement element, const QStyleOption *option,
                 QPainter *painter, const QWidget *widget) const{
  const QStyleOptionButton *buttonOption =
          qstyleoption_cast<const QStyleOptionButton *>(option);
  if( !buttonOption )
    return;

  painter->save();

  QRect btnRect = option->rect;
  int s = std::min( btnRect.width(), btnRect.height() );
  s = std::min(s, 20);

  btnRect.setY( (widget->height()-s)/2 );
  btnRect.setSize( QSize(s,s) );

  bool pressed = 0;
  if( !(buttonOption->features & QStyleOptionButton::Flat &&
      !(buttonOption->state    & (State_Sunken | State_On)) ) ){
    if( buttonOption->state & (State_Sunken | State_On) ){
      pressed = 1;/*
      int d = 2;
      btnRect = QRect( btnRect.x()+d,
                       btnRect.y()+d,
                       btnRect.width()-2*d,
                       btnRect.height()-2*d );*/
      }

    QBrush b;
    if( buttonOption->state & (State_Enabled) ){
      b.setTexture( buttonBack[0] );
      } else {
      b.setTexture( buttonBack[1] );
      }

    if( !(buttonOption->state & State_Sunken) )
      painter->fillRect( btnRect, b);

    drawRect(painter, btnRect, buttonBase);
    if( pressed )
      painter->drawPixmap(btnRect, ckBoxCheck);
    }

  if( element==CE_CheckBoxLabel ){
    QRect r = option->rect;
    r.setX( r.x()+20 );
    r.setWidth( r.width()-20 );
    QStyleOptionButton opt = *(QStyleOptionButton*)option;
    opt.rect = r;

    QMotifStyle::drawControl(element, &opt, painter, widget);
    } else {
    drawControl( CE_CheckBoxLabel, option, painter, widget );
    }

  painter->restore();
  }

void NorwegianWoodStyle::drawRect( QPainter* painter,
                                   QRect rect,
                                   const QPixmap &buttonBase) const{
    int bw = buttonBase.width()/3,
        bh = buttonBase.height()/3;

    int ww = std::min(bw, rect.width ()/2),
        wh = std::min(bh, rect.height()/2);

    int bw2 = buttonBase.width()-bw*2,
        bh2 = buttonBase.height()-bh*2;

    int ww2 = std::min(bw2, rect.width ()/2),
        wh2 = std::min(bh2, rect.height()/2);

    ww = std::min(ww, wh);
    ww2 = std::min(ww2, wh2);

    painter->drawPixmap( rect.x(),
                         rect.y(),
                         ww, wh,
                         buttonBase, 0, 0, bw, bh );

    painter->drawPixmap( rect.x()+ww,
                         rect.y(),
                         rect.width()-ww-ww2,
                         wh,
                         buttonBase, bw, 0, bw, bh );

    painter->drawPixmap( rect.x()+rect.width()-ww2,
                         rect.y(),
                         ww2, wh,
                         buttonBase, bw*2, 0, bw2, bh );


    painter->drawPixmap( rect.x(),
                         rect.y()+rect.height()-wh2,
                         ww, wh2,
                         buttonBase, 0, bh*2, bw, bh2 );

    painter->drawPixmap( rect.x()+ww,
                         rect.y()+rect.height()-wh2,
                         rect.width()-ww-ww2,
                         wh2,
                         buttonBase, bw, bh*2, bw, bh2 );

    painter->drawPixmap( rect.x()+rect.width()-ww2,
                         rect.y()+rect.height()-wh2,
                         ww2, wh2,
                         buttonBase, bw*2, bh*2, bw2, bh2 );


    painter->drawPixmap( rect.x(),
                         rect.y()+wh,
                         ww,
                         rect.height()-wh-wh2,
                         buttonBase, 0, bh, bw, bh );

    painter->drawPixmap( rect.x()+rect.width()-ww2,
                         rect.y()+wh,
                         ww2,
                         rect.height()-wh-wh2,
                         buttonBase, bw*2, bh, bw2, bh );
    }
