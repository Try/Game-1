#ifndef CENTRALBUILDINGBEHAVIOR_H
#define CENTRALBUILDINGBEHAVIOR_H

#include "abstractbehavior.h"
#include "movealgo.h"

#include <vector>
#include <string>

class GLObject;
class GameObjectClass;

#include "buildingbehavior.h"

class CentralBuildingBehavior:public BuildingBehavior{
  public:
    CentralBuildingBehavior( GLObject *obj );
    ~CentralBuildingBehavior();

    static const Registrator<CentralBuildingBehavior> registration;
    void setPlaylerEvent(int Old, int New);

    // void serialize(FileStream &f);
    void buyWorker();
  };

#endif // CENTRALBUILDINGBEHAVIOR_H
