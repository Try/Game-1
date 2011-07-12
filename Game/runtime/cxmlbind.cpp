#include "cxmlbind.h"

#include <QXmlInputSource>
#include <QXmlSimpleReader>

#include <QDebug>

#include "gameclasses.h"
#include "gameobjectclass.h"

#include "dataCtrl/pixmaps.h"
#include "runtime/atacktypes.h"
#include "log.h"

class CXMLBind::Parser : public QXmlDefaultHandler {
  public:
    Parser(){
      cls = 0;
      }

    bool extract(QString &x, QString var, const QXmlAttributes &attrs){
      for( int i=0; i<attrs.count(); ++i ){
        if( attrs.localName( i )==var ){
          x = attrs.value(i);
          return 1;
          }
        }
      return 0;
      }

    bool extract(std::string &x, QString var, const QXmlAttributes &attrs){
      for( int i=0; i<attrs.count(); ++i ){
        if( attrs.localName( i )==var ){
          x = attrs.value(i).toStdString();
          return 1;
          }
        }
      return 0;
      }

    bool extract(int &x, QString var, const QXmlAttributes &attrs){
      for( int i=0; i<attrs.count(); ++i ){
        if( attrs.localName( i )==var ){
          x = attrs.value(i).toInt();
          return 1;
          }
        }
      return 0;
      }

    bool extract(double &x, QString var, const QXmlAttributes &attrs){
      for( int i=0; i<attrs.count(); ++i ){
        if( attrs.localName( i )==var ){
          x = attrs.value(i).toDouble();
          return 1;
          }
        }
      return 0;
      }

    bool extract(double size[], QString xyz, const QXmlAttributes &attrs){
      QString xy, xz, yz;

      xy.append(xyz[0]).append(xyz[1]);
      xz.append(xyz[0]).append(xyz[2]);
      yz.append(xyz[1]).append(xyz[2]);

      for( int i=0; i<attrs.count(); i++ ){
        if( attrs.localName( i )==xyz ){
          size[0] = attrs.value(i).toDouble();
          size[1] = size[0];
          size[2] = size[0];
          return 1;
          }

        if( attrs.localName( i )==xy ){
          size[0] = attrs.value(i).toDouble();
          size[1] = size[0];
          }

        if( attrs.localName( i )==xz ){
          size[0] = attrs.value(i).toDouble();
          size[2] = size[0];
          }

        if( attrs.localName( i )==yz ){
          size[2] = attrs.value(i).toDouble();
          size[1] = size[2];
          }
        }

      extract(cls->size[0], QString(xyz[0]), attrs);
      extract(cls->size[1], QString(xyz[1]), attrs);
      extract(cls->size[2], QString(xyz[2]), attrs);

      return true;
      }

    bool extract(bool &x, QString var, const QXmlAttributes &attrs){
      for( int i=0; i<attrs.count(); ++i ){
        if( attrs.localName( i )==var ){
          x = !( attrs.value(i) == "false" ||
                 attrs.value(i) == "0");
          return 1;
          }
        }
      return 0;
      }

    bool startDocument(){
      return true;
      }

    bool endElement( const QString&, const QString &lname, const QString & ){
      if( lname=="class" ){
        GameClasses::add( cls );
        cls = 0;
        }
      //qDebug() << lname;

      return true;
      }

