#include "playlersettings.h"
#include "ui_playlersettings.h"

QVector<PlaylerSettings*> PlaylerSettings::exemplars;

PlaylerSettings::PlaylerSettings(QWidget *parent) :
                  QWidget(parent),
                  ui(new Ui::PlaylerSettings){
    ui->setupUi(this);
    exemplars.push_back(this);

    ui->plLabel->setText( ui->plLabel->text() +
                          QString::number(exemplars.size()) );

    connect(ui->isHuman,SIGNAL(currentIndexChanged(int)),
            this, SLOT( onPlTypeChange() ));

    onPlTypeChange();
    }

void PlaylerSettings::setHuman(){
    ui->isHuman->setCurrentIndex(0);
    }

PlaylerSettings::~PlaylerSettings(){
    delete ui;

    for( int i=0; i<exemplars.size(); ++i){
      if( exemplars[i]==this ){
        exemplars.remove(i);
        return;
        }
      }
    }

bool PlaylerSettings::isUsed(){
    return ui->used->isChecked();
    }

bool PlaylerSettings::isHuman(){
    return (ui->isHuman->currentIndex()==0);
    }

int PlaylerSettings::level(){
    return ui->ai_level->currentIndex();
    }

void PlaylerSettings::onPlTypeChange(){
    if( ui->isHuman->currentIndex()==0 ){
      ui->ai_level->setEnabled(0);
      ui->botSettings->setCurrentIndex(1);
      ui->ai_level->setCurrentIndex(1);
      } else {
      ui->ai_level->setEnabled(1);
      ui->botSettings->setCurrentIndex(0);
      }

    if( ui->isHuman->currentIndex()==0 )
      for(int i=0; i<exemplars.size(); ++i){
        if( exemplars[i]->ui->isHuman->currentIndex()==0 &&
            exemplars[i] != this ){
          exemplars[i]->ui->isHuman->setCurrentIndex(1);
          }
        }
    }
