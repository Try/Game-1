#ifndef HOTKEYS_H
#define HOTKEYS_H

#include <vector>
#include <string>

#include <QKeyEvent>

class HotKeys {
  public:
    HotKeys();

    class IKey{
      public:
        virtual ~IKey(){}
        virtual void keyEvent( const QKeyEvent *event ) = 0;
      };

    template< class T >
    class Key:public IKey{
      public:
        Key(){
          object = 0;
          event = 0;
          inst->add(this);
          }

        ~Key(){
          inst->del(this);
          }

        void setKey( const std::string &k ){
          key = k.data();
          }

        void keyEvent( const QKeyEvent * ev){
          QString k = ev->text();
          if( ev->key() == Qt::Key_Control )
            k = "Ctrl";

          if( k==key && object )
            (object->*event)();
          }

        void setEvent(T *obj, void (T::*ev)()){
          object = obj;
          event  = ev;
          }

      private:
        QString key;
        T *object;
        void (T::*event)();
      };

    static void keyEvent( const QKeyEvent *event );
  private:
    void add(IKey *);
    void del(IKey *);

    std::vector< IKey* > keys;
    static HotKeys* inst;
  };

#endif // HOTKEYS_H
