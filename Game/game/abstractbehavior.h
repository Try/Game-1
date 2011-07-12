#ifndef ABSTRACTBEHAVIOR_H
#define ABSTRACTBEHAVIOR_H

#include <string>
#include <map>

class GLObject;
class IController;
class FileStream;

class AbstractBehavior{
  public:
    AbstractBehavior();
    virtual ~AbstractBehavior(){}

    class IRegistrator{
      public:
        virtual ~IRegistrator(){}

        virtual const std::string& name() = 0;
        virtual AbstractBehavior* construct(GLObject* ) = 0;
      };

    static AbstractBehavior* create(GLObject *owner, const char*);
    static AbstractBehavior* create(GLObject *owner, const std::string& );
    static void free();

    virtual void tick(){}
    virtual void command(float , float , int, bool ){}
    virtual void command( GLObject* ){}
    virtual void deleteUnitEvent( const GLObject* ){}

    virtual bool needToMoveDisplace(){return 0;}
    virtual void setMoveDisplace(float , float ){}

    virtual int buildQueueSize(){ return 0; }

    virtual void positionEvent(float, float){}
    virtual void setPlaylerEvent(int /*Old*/, int /*New*/) = 0;

    virtual IController* createController() = 0;
    virtual void serialize(FileStream &f) = 0;

    virtual void selectEvent( bool /*s*/ ){}

    const std::string& name();
  protected:
    void setName(const std::string &s);

    template< class T >
    class Registrator:public IRegistrator{
      public:
        Registrator( const char* n ){
          m_name = n;
          if( !reg )
            reg = new std::map<std::string, IRegistrator*>();
          (*AbstractBehavior::reg)[ m_name ] = this;
          }

        const std::string& name(){
          return m_name;
          }

        AbstractBehavior* construct(GLObject *obj){
          return new T(obj);
          }
      private:
        std::string m_name;
      };
  private:
    static std::map<std::string, IRegistrator*> *reg;

    std::string m_name;
  };

#endif // ABSTRACTBEHAVIOR_H
