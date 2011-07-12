#include "behaviorcollection.h"

#include "dataCtrl/filestream.h"

BehaviorCollection::BehaviorCollection(){

    }

BehaviorCollection::~BehaviorCollection(){
    clear();
    }

void BehaviorCollection::clear(){
    for(unsigned i=0; i<behaviors.size(); ++i){
      delete behaviors[i];
      }
    behaviors.clear();
    }

void BehaviorCollection::add(AbstractBehavior* b){
    behaviors.push_back( b );
    }

bool BehaviorCollection::needToMoveDisplace(){
    for(unsigned i=0; i<behaviors.size(); ++i){
      if( behaviors[i]->needToMoveDisplace()  )
        return 1;
      }

    return 0;
    }

AbstractBehavior* BehaviorCollection::getBehavior( const std::string& name ){
    for(unsigned i=0; i<behaviors.size(); ++i){
      if( behaviors[i]->name() == name )
        return behaviors[i];
      }

    return 0;
    }

void BehaviorCollection::del(AbstractBehavior* b ){
    for(unsigned i=0; i<behaviors.size(); ++i){
      if( behaviors[i]==b ){
        behaviors[i] = behaviors.back();
        behaviors.pop_back();
        delete b;
        return;
        }
      }
    }

void BehaviorCollection::tick(){
    for(unsigned i=0; i<behaviors.size(); ++i){
      behaviors[i]->tick();
      }
    }

int BehaviorCollection::buildQueueSize(){
    int s = 0;
    for(unsigned i=0; i<behaviors.size(); ++i){
      s += behaviors[i]->buildQueueSize();
      }

    return s;
    }

void BehaviorCollection::command( GLObject* obj ){
    for(unsigned i=0; i<behaviors.size(); ++i){
      behaviors[i]->command( obj );
      }
    }

void BehaviorCollection::command(float x, float y, int sq, bool fake){
    for(unsigned i=0; i<behaviors.size(); ++i){
      behaviors[i]->command(x,y,sq,fake);
      }
    }

void  BehaviorCollection::deleteUnitEvent( const GLObject* obj ){
    for(unsigned i=0; i<behaviors.size(); ++i){
      behaviors[i]->deleteUnitEvent( obj );
      }
    }

void BehaviorCollection::setMoveDisplace(float x, float y){
    for(unsigned i=0; i<behaviors.size(); ++i){
      behaviors[i]->setMoveDisplace(x,y);
      }
    }

void BehaviorCollection::selectEvent( bool s ){
    for(unsigned i=0; i<behaviors.size(); ++i){
      behaviors[i]->selectEvent( s );
      }
    }

void BehaviorCollection::positionEvent(float x, float y){
    for(unsigned i=0; i<behaviors.size(); ++i){
      behaviors[i]->positionEvent(x,y);
      }
    }


IController* BehaviorCollection::createController(){
    IController* c = 0;
    for(unsigned i=0; i<behaviors.size(); ++i){
      c = behaviors[i]->createController();
      if( c )
        return c;
      }

    return c;
    }

void BehaviorCollection::serialize(FileStream &f, GLObject *owner){
    if( f.isOut() ){
      int s = behaviors.size();
      f << s;
      for(unsigned i=0; i<behaviors.size(); ++i)
        f << behaviors[i]->name();
      } else {
      clear();
      int s;
      f >> s;

      for(int i=0; i<s; ++i){
        std::string name;
        f >> name;
        add( AbstractBehavior::create(owner, name) );
        }
      }

    for(unsigned i=0; i<behaviors.size(); ++i){
      behaviors[i]->serialize(f);
      }
    }

void BehaviorCollection::serialize(FileStream &){
    // not usage, go up^
    }

void BehaviorCollection::setPlaylerEvent(int Old, int New){
    for(unsigned i=0; i<behaviors.size(); ++i){
      behaviors[i]->setPlaylerEvent(Old, New);
      }
    }
