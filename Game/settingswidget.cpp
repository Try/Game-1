#include "settingswidget.h"
#include "ui_settingswidget.h"

SettingsWidget::SettingsData SettingsWidget::settings;


#include <QXmlInputSource>
#include <QXmlSimpleReader>

#include <QDebug>

#include <fstream>
#include "style/cursors.h"

using namespace std;

class SettingsWidget::Parser : public QXmlDefaultHandler {
  public:
    Parser(){
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

    bool extract(float &x, QString var, const QXmlAttributes &attrs){
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

    bool endElement( const QString&, const QString &, const QString & ){
      return true;
      }

    bool startElement( const QString& , const QString& , const QString &lname,
                       const QXmlAttributes &attrs ){
      if( 0 ){

        for( int i=0; i<attrs.count(); i++ ){
          qDebug() << lname <<" "<<attrs.localName( i ) <<" = " << attrs.value(i);
          }

        }

#define extract(X) extract( SettingsWidget::settings.X, \
                            #X, attrs )

      if( lname=="graphics" ){
        extract( virtualTexture );
        extract( bloom );
        extract( fog );
        extract( shadows );
        extract( shadowQuality );
        extract( grass );
        extract( ssao  );
        extract( windowMode );
        } else

      if( lname=="game" ){
        extract( messageShowTime );
        extract( cameraSpeed );
        }

      return true;
      }
#undef extract
  };

class SettingsWidget::Data{
  public:
    class IVariable{
      public:
        virtual ~IVariable(){}

        virtual void upsetWidget() = 0;
        virtual void upsetData()   = 0;
      };

    template< class Data, class View >
    class Variable:public IVariable{
      public:
        Variable(Data *pd, View *pv):d(pd), v(pv){
          // connect( v, SIGNAL())
          }

         void upsetWidget(){
           // v->setChecked(*d);
           upsetWidget(*d, v);
           }

         void upsetData(){
           //*d = v->isChecked();
           upsetData( *d, v);
           }
      private:
        Data *d;
        View *v;

        template< class T >
        void upsetWidget(bool d, T *v){
          v->setChecked(d);
          }

        template< class T >
        void upsetWidget(int d, T *v){
          v->setValue(d);
          }

        template< class T >
        void upsetWidget(float d, T *v){
          v->setValue(d);
          }

        template< class T >
        void upsetData(bool& d, T *v){
          d = v->isChecked();
          }

        template< class T >
        void upsetData(int& d, T *v){
          d = v->value();
          }

        template< class T >
        void upsetData(float& d, T *v){
          d = v->value();
          }
      };

    std::vector<IVariable*> variables;
    SettingsWidget *owner;

    ~Data(){
      for(size_t i = 0; i<variables.size(); ++i)
        delete variables[i];
      }

    template< class V>
    void addVariable(bool &d, V *v){
      variables.push_back( new Data::Variable<bool, V>(&d, v) );

      connect( v,     SIGNAL(clicked()),
               owner, SLOT(upsetData() ) );
      }

    template< class V>
    void addVariable(int &d, V *v){
      variables.push_back( new Data::Variable<int, V>(&d, v) );

      connect( v,     SIGNAL(sliderReleased()),
               owner, SLOT  (upsetData() ) );
      }

    template< class V>
    void addVariable(float &d, V *v){
      variables.push_back( new Data::Variable<float, V>(&d, v) );

      connect( v,     SIGNAL(editingFinished()),
               owner, SLOT  (upsetData() ) );
      }

    void addVariable(int &d, QSpinBox *v){
      variables.push_back( new Data::Variable<int, QSpinBox>(&d, v) );

      connect( v,     SIGNAL(editingFinished()),
               owner, SLOT  (upsetData() ) );
      }
  };

SettingsWidget::SettingsWidget(QWidget *parent) :
      QDialog(parent),
      ui(new Ui::SettingsWidget) {
    ui->setupUi(this);

    setCursor( Cursors::instance().main );

    data = new Data();
    data->owner = this;

    setWindowFlags( Qt::Tool | Qt::WindowTitleHint | Qt::FramelessWindowHint );
    setFocusPolicy(Qt::StrongFocus);
    setFocus();

    settings.bloom     = 0;
    settings.fog       = 0;
    settings.shadows   = 1;
    settings.shadowQuality  = 2;
    settings.virtualTexture = 1;
    settings.grass = 1;
    settings.windowMode = 1;

    data->addVariable( settings.bloom,   ui->bloom );
    data->addVariable( settings.fog  ,   ui->fog   );
    data->addVariable( settings.shadows, ui->useShadow );
    data->addVariable( settings.shadowQuality,   ui->shadowQuality   );
    data->addVariable( settings.virtualTexture,  ui->virtualTexture );
    data->addVariable( settings.grass,           ui->grass );
    data->addVariable( settings.ssao,            ui->ssao  );
    data->addVariable( settings.windowMode,      ui->windowMode  );

    data->addVariable( settings.cameraSpeed,      ui->cameraSpeed );
    data->addVariable( settings.messageShowTime,  ui->messageShowTime );


    connect( ui->okButton, SIGNAL(clicked()),
             this, SLOT(okSettings()) );

    connect( ui->cansel, SIGNAL(clicked()),
             this, SLOT(cansel()) );


    load();
    upsetWidget();
    }

SettingsWidget::~SettingsWidget() {
    delete ui;
    delete data;
    }

void SettingsWidget::upsetWidget(){
    for(size_t i=0; i<data->variables.size(); ++i){
      data->variables[i]->upsetWidget();
      }
    }

void SettingsWidget::upsetData(){
    for(size_t i=0; i<data->variables.size(); ++i){
      data->variables[i]->upsetData();
      }
    }

void SettingsWidget::okSettings(){
    save();
    close();
    }

void SettingsWidget::cansel(){
    close();
    }

void SettingsWidget::save(){
    fstream fout;
    fout.open("./settings/settings.xml", fstream::out );

    fout << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
    fout << "<!DOCTYPE GameSettings>" << endl << endl
         << "<settings>" << endl;

    fout << "  <graphics" << endl;
    fout << "    virtualTexture = \"" << settings.virtualTexture << '\"' << endl
         << "    bloom          = \"" << settings.bloom          << '\"' << endl
         << "    fog            = \"" << settings.fog            << '\"' << endl
         << "    shadows        = \"" << settings.shadows        << '\"' << endl
         << "    shadowQuality  = \"" << settings.shadowQuality  << '\"' << endl
         << "    windowMode     = \"" << settings.windowMode     << '\"' << endl
         << "    grass  = \"" << settings.grass  << '\"' << endl
         << "    ssao   = \"" << settings.ssao   << '\"' << endl
         << "    />" << endl << endl;

    fout << "  <game" << endl;
    fout << "    cameraSpeed     = \"" << settings.cameraSpeed << '\"' << endl
         << "    messageShowTime = \""
            << settings.messageShowTime << '\"' << endl
         << "    />" << endl << endl;

    fout << "</settings>" << endl;
    }

void SettingsWidget::load(){
    load("./settings/settings.xml");
    }

void SettingsWidget::load( const QString &f ){
    Parser handler;

    QFile file( f );
    QXmlInputSource source( &file );

    QXmlSimpleReader reader;
    reader.setContentHandler( &handler );

    reader.parse( source );
    }
