#ifndef STABLESET_H
#define STABLESET_H

#include <vector>

template< class T >
class StableSet {
  public:
    StableSet(){}

    typedef typename std::vector<T>::iterator iterator;
    iterator begin(){
      return data.begin();
      }

    iterator end(){
      return data.end();
      }

    int size(){
      return data.size();
      }

    void insert( T &obj ){
      data.push_back(obj);
      }

    void erase( T &obj ){
      for(size_t i=0; i<data.size(); ){
        if( data[i]==obj ){
          data[i] = data.back();
          data.pop_back();
          } else{
          ++i;
          }
        }
      }

  private:
    std::vector<T> data;
  };

#endif // STABLESET_H
