#include "hotkeys.h"

#include <QDebug>

HotKeys* HotKeys::inst = 0;

HotKeys::HotKeys() {
    inst = this;
    }

void HotKeys::add(IKey *k){
    keys.push_back(k);
    }

void HotKeys::del(IKey *k){
    for(size_t i=0; i<keys.size(); ++i){
      if( keys[i]==k ){
        keys[i] = keys.back();
        keys.pop_back();
        return;
        }
      }

    }

void HotKeys::keyEvent( const QKeyEvent *event ){
    for(size_t i = 0; i<inst->keys.size(); ++i)
      inst->keys[i]->keyEvent(event);
    }
