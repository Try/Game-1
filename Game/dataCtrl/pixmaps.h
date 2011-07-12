#ifndef PIXMAPS_H
#define PIXMAPS_H

#include <QImage>
#include <QIcon>
#include <QPixmap>
#include <map>

class Pixmaps{
  public:
    Pixmaps();
    ~Pixmaps();

    static QImage*   get( const std::string &name );
    static QIcon     getIcon( const std::string &name);
    static QPixmap   getPm( const std::string &name);
    static Pixmaps& instance();

    void add(QString file, std::string key);
  private:
    typedef std::map<std::string, QImage*>  Data;
    Data data;

    static Pixmaps* inst;

  };

#endif // PIXMAPS_H
