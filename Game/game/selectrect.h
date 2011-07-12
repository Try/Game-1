#ifndef SELECTRECT_H
#define SELECTRECT_H

#include <QRect>

class SelectRect{
  public:
    SelectRect();

    void start(int x, int y);
    bool isStarted();
    bool isSmall(int x, int y);
    void finish();

    QRect rect(int x, int y);
    QRect rect(int *xy);
  private:
    int x, y;
    int s;
  };

#endif // SELECTRECT_H
