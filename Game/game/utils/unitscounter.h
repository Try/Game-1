#ifndef UNITSCOUNTER_H
#define UNITSCOUNTER_H

#include <map>
#include "runtime/gameobjectclass.h"

class UnitsCounter{
  public:
    UnitsCounter();

    void add( const GameObjectClass*);
    void del( const GameObjectClass*);

    int countOf( const GameObjectClass*);
  private:
    std::map<  const GameObjectClass*, int > count;
  };

#endif // UNITSCOUNTER_H
