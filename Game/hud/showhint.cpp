#include "showhint.h"

ShowHint* ShowHint::inst = 0;

#include "settingswidget.h"
#include "runtime/gameobjectclass.h"

#include <QIcon>

ShowHint::ShowHint(){
    inst = this;
    }

ShowHint& ShowHint::instance(){
    return *inst;
    }

const QString& ShowHint::text(){
    return txt;
    }

void ShowHint::setText( const QString &s ){
    txt = s;
    }

void ShowHint::addMessage( const GameObjectClass* str ){
    if( str )
      addMessage( str->hint, str->icon );
    }

void ShowHint::addMessage( const QString & s, const QIcon &p ){
    msg.push_back( Message() );

    msg.back().msg  = s;
    msg.back().time = SettingsWidget::settings.messageShowTime;
    msg.back().icon = p.pixmap( 32, 32);
    }

void ShowHint::tick(){
    for( int i=0; i<msg.size(); ++i )
      --msg[i].time;

    if( msg.size() ){
      if( msg.front().time<=0 )
        msg.pop_front();
      }
    }

QQueue<ShowHint::Message>& ShowHint::messages(){
    return msg;
    }
