#include "resourcebehavior.h"

#include "game.h"

#include "dataCtrl/filestream.h"
#include "globject.h"

using namespace std;

const AbstractBehavior::Registrator<ResourceBehavior>
  ResourceBehavior::registration( "resource" );

std::vector< ResourceBehavior* > ResourceBehavior::m_items;

ResourceBehavior::ResourceBehavior( GLObject * obj):ow(obj){
    count = 1500;
    lx = -1;
    ly = -1;

    ow->setMinSelSize( 0.275 );

    isUsed = ResourceBehavior::NoUsing;

    m_items.push_back( this );
    }

ResourceBehavior::~ResourceBehavior(){
    positionEvent(-1, -1);

    for(size_t i=0; i<m_items.size(); ++i){
      if(m_items[i]==this){
        m_items[i] = m_items.back();
        m_items.pop_back();
        return;
        }
      }
    }

GLObject * ResourceBehavior::owner(){
    return ow;
    }

void ResourceBehavior::positionEvent(float x, float y){
    if( lx==Map::coordX(x) &&
        ly==Map::coordY(y) )
      return;

    if( Game::instance().map.exist(lx, ly) ){
      Game::instance().map.editResCount(lx, ly, -count);
      }

    isUsed = ResourceBehavior::NoUsing;

    lx = Map::coordX(x);
    ly = Map::coordY(y);

    fx = x;
    fy = y;

    if( Game::instance().map.exist(lx, ly) ){
      Game::instance().map.editResCount(lx, ly, count);
      }
    }

std::vector< ResourceBehavior* >& ResourceBehavior::items(){
    return m_items;
    }

float ResourceBehavior::x(){
    return fx;
    }

float ResourceBehavior::y(){
    return fy;
    }


IController* ResourceBehavior::createController(){
    return 0;
    }

void ResourceBehavior::serialize(FileStream &f){
    f + //isUsed +
        count  +
        lx + ly +
        fx + fy;

    lx = -1;
    ly = -1;

    if( f.isIn() ){
      int s;
      f >> s;
      isUsed = Using(s);
      } else {
      int s = int(isUsed);
      f << s;
      }

    positionEvent( owner()->x(), owner()->y() );
    }

GLObject* ResourceBehavior::resAt(float x, float y){
    for( size_t i=0; i<m_items.size(); ++i)
      if( m_items[i]->owner()->canSel(x,y) )
        return m_items[i]->owner();

    return 0;
    }
