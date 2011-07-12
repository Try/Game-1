#ifndef GAMECLASSES_H
#define GAMECLASSES_H

#include <vector>
#include <string>

class GameObjectClass;
class AtackTypes;

class GameClasses {
  public:
    GameClasses();
    ~GameClasses();

    static const std::vector<GameObjectClass*>& classes();
    static void add(GameObjectClass *cls);

    static const GameObjectClass* get(const char * name);
    static const GameObjectClass* get(const std::string &s);
  private:
    std::vector<GameObjectClass*> cls;
    static GameClasses *inst;

    static AtackTypes* atkTypes;
  };

#endif // GAMECLASSES_H
