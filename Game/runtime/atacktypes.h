#ifndef ATACKTYPES_H
#define ATACKTYPES_H

#include <string>
#include <map>
#include <algorithm>
#include <vector>

#include "dataCtrl/filestream.h"

class AtackTypes {
  public:
    AtackTypes();

    static AtackTypes& instance();

    void add( const std::string& e, const std::string& r,
              double val );

    class ArmoType{
      public:
        ArmoType():id(0){}
      private:
        int id;
        friend class AtackTypes;
      };

    class AtkType{
      public:
        AtkType():id(0){}
      private:
        int id;
        friend class AtackTypes;
      };

    template< class T >
    class AtkTypeSet{
      public:
        T& operator [] ( const AtkType& a ){
          if( a.id>=size() )
            return data[0];
          return data[ a.id ];
          }

        const T& operator [] ( const AtkType& a ) const{
          return data[ a.id ];
          }

        int size(){
          return data.size();
          }

        void resize(int s){
          data.resize(s);
          }

        void resize(){
          data.resize( AtackTypes::instance().emitterHash.size() );
          }

        void serialize( FileStream &f ){
          if( f.isIn() ){
            int s;
            f >> s;
            resize(s);
            } else {
            f << size();
            }

          for( int i=0; i<size(); ++i)
            f + data[i];
          }

      private:
        std::vector<T> data;
      };

    AtkType  getAtk ( const std::string& e );
    ArmoType getArmo( const std::string& e );

    static double get( const AtkType &, const ArmoType &);
  private:
    static AtackTypes * inst;

    typedef std::pair<int, int>         Key;
    typedef std::map <std::string, int> hMap;

    std::map< Key, double> data;

    std::map< std::string, int> emitterHash, reciverHash;
    int hash( const std::string& e, hMap& hMap );

    std::vector< std::vector<double> > atkMatrix;
  };

#endif // ATACKTYPES_H
