#ifndef LOG_H
#define LOG_H

#include <fstream>

class Log {
  public:
    Log();
    ~Log();

    template< class T >
    Log& operator << ( const T& t){
      fout << t;
      return *this;
      }

    static std::fstream& outStream();
  private:
    static std::fstream fout;
  };

#endif // LOG_H
