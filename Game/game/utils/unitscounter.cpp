#include "unitscounter.h"

#include <QDebug>

UnitsCounter::UnitsCounter(){

    }

void UnitsCounter::add( const GameObjectClass* x){
    if( count.find(x)==count.end() )
      count[x] = 0;

    ++count[x];
    }

void UnitsCounter::del( const GameObjectClass* x){
    --count[x];
    if( count[x]<0 ){
      qDebug() << "Count Error";
      }
    }

int UnitsCounter::countOf( const GameObjectClass* x){
    int re = count[x];
    return re;
    }
