#include "objectcollection.h"
#include "../globject.h"

#include <cmath>

#include "../widgets/unitsgroup.h"
#include "dataCtrl/filestream.h"

#include "game/playler.h"

#include <QDebug>

#include "game/unitbehavior.h"
#include "game/warriorbehavior.h"

ObjectCollection::ObjectCollection(){
    m_isGroupControlled = 0;
    needToGuiUpdate     = 0;
    }

ObjectCollection::~ObjectCollection(){
		clear();
		}

void ObjectCollection::clear(){
		for(unsigned i=0u; i<object.size(); ++i)
			delete object[i];

    object. clear();
    mvUnits.clear();
    sunits. clear();
    m_interactive.clear();
    }

GLObject& ObjectCollection::operator [](int id){
    return *object[id];
    }

const GLObject& ObjectCollection::operator [](int id) const{
    return *object[id];
    }

void ObjectCollection::add(GLObject *a){
    object.push_back( a );

    if( a->getClass()->speed > 0 ){
      mvUnits.push_back( a );
      }

    if( !a->getClass()->isInvulnerable ){
      m_interactive.push_back(a);
      }
    }

int ObjectCollection::size() const{
    return object.size();
    }

void ObjectCollection::del( GLObject *& obj ){
    if( obj ){
      removeFrom(obj, object);
      removeFromSets(obj);

      delete obj;
      obj = 0;
      }

    }

void ObjectCollection::removeFromSets( GLObject *obj ){
    removeFrom(obj, sunits);
    UnitsGroup::removeUnit( obj );
    removeFrom(obj, mvUnits);
    removeFrom(obj, m_interactive);
    }

void ObjectCollection::removeFrom( GLObject *obj,
                                   std::vector<GLObject*>& units ){
    for(unsigned i=0; i<units.size(); ++i)
      if( units[i]==obj ){
        units[i] = units.back();
        units.pop_back();
        return;
        }
    }

const std::vector<GLObject*>& ObjectCollection::selected() const{
    return sunits;
    }

std::vector<GLObject*>& ObjectCollection::moviable(){
    return mvUnits;
    }

std::vector<GLObject*>& ObjectCollection::interactive(){
    return m_interactive;
    }

GLObject* ObjectCollection::unitAt( double x, double y ) const{
		GLObject* re = 0;

		enum{
			fNull,
			fBuildings,
			fUnits
			} filter = fNull;

		for(unsigned i=0; i<object.size(); ++i){
			if( object[i]->canSel(x,y) ){
				if( filter < fBuildings &&
						object[i]->getClass()->group=="building" ){
					filter = fBuildings;
					re = object[i];
					}

				if( //filter < fUnits &&
						object[i]->getClass()->group=="unit" ){
					filter = fUnits;
					re = object[i];
					}
				}
			}

		return re;
		}

void ObjectCollection::select( double x, double y){
		unSelect();

		enum{
			fNull,
			fBuildings,
			fUnits
			} filter = fNull;

		std::string tagetGroup;
		m_isGroupControlled = 0;

		for(unsigned i=0; i<object.size(); ++i){
			object[i]->computeSel( x, y );
			if( object[i]->isSel() ){
				sunits.push_back( object[i] );

				if( filter < fBuildings &&
						object[i]->getClass()->group=="building" ){
					filter = fBuildings;
					tagetGroup = "building";
					}

				if( //filter < fUnits &&
						object[i]->getClass()->group=="unit" ){
					filter = fUnits;
					tagetGroup = "unit";
					}

				if( object[i]->playlerPtr().isDrived() )
					m_isGroupControlled = 1;

				}
			}

		if( tagetGroup.size() ){
			unsigned nsize = 0;
			for(unsigned i=0; i<sunits.size(); ++i){
				if( sunits[i]->getClass()->group==tagetGroup &&
						 ( !m_isGroupControlled ||
							 sunits[i]->playlerPtr().isDrived() )){
					sunits[nsize] = sunits[i];
					++nsize;
					} else {
					sunits[i]->setSel(0);
					}
				}
			sunits.resize(nsize);
			}

    if( sunits.size() ){
      for(unsigned i=1; i<sunits.size(); ++i){
        sunits[i]->setSel(0);
        }
      sunits.resize(1);
      }

    //updateGUI();
    toGuiUpdate();
    }

void ObjectCollection::select( GLObject* obj){
    unSelect();
    sunits.push_back( obj );
    obj->setSel(1);

    m_isGroupControlled = obj->playlerPtr().isDrived();

    //updateGUI();
    toGuiUpdate();
    }

void ObjectCollection::select( QRectF r ){
		sunits.clear();

		enum{
			fNull,
			fBuildings,
			fUnits
			} filter = fNull;

		std::string tagetGroup;
		m_isGroupControlled = 0;

		for(unsigned i=0; i<object.size(); ++i){
			object[i]->computeSel( r.x(), r.y(), r.width(), r.height() );
			if( object[i]->isSel() ){
				sunits.push_back( object[i] );

				if( filter < fBuildings &&
						object[i]->getClass()->group=="building" ){
					filter = fBuildings;
					tagetGroup = "building";
					}

				if( //filter < fUnits &&
						object[i]->getClass()->group=="unit" ){
					filter = fUnits;
					tagetGroup = "unit";
					}

				if( object[i]->playlerPtr().isDrived() )
					m_isGroupControlled = 1;

				}
			}

		if( tagetGroup.size() ){
			unsigned nsize = 0;
			for(unsigned i=0; i<sunits.size(); ++i){
				if( sunits[i]->getClass()->group==tagetGroup &&
						 ( !m_isGroupControlled ||
							 sunits[i]->playlerPtr().isDrived() )){
					sunits[nsize] = sunits[i];
					++nsize;
					} else {
					sunits[i]->setSel(0);
					}
				}
			sunits.resize(nsize);
			}

    //updateGUI();
    toGuiUpdate();
    }

