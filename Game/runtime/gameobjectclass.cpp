#include "gameobjectclass.h"

GameObjectClass::GameObjectClass(){
    for(int i=0; i<3; ++i){
      size[i] = 1;
      rand_size.min[i] = 1;
      rand_size.max[i] = 1;
      }
    rand_size.proportional = 0;

    group = "no_group";

    rand_rotate = 1;
    mvLock      = 0;
    buildTime   = 0;
    speed       = 0;

    cost.gold = 0;
    cost.lim  = 0;

    setUpView(view);
    setUpView(view1);

    isInvulnerable   = 1;

    atack.isAgressor = 1;
    atack.isUpgrade  = 0;

    atack.land_land.atackRange = 0;
    atack.land_land.damage     = 0;
    atack.land_land.time       = 0;
    atack.land_land.bullet     = "worker";

    maxHp = 100;

    view.surface_scerting = 0;
    selectable       = 1;
    }

void GameObjectClass::setUpView( View &view ){
    view.useCullFace  = 1;
    view.atest_shadow = 0;
    view.blend       = Blend::no;

    view.data  = "no_view";

    view.generate_texture.diff = 0;
    view.generate_texture.spec = 0;
    view.generate_texture.norm = 0;
    view.generate_texture.glow = 0;
    }

void GameObjectClass::copy( const GameObjectClass &other){
    for(int i=0; i<3; ++i)
      size[i] = other.size[i];

    rand_size   = other.rand_size;

    name        = other.name;
    group       = other.group;

    view        = other.view;
    view1       = other.view1;

    rand_rotate  = other.rand_rotate;

    behaviors = other.behaviors;
    mvLock    = other.mvLock;

    icon      = other.icon;

    buildTime = other.buildTime;

    recruts = other.recruts;
    speed   = other.speed;

    cost = other.cost;

    hint        = other.hint;
    priviewFile = other.priviewFile;

    //generate_texture = other.generate_texture;

    isInvulnerable = other.isInvulnerable;
    atack = other.atack;

    maxHp = other.maxHp;

    atkType  = other.atkType;
    armoType = other.armoType;

    selectable = other.selectable;
    needs = other.needs;
    }
