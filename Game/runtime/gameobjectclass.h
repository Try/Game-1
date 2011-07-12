#ifndef GAMEOBJECTCLASS_H
#define GAMEOBJECTCLASS_H

#include <string>
#include <vector>

#include <QIcon>

#include "runtime/atacktypes.h"

class GameObjectClass {
  public:
    GameObjectClass();

    double size[3];
    struct {
      double min[3], max[3];
      bool   proportional;
      } rand_size;

    struct Blend{
      enum Type{
        no,
        add,
        alpha
        };
      };

    struct View{
      bool useCullFace, atest_shadow;
      bool surface_scerting;
      std::string data;
      Blend::Type blend;


      struct GenerateTexture{
        bool diff, spec, norm, glow;
        } generate_texture;
      } view, view1;

    bool rand_rotate;

    std::string name, group;

    bool isInvulnerable;

    struct Atack{
      bool isAgressor, isUpgrade;

      struct Land_Land{
        int damage,
              time;
        double atackRange;
        std::string bullet;
        } land_land;
      } atack;

    int maxHp;

    int mvLock;
    int buildTime;

    void copy( const GameObjectClass &other);
    std::vector< std::string > behaviors;

    QIcon icon;
    QString hint, priviewFile;

    struct Recrut{
      std::string name;
      std::string hotKey;
      };

    std::vector< Recrut > recruts;
    std::vector< const GameObjectClass* > needs;

    double speed;

    struct Cost{
      int gold;
      int lim;
      } cost;

    AtackTypes::AtkType  atkType;
    AtackTypes::ArmoType armoType;

    bool selectable;

    void setUpView( View &v );
  };

#endif // GAMEOBJECTCLASS_H
