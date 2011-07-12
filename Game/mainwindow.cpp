#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "glwidget.h"

#include "runtime/gameclasses.h"

#include <QPushButton>
#include <QMouseEvent>

#include <QSet>

#include "manwidget.h"
#include "dataCtrl/pixmaps.h"

#include <QMessageBox>

#include "runtime/gameclasses.h"
#include "settingswidget.h"
#include "widgets/startffawidget.h"


#include "dialogs/saveloaddialog.h"
#include "widgets/gamewidget.h"

MainWindow::MainWindow(QWidget *parent) :
						QMainWindow(parent),
						ui(new Ui::MainWindow) {
						ui->setupUi(this);

		SettingsWidget::load();
		widGl = new GameWidget( this );

		ui->layGl->addWidget( widGl );

		// ui->unitsLay->addWidget( new UnitsGroup(this) );

		widMan = new ManWidget();
		ui->manLayout->addWidget(widMan);


		startFFA = new StartFFAWidget();
		ui->startFFALayout->addWidget( startFFA );

		connect(ui->play,  SIGNAL(clicked(bool)),
						this, SLOT(playMultiplayler()) );
		connect(ui->autor, SIGNAL(clicked(bool)),
						this, SLOT(autors()) );
		connect(ui->exit,  SIGNAL(clicked(bool)),
						this, SLOT(close()) );
		connect(ui->settings,  SIGNAL(clicked(bool)),
						this, SLOT(showSettings()) );

		connect( startFFA, SIGNAL(backToMenu()),
						this, SLOT(showMainMenu()) );
		connect( startFFA,
						 SIGNAL(startGame(QString, std::vector<StartFFAWidget::PlInfo>&)),
						 this,
						 SLOT(startDemo(QString, std::vector<StartFFAWidget::PlInfo>&)) );



		connect(ui->save, SIGNAL(clicked(bool)),
						this, SLOT(save()) );
		connect(ui->load, SIGNAL(clicked(bool)),
						this, SLOT(load()) );

		connect(ui->showIDE, SIGNAL(clicked(bool)),
						widGl, SLOT( showIDE(bool) ) );

		initIdeCtrls();

		ui->gameTabs->setCurrentIndex(0);

		setCursor( Cursors::instance().main );

    if( SettingsWidget::settings.windowMode )
      showMaximized();  else
      showFullScreen();
    }

MainWindow::~MainWindow(){
		delete widMan;
		delete startFFA;
		delete widGl;
		delete ui;

		AbstractBehavior::free();
		}


void MainWindow::playMultiplayler(){
		ui->mainPages->setCurrentIndex(1);
		}

void MainWindow::showMainMenu(){
		ui->mainPages->setCurrentIndex(0);
		}

void MainWindow::save(){
		if( widGl->save() )
			ui->gameTabs->setCurrentIndex(1);
		}

void MainWindow::load(){
		if( widGl->load() )
			ui->gameTabs->setCurrentIndex(1);
		}

void MainWindow::autors(){
		QMessageBox m;
		m.setText("Try from 'GameDev.ru'");

		m.exec();
		}

void MainWindow::showSettings(){
		SettingsWidget s(this);
		s.exec();
		}

void MainWindow::startDemo( QString mapFile,
														std::vector<StartFFAWidget::PlInfo>& info ){
		ui->gameTabs->setCurrentIndex(1);
		widGl->startDemo( mapFile, info );
		}

Ui::MainWindow *MainWindow::gui(){
		return ui;
		}

void MainWindow::initIdeCtrls(){

		}

void MainWindow::resetSelection(){
		widGl->addObject( "" );
		}

bool MainWindow::isInGame(){
		return ui->gameTabs->currentIndex()==1;
		}

void MainWindow::upsetObjectData(){
		}

void MainWindow::paintEvent(QPaintEvent *){
		QPainter p(this);

		p.setBrush( Qt::black );
		p.setPen  ( Qt::black );
		p.drawRect( 0, 0, 50, height() );
		}
