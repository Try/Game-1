#include "manwidget.h"
#include "ui_manwidget.h"

#include "runtime/gameclasses.h"
#include "runtime/gameobjectclass.h"

#include <QDebug>
#include <set>

#include "widgets/showwidget.h"

std::string ManWidget::filters[] = {
    "unit",
    "building"
    };

ManWidget::ManWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ManWidget) {
    ui->setupUi(this);

    update( filters[0] );

    connect( ui->groups, SIGNAL(currentIndexChanged(int)),
             this, SLOT(updateEvent(int)) );
    connect( ui->unitsList,
             SIGNAL(currentItemChanged(QListWidgetItem*,QListWidgetItem*)),
             this, SLOT(showHelp(QListWidgetItem*)) );

    priviewWidget = new ShowWidget();
    priviewWidget->setImage("./helpSys/game.png");
    ui->layShow->addWidget( priviewWidget );
    }

ManWidget::~ManWidget(){
    deleteBtns();
    delete ui;
    }

void ManWidget::deleteBtns(){
    for(int i=0; i<btns.size(); ++i)
      delete btns[i];
    btns.clear();
    }

void ManWidget::addUnitButton( QLayout *l,
                               const std::string &name ){
    QPushButton *btn = new QPushButton();
    l->addWidget(btn);

    btns.push_back( btn );

    btn->setMinimumSize(50, 50);
    btn->setMaximumSize(50, 50);
    btn->setIconSize( QSize(45,45) );

    const GameObjectClass *c = GameClasses::get( name );
    if(c)
      btn->setIcon( c->icon );
    }

void ManWidget::showHelp(QListWidgetItem* item){
    if( !item )
      return;

    const GameObjectClass *c = GameClasses::get( item->text().toStdString() );

    priviewWidget->setImage( c->priviewFile );

    ui->priview->setIcon( c->icon );
    ui->text->setText( c->hint );
    ui->speed->setText( QString::number( c->speed ) );

    ui->hp->setText( QString::number( c->maxHp ) );
    ui->damage->setText( QString::number( c->atack.land_land.damage ) );
    ui->atkTime->setText( QString::number( c->atack.land_land.time ) );

    ui->cost     ->setText( QString::number( c->cost.gold ) );
    if( c->cost.lim < 0){
      ui->houses   ->setText( "+"+QString::number( -c->cost.lim ));
      } else {
      ui->houses   ->setText( QString::number( c->cost.lim  ) );
      }
    ui->buildTime->setText( QString::number( c->buildTime ) );

    deleteBtns();
    for(unsigned i=0; i<c->recruts.size(); ++i){
      addUnitButton( ui->layRecruts, c->recruts[i].name );
      }

    std::set<std::string> hKeys;

    for(size_t i=0; i<GameClasses::classes().size(); ++i){
      const GameObjectClass *cl = GameClasses::classes()[i];

      for(unsigned r=0; r<cl->recruts.size(); ++r){
        if( cl->recruts[r].name==c->name ){
          addUnitButton( ui->layOwners, cl->name );
          //hKey.append( cl->recruts[r].hotKey.data() );
          hKeys.insert( cl->recruts[r].hotKey );
          //hKey.append(", ");
          }
        }

      }

    QString hKey = "[";
    for(std::set<std::string>::iterator i=hKeys.begin(); i!=hKeys.end(); ++i){
      hKey.append( i->data() );
      }
    hKey.append("]");

    ui->hKey->setText(hKey);
    }

void ManWidget::updateEvent( int item ){
    update( filters[item] );
    }

void ManWidget::showEvent(QShowEvent *){
    //update(0);
    }

void ManWidget::update( const std::string &group ){
    ui->unitsList->clear();

    for(size_t i=0; i<GameClasses::classes().size(); ++i){
      // qDebug() <<  GameClasses::classes()[i]->group.data();
      if( GameClasses::classes()[i]->group==group &&
          GameClasses::classes()[i]->view.data != "no_view" ){
        QListWidgetItem *item =
            new QListWidgetItem(GameClasses::classes()[i]->name.data());
        item->setIcon( GameClasses::classes()[i]->icon );

        ui->unitsList->addItem( item );
        }
      }
    }
