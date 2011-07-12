#include "saveloaddialog.h"
#include "ui_saveloaddialog.h"

#include <QDir>
#include <QDebug>

#include "game/game.h"

#include "style/cursors.h"

SaveLoadDialog::SaveLoadDialog(bool& re, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SaveLoadDialog),
    ret(re) {

    ui->setupUi(this);

    setCursor( Cursors::instance().main );
    ret = 0;

    setFocusPolicy(Qt::StrongFocus);
    setFocus();

    setWindowFlags( Qt::Tool | Qt::WindowTitleHint | Qt::FramelessWindowHint );

    connect(ui->cansel, SIGNAL(clicked()),
            this, SLOT(close()) );

    QDir files("./save/");

    QStringList filter;
    filter.push_back("*.sav");
    filter.push_back("*.map");

    QStringList sl = files.entryList( filter );

    ui->files->addItems( sl );

    connect(ui->files, SIGNAL(itemClicked(QListWidgetItem*)),
            this, SLOT(click(QListWidgetItem*)));
    connect(ui->files, SIGNAL(itemDoubleClicked(QListWidgetItem*)),
            this, SLOT(action(QListWidgetItem*)));

    connect(ui->fname, SIGNAL(returnPressed()),
            this, SLOT(action()));
    connect(ui->action, SIGNAL(clicked()),
            this, SLOT(action()));
    }

SaveLoadDialog::~SaveLoadDialog(){
    delete ui;
    }

bool SaveLoadDialog::save(){
		bool ok;
		SaveLoadDialog* dlg = new SaveLoadDialog(ok);

		dlg->ui->caption->setText("Save Game");
		dlg->ui->action->setText("Save");
		dlg->ui->mapFormat->setVisible(1);
		dlg->isLoad = 0;

		dlg->exec();
		delete dlg;

		return ok;
		}

bool SaveLoadDialog::load(){
		bool ok;
		SaveLoadDialog* dlg = new SaveLoadDialog(ok);

		dlg->ui->caption->setText("Load Game");
		dlg->ui->action->setText("Load");
		dlg->ui->mapFormat->setVisible(0);
		dlg->isLoad = 1;

		dlg->exec();
		delete dlg;

		return ok;
		}

void SaveLoadDialog::click( QListWidgetItem* item ){
		ui->fname->setText( item->text() );
		}

void SaveLoadDialog::action( QListWidgetItem* item ){
		//qDebug() << item->text();
		ui->fname->setText( item->text() );
		serialize( item->text() );
		}

void SaveLoadDialog::action(){
		//qDebug() << ui->fname->text();
		serialize( ui->fname->text() );
		}

void SaveLoadDialog::serialize( QString str){
		if( !str.endsWith(".sav" ) &&
				!str.endsWith(".map" ) ){
			if( ui->mapFormat->isChecked() )
				str.append( ".map" ); else
				str.append( ".sav" );
			}

		bool ok = 0;
		if( !str.endsWith(".map") ){
			ok =  Game::instance().
							serialize   (("./save/"+str).toStdString(), isLoad);
			} else {
			ok =  Game::instance().
							serializeMap(("./save/"+str).toStdString(), isLoad);
			}

		if( ok ){
			ret = 1;
			close();
			}
		}
