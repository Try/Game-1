#ifndef BMPMAP_H
#define BMPMAP_H

#include <string>

class Game;
class QColor;

class BmpMap {
  public:
    static void load(Game &game, const std::string &);

  private:
    static void pixel(Game &game, int x, int y, const QColor& c);
    static int curPl;
  };

#endif // BMPMAP_H
