#ifndef CURSORS_H
#define CURSORS_H

#include <QCursor>

class Cursors{
  public:
    Cursors();

    static const Cursors& instance();

    QCursor main, getMinerals;
  private:
    static Cursors* inst;
  };

#endif // CURSORS_H