    bool startElement( const QString& , const QString& , const QString &lname,
                       const QXmlAttributes &attrs ){
      if( 0 ){

        for( int i=0; i<attrs.count(); i++ ){
          qDebug() << lname <<" "<<attrs.localName( i ) <<" = " << attrs.value(i);
          }

        }

      if( lname == "pixmap" ){
        QString file;
        std::string key;

        extract(file, "file", attrs);
        extract(key,  "key" , attrs);

        Pixmaps::instance().add(file, key);
        return 1;
        }

      if( lname=="class" ){
        cls = new GameObjectClass();

        std::string exClass;
        extract(exClass, "extends", attrs);

        if( exClass.size() ){
          cls->copy( *GameClasses::get( exClass.data() ) );
          }

        return extract(cls->name, "name", attrs);
        }

      if( lname=="view" ||
          lname=="view0"){
        if( cls==0 )
          return false;

        extractView( cls->view, attrs );
        return 1;
        }

      if( lname=="view1" ){
        if( cls==0 )
          return false;

        extractView( cls->view1, attrs );
        return 1;
        }

      if( lname=="hint" ){
        if( cls==0 )
          return false;

        extract(cls->hint, "text", attrs);

        QString str;
        if( cls->hint.size() )
          str += cls->hint[0];
        for(int i=1; i<cls->hint.size(); ++i)
          if( !(cls->hint[i  ]==' ' &&
                cls->hint[i-1]==' ') )
            str += cls->hint[i];
        cls->hint = str;
        return 1;
        }

      if( lname=="priview" ){
        if( cls==0 )
          return false;

        return extract(cls->priviewFile, "file", attrs);
        }

      if( lname=="need" ){
        if( cls==0 )
          return false;

        std::string taget;
        extract(taget, "object", attrs);

        const GameObjectClass *c = GameClasses::get(taget);
        if( c ){
          cls->needs.push_back( c );
          return 1;
          } else {
          qDebug() << "class " << taget.data() << "not found";
          return 0;
          }
        }

      if( lname=="input" ){
        if( cls==0 )
          return false;

        extract(cls->selectable, "selectable", attrs);
        }

      if( lname=="atack_mode" ){
        if( cls==0 )
          return false;

        extract(cls->isInvulnerable, "invulnerable", attrs);
        extract(cls->atack.isAgressor, "agressor", attrs);
        extract(cls->atack.isUpgrade,  "isGrade", attrs);
        }

      if( lname=="moveLock" ){
        if( cls==0 )
          return false;

        return extract(cls->mvLock, "size", attrs);
        }

      if( lname=="battle" ){
        if( cls==0 )
          return false;

        std::string s[2];
        extract( s[0], "atack", attrs);
        extract( s[1], "armo",  attrs);

        cls->atkType  = AtackTypes::instance().getAtk (s[0]);
        cls->armoType = AtackTypes::instance().getArmo(s[1]);
        return 1;
        }

      if( lname=="atack" ){
        std::string s[2];
        double k = 1.0;
        extract( s[0], "emitter",  attrs);
        extract( s[1], "receiver", attrs);

        extract( k, "dim", attrs);

        AtackTypes::instance().add(s[0], s[1], k);
        return 1;
        }

      if( lname=="generate" ){
        if( cls==0 )
          return false;

        extract(cls->view.generate_texture.diff, "texture",  attrs);
        extract(cls->view.generate_texture.spec, "specular", attrs);
        extract(cls->view.generate_texture.norm, "normal",   attrs);
        extract(cls->view.generate_texture.glow, "glow",     attrs);
        return 1;
        }

      if( lname=="cost" ){
        if( cls==0 )
          return false;

        extract(cls->cost.gold, "gold", attrs);
        extract(cls->cost.lim,  "lim",  attrs);

        return 1;
        }

      if( lname=="speed" ){
        if( cls==0 )
          return false;

        return extract(cls->speed, "moveSpeed", attrs);
        }

      if( lname=="hp" ){
        if( cls==0 )
          return false;

        return extract(cls->maxHp, "max", attrs);
        }

      if( lname=="atack_ll" ){
        if( cls==0 )
          return false;

        extract(cls->atack.land_land.damage, "damage", attrs);
        extract(cls->atack.land_land.time,   "time",   attrs);
        extract(cls->atack.land_land.atackRange, "atackRange",   attrs);

        extract(cls->atack.land_land.bullet, "bullet",   attrs);
        return 1;
        }

      if( lname=="build" ){
        if( cls==0 )
          return false;

        return extract(cls->buildTime, "time", attrs);
        }

      if( lname=="icon" ){
        if( cls==0 )
          return false;

        std::string file;
        extract(file, "file", attrs);

        QPixmap img;
        if( !img.load( file.data() ) )
          Log() << "file \"" << file <<"\" noit found";
        cls->icon = QIcon( img );
        return 1;
        }

      if( lname=="group" ){
        if( cls==0 )
          return false;

        return extract(cls->group, "name", attrs);
        }

      if( lname=="behavior" ){
        if( cls==0 )
          return false;

        std::string b;
        extract(b, "name", attrs);
        cls->behaviors.push_back(b);
        return 1;
        }

      if( lname=="recrut" ){
        if( cls==0 )
          return false;

        std::string name;
        extract(name, "name", attrs);

        if( name.size() ){
          cls->recruts.push_back( GameObjectClass::Recrut() );
          GameObjectClass::Recrut &r = cls->recruts.back();

          r.name   = name;
          extract(r.hotKey, "shortcut", attrs);
          return 1;
          }

        return 0;
        }

      if( lname=="init" ){
        if( cls==0 )
          return false;

        return extract(cls->rand_rotate, "rand_rotate", attrs);
        }

      if( lname=="rand_size" ){
        if( cls==0 )
          return false;

        extract(cls->rand_size.proportional, "proportional", attrs);
        return 1;
        }

      if( lname=="rand_size_min" ){
        if( cls==0 )
          return false;

        extract(cls->rand_size.min, "xyz", attrs);
        return 1;
        }
      if( lname=="rand_size_max" ){
        if( cls==0 )
          return false;

        extract(cls->rand_size.min, "xyz", attrs);
        return 1;
        }

      if( lname=="size" ){
        if( cls==0 )
          return false;

        extract(cls->size, "xyz", attrs);
        return true;
        }

      if( lname=="module" ){
        if( cls )
          return false;

        std::string file;
        extract(file, "file", attrs);

        CXMLBind xml;
        xml.load( file.data() );
        return true;
        }

      return true;
      }

  private:
    void extractView( GameObjectClass::View& view,
                      const QXmlAttributes &attrs ){
      extract(view.useCullFace, "cull", attrs);
      extract(view.data,        "data", attrs);
      extract(view.surface_scerting, "scerting", attrs);

      std::string blend;
      extract(blend, "blend", attrs);

      if( blend=="add" ){
        view.blend = GameObjectClass::Blend::add;
        }

      if( blend=="alpha" ){
        view.blend = GameObjectClass::Blend::alpha;
        }

      extract(view.atest_shadow, "atest_shadow", attrs);
      }

    GameObjectClass *cls;
  };

CXMLBind::CXMLBind(){

  }

void CXMLBind::load( const char *f ){
    Parser handler;

    QFile file( f );
    QXmlInputSource source( &file );

    QXmlSimpleReader reader;
    reader.setContentHandler( &handler );

    reader.parse( source );
    }
