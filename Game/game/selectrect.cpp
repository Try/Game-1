#include "selectrect.h"

#include <algorithm>
#include <QDebug>

using namespace std;

SelectRect::SelectRect(){
    s = 0;
    x = 0;
    y = 0;
    }

void SelectRect::start(int x1, int y1){
    x = x1;
    y = y1;
    s = 1;
    }

bool SelectRect::isStarted(){
    return (s==2);
    }

void SelectRect::finish(){
    s = 0;
    }

QRect SelectRect::rect(int *xy){
    return rect(xy[0], xy[1]);
    }

QRect SelectRect::rect(int x1, int y1){
    if(s==1)
      s = 2;

    return QRect( min(x, x1),
                  min(y, y1),
                  max(x, x1) - min(x, x1),
                  max(y, y1) - min(y, y1) );
    }

bool SelectRect::isSmall(int x1, int y1){
    return (abs(x-x1)+abs(y-y1))<10;
    }
