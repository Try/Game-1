#ifndef FILESTREAM_H
#define FILESTREAM_H

#include <string>
#include <fstream>

#include <vector>

#define DECLARATE_INOUT(T) \
  FileStream& operator << (const T& data); \
  FileStream& operator >> (      T& data);

class GLObject;

class FileStream{
  public:
    enum openMode{
      in,
      out
      };
    FileStream(const std::string &f, openMode m);

    bool isOpen();

    bool isIn();
    bool isOut();

    template< class T >
    FileStream& serialize ( T& data){
      if( omode==in )
        (*this) >> ((      T&)data); else
        (*this) << ((const T&)data);

      return *this;
      }

    DECLARATE_INOUT(std::string)

    DECLARATE_INOUT(bool)
    DECLARATE_INOUT(int)
    DECLARATE_INOUT(unsigned)
    DECLARATE_INOUT(unsigned long)
    DECLARATE_INOUT(float)
    DECLARATE_INOUT(double)
    DECLARATE_INOUT(char)

    template< class T >
    FileStream& operator + ( T& data){
      return serialize(data);
      }

    FileStream& serialize ( GLObject*& data);

    template< class T >
    void write(const T& w){
      f.write( (char*)&w, sizeof(w) );
      }

    template< class T >
    void read( T& r){
      f.read( (char*)&r, sizeof(r) );
      }

  private:
    std::fstream f;

    openMode omode;
  };

#undef DECLARATE_INOUT

#endif // FILESTREAM_H