void ObjectCollection::aClick(float x, float y){
    command(x, y);

    for(size_t i=0; i<sunits.size(); ++i){
      GLObject *obj = sunits[i];
      {

        UnitBehavior *war = (UnitBehavior*)obj->getBehavior("unit");

        if( war ){
          war->getWarrior()->setAtack(1);
          war->getWarrior()->setAClick(1, x, y);
          }
        }
      }
    }

void ObjectCollection::command( GLObject * taget ){
		for(unsigned i=0; i<sunits.size(); ++i){
			sunits[i]->command( taget );
			}
		}

void ObjectCollection::coolMoveCommand(float x, float y){
		int sq = sqrt( sunits.size() );

		float dx = 0, dy = 0, ddy = 0;
		for(unsigned i=0; i<sunits.size(); ++i){
			if( Game::instance().map.existf( x+dx, y+dy ) ||
					Game::instance().map.resCountf( x+dx, y+dy )){
				sunits[i]->command(x+dx, y+dy, 0, 0 );
				dx += sunits[i]->viewSize();
				ddy = std::max(ddy, sunits[i]->viewSize());
				if( i%sq==0 ){
					dy += ddy;
					ddy = 0;
					dx = 0;
					}
				} else
				sunits[i]->command(x, y, 0, 0);
			}
		}

void ObjectCollection::command(float x, float y){
		if( !Game::instance().map.existf( x, y ) ){
			return;
			}

    if( sunits.size()<250  &&
        Game::instance().map.resCountf( x, y )==0 &&
        sunits.size() &&
        sunits[0]->getBehavior("building")==0 &&
        sunits[0]->getBehavior("incomplete_building")==0  ){
      coolMoveCommand(x, y);
      } else {
      int sq = sqrt( sunits.size() )*0.5;
      for(unsigned i=0; i<sunits.size(); ++i){
        sunits[i]->command(x, y, sq, 0);
        }
      }

    }

void ObjectCollection::toGuiUpdate(){
    needToGuiUpdate = 1;
    UnitsGroup::lock();
    }

void ObjectCollection::tick(){
    if( needToGuiUpdate )
      updateGUI();

		for(unsigned i=0; i<object.size(); ++i){
			object[i]->tick();
			}

		destroyDeathUnits();
		}

void ObjectCollection::unSelect(){
		for(unsigned i=0; i<sunits.size(); ++i){
			sunits[i]->setSel(0);
			}
		sunits.clear();

    m_isGroupControlled = 0;
    //updateGUI();
    toGuiUpdate();
    }

void ObjectCollection::updateGUI(){
    UnitsGroup::rebuildData();
    needToGuiUpdate = 0;
    }

void ObjectCollection::serialize(FileStream &f, bool map){
		int s = size();
		f.serialize(s);

		if( f.isIn() ){
			clear();
			}

		// qDebug() << s;
		// return;

		for(int i=0; i<s; ++i){
			if( f.isIn() ){
				std::string cls;
				f >> cls;
				Game::instance().add( cls );//->serialize(f);
				} else {
				f << object[i]->getClass()->name;
				//object[i]->serialize(f);
				}
			}

		if( map ){
			for(int i=0; i<size(); ++i)
				object[i]->serializeMap(f);
			} else {
			for(int i=0; i<size(); ++i)
				object[i]->serialize(f);
			}

		if( f.isIn() ){
			sunits.clear();
			m_isGroupControlled = 0;

			for(unsigned i=0; i<object.size(); ++i){
				if( object[i]->isSel() ){
					sunits.push_back( object[i]);
					m_isGroupControlled |= object[i]->playlerPtr().isDrived();
					}
				}

			updateGUI();
			}

		}

int ObjectCollection::find( const GLObject *obj){
		if( obj==0 )
			return -1;

		for(unsigned i=0; i<object.size(); ++i)
			if( object[i]==obj ){
				return i;
				}

		return -1;
		}


void ObjectCollection::sortPass(){
    for(int i=0; i<(int)object.size()-1; ++i){
      if( object[i]->gridNum() > object[i+1]->gridNum() )
        std::swap(object[i], object[i+1] );
      }
    }

bool ObjectCollection::isGroupControlled(){
    return m_isGroupControlled;
    }

void ObjectCollection::destroyDeathUnits(){
    bool recreateCtrl = 0;
    for(size_t i=0; i<object.size(); /*++i*/){
      if( object[i]->hp()<=0 ){
        if( selected().size() &&( selected()[0]==object[i]) )
          recreateCtrl = 1;

        removeFromSets( object[i] );

        GLObject* dObject = object[i];
        object[i] = object.back();
        object.pop_back();

        for(size_t r=0; r<object.size(); ++r)
          object[r]->deleteUnitEvent( dObject );

        dObject->deathEvent();
        delete dObject;
        } else {
        ++i;
        }
      }

    if( recreateCtrl )
      Game::instance().createController();

    }
