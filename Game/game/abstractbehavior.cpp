#include "abstractbehavior.h"

std::map<std::string, AbstractBehavior::IRegistrator*>
  *AbstractBehavior::reg = 0;

AbstractBehavior::AbstractBehavior(){

    }

AbstractBehavior* AbstractBehavior::create(GLObject *owner, const std::string& s){
    AbstractBehavior* re =  create(owner, s.data() );
    re->setName( s );
    return re;
    }

AbstractBehavior* AbstractBehavior::create(GLObject *ow, const char* n){
    return (*reg)[n]->construct(ow);
    }

void AbstractBehavior::free(){
    delete reg;
    }

void AbstractBehavior::setName(const std::string &s){
    m_name = s;
    }

const std::string& AbstractBehavior::name(){
    return m_name;
    }
