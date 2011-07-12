#ifndef BUILDINGBEHAVIOR_H
#define BUILDINGBEHAVIOR_H

#include "game/falagownerbahavior.h"
#include "movealgo.h"

#include <vector>
#include <string>

class GLObject;
class GameObjectClass;

class BuildingBehavior:public FalagOwnerBahavior{
  public:
    BuildingBehavior( GLObject *obj );
    ~BuildingBehavior();

    static const Registrator<BuildingBehavior> registration;

    int x();
    int y();

    float worldX();
    float worldY();

    void tick();
    void command(float , float , int, bool);

    void positionEvent(float, float);

    void setPlaylerEvent(int Old, int New);

    IController* createController();

    float progressBar();

    std::vector< std::string >& buildQueue();

    void removeFromQueue(int id);
    void build( const std::string &s );
    void buildByController( const std::string &s );

    const GameObjectClass& ownerClass();
    int buildQueueSize();

    void serialize(FileStream &f);
  protected:
    void createObject( const std::string &name );
  private:
    int buildTime;
    std::vector< std::string > queue;

    int   maxBuildTime;
    bool  isDelay;

    void upsetPointFlagPos();
  };

#endif // BUILDINGBEHAVIOR_H
