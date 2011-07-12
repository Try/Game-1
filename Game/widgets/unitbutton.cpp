#include "unitbutton.h"

#include "globject.h"

UnitButton::UnitButton( GLObject *obj ){
  object = obj;
  setIconSize( QSize(40, 40) );
  setMinimumSize(40, 40);
  setMaximumSize(40, 40);

  setIcon( obj->getClass()->icon );

  setContextMenuPolicy( Qt::NoContextMenu );

  connect(this, SIGNAL(clicked()),
          this, SLOT(mouseClick()));

  }

void UnitButton::mouseClick(){
  Game::instance().select( object );
  }





