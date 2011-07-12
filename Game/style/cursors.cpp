#include "cursors.h"

#include <QPixmap>
#include "dataCtrl/pixmaps.h"

Cursors* Cursors::inst = 0;

Cursors::Cursors(){
  inst = this;


  main        = QCursor( QPixmap("./pixmaps/cursor.png"), 2, 2 );
  getMinerals = QCursor( QPixmap("./pixmaps/cursor_get.png"), 2, 2 );
  }

const Cursors& Cursors::instance(){
  return *inst;
  }
