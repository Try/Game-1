#include "startffawidget.h"
#include "ui_startffawidget.h"

#include <QDir>

#include "widgets/mapfilewidget.h"

#include "widgets/playlersettings.h"

#include "dataCtrl/pixmaps.h"

StartFFAWidget::StartFFAWidget(QWidget *parent) :
                QWidget(parent),
                ui(new Ui::StartFFAWidget) {
    ui->setupUi(this);


    connect(ui->back_to_menu, SIGNAL(clicked()),
            this, SLOT(backToMenuSlot()));
    connect(ui->play, SIGNAL(clicked()),
            this, SLOT(startGameSlot()));

    priview = new MapFileWidget("", this);
    ui->priviewMap->addWidget( priview );

    ui->back_to_menu->setIcon( Pixmaps::getIcon("back") );

    updateDir();
    }

StartFFAWidget::~StartFFAWidget(){
    delete ui;
    }

void StartFFAWidget::createPlaylers(){
    QImage img;
    img.load( "./bmp/"+priview->name() );

    delPlaylers();
    for(int i=0; i<img.width(); ++i)
      for(int r=0; r<img.height(); ++r){
        if( QColor(img.pixel(i,r))==QColor(255,255,255) ){
          PlaylerSettings *p = new PlaylerSettings();

          plSettings.push_back( p );
          ui->layPlaylers->addWidget( p );

          if( plSettings.size()==8 ){
            i = img.width();
            r = img.height();
            }
          }
        }

    if( plSettings.size() )
      plSettings[0]->setHuman();
    }

void StartFFAWidget::delPlaylers(){
    for(size_t i=0; i<plSettings.size(); ++i)
      delete plSettings[i];
    plSettings.clear();
    }

void StartFFAWidget::upsetInform( MapFileWidget* m ){

    priview->set(m);
    ui->name->setText( m->name() );
    ui->size->setText( QString::number(m->image().width()) + "x" +
                       QString::number(m->image().height()) );
    createPlaylers();
    }

void StartFFAWidget::backToMenuSlot(){
    emit backToMenu();
    }

void StartFFAWidget::startGameSlot(){
    setCursor( Qt::WaitCursor  );

    if( priview ){
      emit backToMenu();

      std::vector<PlInfo> info;
      for(size_t i=0; i<plSettings.size(); ++i){
        info.push_back( PlInfo() );
        info.back().exist   = plSettings[i]->isUsed();
        info.back().isHuman = plSettings[i]->isHuman();
        info.back().level   = plSettings[i]->level();
        }

      emit startGame( "./bmp/" + priview->name(), info );
      }

    setCursor( Qt::ArrowCursor );
    }

void StartFFAWidget::updateDir(){
    QDir files("./bmp/");

    QStringList filter;
    filter.push_back("*.bmp");
    filter.push_back("*.png");

    QStringList sl = files.entryList( filter );


    int count = 4;//ui->maps->width()/128;
    for(int i=0; i<sl.size(); ++i){
      MapFileWidget *m = new MapFileWidget(sl[i], this);
      if( i==0 )
        upsetInform(m);
      ui->layMaps->addWidget( m, i/count, i%count );
      }

    }
