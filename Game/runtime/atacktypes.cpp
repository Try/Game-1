#include "atacktypes.h"

AtackTypes * AtackTypes::inst = 0;

AtackTypes::AtackTypes(){
    inst = this;
    }

AtackTypes& AtackTypes::instance(){
    return *inst;
    }

void AtackTypes::add( const std::string& e, const std::string& r,
                      double val ){
    int eh = hash(e, emitterHash);
    int rh = hash(r, reciverHash);

    if( atkMatrix.size() <= (unsigned)eh ){
      int h = 0;
      if( eh ){
        h = atkMatrix[0].size();
        }

      atkMatrix.resize(eh+1);

      for(unsigned i=0; i<atkMatrix.size(); ++i)
        atkMatrix[i].resize(h);
      }

    if( atkMatrix[0].size() <= (unsigned)rh){
      for(unsigned i=0; i<atkMatrix.size(); ++i)
        atkMatrix[i].resize(rh+1);
      }

    atkMatrix[eh][rh] = val;
    }

int AtackTypes::hash( const std::string& e,
                      AtackTypes::hMap& hMap ){
    AtackTypes::hMap::iterator i = hMap.find(e);

    if( i==hMap.end() ){
      int id = hMap.size();
      hMap[e] = id;
      return id;
      } else {
      return i->second;
      }
    }

AtackTypes::AtkType AtackTypes::getAtk( const std::string& e ){
    AtkType a;
    a.id =  hash(e, emitterHash);
    return a;
    }

AtackTypes::ArmoType AtackTypes::getArmo( const std::string& e ){
    ArmoType a;
    a.id =  hash(e, reciverHash);
    return a;
    }

double AtackTypes::get( const AtkType &a, const ArmoType &d){
    return inst->atkMatrix[ a.id ][ d.id ];
    }
