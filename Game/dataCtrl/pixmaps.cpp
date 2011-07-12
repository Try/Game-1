#include "pixmaps.h"

#include "log.h"

Pixmaps* Pixmaps::inst = 0;

Pixmaps::Pixmaps(){
    inst = this;
    }

Pixmaps::~Pixmaps(){
    for(Data::iterator i=data.begin(); i!=data.end(); ++i){
      delete i->second;
      }
    inst = 0;
    }

Pixmaps& Pixmaps::instance(){
    return *inst;
    }

void Pixmaps::add(QString file, std::string key){
    QImage *img = new QImage();

    if( !(img->load(file)) ){
      Log() << "pixmap \'" << file.toStdString() << "\' load error";
      } //else
      //Log() << "pixmap \'" << file.toStdString() << "\' ok";

    Data::iterator it = data.find(key);
    if( it!= data.end() ){
      delete it->second;
      }

    data[key] = img;
    }

QImage* Pixmaps::get( const std::string &name ){
    return instance().data[name];
    }

QIcon   Pixmaps::getIcon( const std::string &name){
    return QIcon( Pixmaps::getPm(name) );
    }

QPixmap   Pixmaps::getPm( const std::string &name){
    QImage *img = 0;
    if( inst )
      img = Pixmaps::get(name);

    if( img )
      return QPixmap::fromImage(*img); else
      return QPixmap();
    }
