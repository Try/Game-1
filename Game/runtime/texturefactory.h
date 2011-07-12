#ifndef TEXTUREFACTORY_H
#define TEXTUREFACTORY_H

#include <map>
#include <string>

#include <MyGL/ITexture2d>
#include <MyGL/IScene>

class QImage;
class QColor;

class TextureFactory{
  public:
    TextureFactory( MyGL::IScene &scene );
    ~TextureFactory();

    static MyGL::ITexture2d* genTexture( const std::string& name,
                                         const std::string& base,
                                         const std::string& base1,
                                         const QColor &color );

  private:
    typedef std::map< std::string, MyGL::ITexture2d* > Cash;
    Cash cash;
    MyGL::IScene &scene;

    MyGL::ITexture2d* creteTexture( QImage &img );
    static TextureFactory *instance;

    static void buildTexture( QImage &out,
                              const QColor &color,
                              QImage *base, QImage *mask );
  };

#endif // TEXTUREFACTORY_H
