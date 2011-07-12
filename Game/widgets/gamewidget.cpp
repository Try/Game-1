#include "gamewidget.h"
#include "ui_gamewidget.h"

#include "unitsgroup.h"
#include "hud/unitavatar.h"
#include "hud/minimap.h"

#include <QPushButton>

class BuildButton:public QPushButton{
	public:
		BuildButton( GLWidget *gl,
								 QLayout *l,
								 std::string &s, std::string &g):
						QPushButton(),
						taget(s),
						group(g),
						glWidget(gl){
			l->addWidget(this);

			setText( QString(taget.data()) );
			setIcon( GameClasses::get( taget )->icon );

//			setMinimumSize( l->widget()->width()-8, 500 );
			}

		void mousePressEvent(QMouseEvent *e ){
			glWidget->addObject( taget );
			QPushButton::mousePressEvent( e );
			}

		std::string &taget;
		std::string &group;

		GLWidget *glWidget;
	};

GameWidget::GameWidget(MainWindow *w, QWidget *parent ) :
            GLWidget(w, parent),
            ui(new Ui::GameWidget){
    ui->setupUi(this);
    loadIcons();

    dHeight    = 0;
    tail.size  = 0;
    tail.id    = 0;

    fpsCounter.framesCount = 0;
    fpsCounter.time        = 0;

		ui->unitsLay->addWidget( new UnitsGroup(this) );
		ui->unitAvatarLayout->addWidget( new UnitAvatar() );


		miniMap = new MiniMap();
		ui->layMiniMap->addWidget( miniMap );

		setLayCtrl( ui->layControl );

		showIDE(0);
		buildButtons();

		ui->pause->setIcon( Pixmaps::getIcon("pause") );
		connect(ui->pause, SIGNAL(clicked(bool)),
						this, SLOT(setPauseIde(bool)) );

		connect( ui->useSnap, SIGNAL(toggled(bool)),
						 this,       SLOT(useSnap(bool)) );

		connect( ui->groups, SIGNAL(currentIndexChanged(QString)),
						 this, SLOT(showEditorGoroup( const QString& ) ) );

		connect( ui->groups, SIGNAL(currentIndexChanged(QString)),
						 this, SLOT(showEditorGoroup( const QString& ) ) );

		connect(ui->curPl, SIGNAL(currentIndexChanged(int)),
						this, SLOT(setPlIDE()) );


		connect( ui->groundUp, SIGNAL(clicked()),
						 this,        SLOT  (groundUp()) );
		connect( ui->groundDown, SIGNAL(clicked()),
						 this,          SLOT  (groundDown()) );
		connect( ui->groundNo, SIGNAL(clicked()),
						 this,        SLOT  (groundNo()) );

		connect( ui->brushSize, SIGNAL(valueChanged(int)),
						 this, SLOT(setTailWidth(int)));

		connect( ui->setGrass, SIGNAL(clicked()),
						 this, SLOT(setStdTail_Grass()));
		connect( ui->setSand, SIGNAL(clicked()),
						 this, SLOT(setStdTail_Sand()));
		// setTailToDraw(1, 2);
		}

GameWidget::~GameWidget(){
    delete ui;
    }

void GameWidget::loadIcons(){
    ui->groundNo->  setIcon( QIcon("./pixmaps/cursor.png") );
    ui->groundUp->  setIcon( QIcon("./pixmaps/mountains_up.png") );
    ui->groundDown->setIcon( QIcon("./pixmaps/mountains_down.png") );

    ui->ideBox->setTabIcon(0, QIcon("./pixmaps/models.png") );
    ui->ideBox->setTabIcon(1, QIcon("./pixmaps/mountains.png") );

    ui->pause->setIcon( QIcon("./pixmaps/pause.png") );
    }


void GameWidget::resizeEvent(QResizeEvent *e){
    //ui->verticalLayout_3->setContentsMargins(4, height()-210, 4, 4 );
    ui->mainSpacer->setGeometry( QRect(
                                   0, 0,
                                   ui->mainSpacer->geometry().width(),
                                   height()-210) );

    GLWidget::resizeEvent(e);
    }


void GameWidget::buildButtons(){
		QSet< QString > setStr;
		ui->groups->addItem( "All" );
		setStr.insert( "All" );

		for(unsigned i=0; i<GameClasses::classes().size(); ++i){
			if( GameClasses::classes()[i]->view.data != "no_view"){
				BuildButton * btn =
					new BuildButton( this,
													 ui->buildButtonsLayout,
													 GameClasses::classes()[i]->name,
													 GameClasses::classes()[i]->group );
				btns.push_back( btn );
				// btn->setMaximumWidth( ui->buttonsBox->width()+8 );
				QString sItem = GameClasses::classes()[i]->group.data();

				if( !setStr.contains( sItem ) ){
					ui->groups->addItem( sItem );
					setStr.insert( sItem );
					}
				}
			}

		}

void GameWidget::setPauseIde(bool pause){
		if( pause )
			ui->pause->setIcon( Pixmaps::getIcon("run") ); else
			ui->pause->setIcon( Pixmaps::getIcon("pause") );

		Game::instance().setPause( pause );
		}


void GameWidget::showIDE(bool ok){
		if( ok )
			ui->groupIdeBox->show(); else
			ui->groupIdeBox->hide();

		groundNo();
		}

void GameWidget::setPlIDE(){
		curIdePl = ui->curPl->currentIndex();
		}

void GameWidget::showEditorGoroup( const QString& str ){
		if( str=="All" ){
			for(int i=0; i<btns.size(); ++i){
				btns[i]->show();
				}
			} else {
			for(int i=0; i<btns.size(); ++i){
				if( str==btns[i]->group.data() )
					btns[i]->show(); else
					btns[i]->hide();
				}
			}
		}



void GameWidget::groundDown(){
		dHeight = -1;
		}

void GameWidget::groundUp(){
		dHeight = 1;
		}

void GameWidget::groundNo(){
		dHeight   = 0;
		tail.size = 0;
		}

void GameWidget::setTailToDraw(int id){
		tail.id = id;
		}

void GameWidget::setTailWidth (int size){
		groundNo();

		tail.size = size;
		}

void GameWidget::setTailToDraw(int id, int size){
		groundNo();

		tail.id   = id;
		tail.size = size;
		}

void GameWidget::ideEvents(){
		if( GLObject::ideObject )
			groundNo();

		if( tail.size && isMousePressed )
			game.map.drawTail(tail.id,
												mouseCoordsF[0],
												mouseCoordsF[1],
												tail.size);

		if( isMousePressed ){
			if( dHeight ) {
				game.setDHeight( mouseCoords[0],
												 mouseCoords[1],
												 dHeight*0.025, 8 );
				}
			}
		}

void GameWidget::displayDipCount( size_t  dip, size_t dt, size_t b ){
		++fpsCounter.framesCount;
		fpsCounter.time += dt;

		float fps = 1000.0*fpsCounter.framesCount/fpsCounter.time;

		ui->dipCount ->setText( "dipCount = " + QString::number(dip) );
		ui->fps      ->setText( "FPS = " + QString::number(fps) );
		ui->deltaTime->setText( "dt = " + QString::number(dt) );
		ui->bathCount->setText( "bachCount = " + QString::number(b) );

		if( fpsCounter.time>1000 ){
			fpsCounter.framesCount = 0;
			fpsCounter.time = 0;
			}
		}
