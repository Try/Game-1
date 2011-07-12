#include "filestream.h"

using namespace std;

#include <QDebug>

#include "game/game.h"
#include "game/objectcollection.h"


#define DECLARATE_INOUT(T) \
  FileStream& FileStream::operator << (const T& data){\
      write(data);\
      return *this;\
      }\
\
  FileStream& FileStream::operator >> ( T& data){\
      read(data);\
      return *this;\
      }\

FileStream::FileStream(const std::string &file, openMode m){
    if( m == in )
      f.open( file.data(), fstream::in |fstream::binary ); else
      f.open( file.data(), fstream::out|fstream::binary );
    //f << "[1]";

    omode = m;
    }

bool FileStream::isOpen(){
    return f.is_open();
    }
/*
template< class T >
void FileStream::write(const T& w){
    //qDebug() << "s = " << sizeof(w);
    f.write( (char*)&w, sizeof(w) );
    }

template< class T >
void FileStream::read( T& r){
    f.read( (char*)&r, sizeof(r) );
    }*/

FileStream& FileStream::operator << (const std::string& data){
    unsigned s = data.size();
    write( s );
    f.write( data.data(), data.size() );

    return *this;
    }

FileStream& FileStream::operator >> ( std::string& data){
    unsigned s;
    read( s );
    data.resize(s);
    f.read( (char*)data.data(), data.size() );
    return *this;
    }

bool FileStream::isIn(){
    return omode == in;
    }

bool FileStream::isOut(){
    return omode == out;
    }

FileStream& FileStream::serialize(GLObject *&data){
    if( omode==in ){
      int id;
      (*this) >> id;
      if( id>=0 )
        data = &Game::instance().objects()[id]; else
        data = 0;
      } else {
      (*this) << Game::instance().objects().find( data );
      }

    return *this;
    }

DECLARATE_INOUT(bool)
DECLARATE_INOUT(int)
DECLARATE_INOUT(unsigned)
DECLARATE_INOUT(unsigned long)
DECLARATE_INOUT(float)
DECLARATE_INOUT(double)
DECLARATE_INOUT(char)
