#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "widgets/startffawidget.h"
#include "runtime/hotkeys.h"

namespace Ui {
		class MainWindow;
}

class GLWidget;

class ManWidget;
class MiniMap;
class StartFFAWidget;

#include "style/cursors.h"
class MainWindow : public QMainWindow{
		Q_OBJECT

	public:
		explicit MainWindow(QWidget *parent = 0);
		~MainWindow();

		Ui::MainWindow *gui();

		bool isInGame();
	private slots:
		void resetSelection();
		void upsetObjectData();
		//void setPlIDE();

		//void showIDE(bool);

		//void showEditorGoroup( const QString& str );

		void autors();
		void playMultiplayler();
		void startDemo( QString mapfile, std::vector<StartFFAWidget::PlInfo>& info );

		void showSettings();

		void save();
		void load();

		//void setPause(bool);

		void showMainMenu();

	private:
		void paintEvent(QPaintEvent *);

	private:
		Ui::MainWindow *ui;
		GLWidget * widGl;
		ManWidget *widMan;

		StartFFAWidget*  startFFA;

		void buildButtons();
		void initIdeCtrls();

		HotKeys hotKeys;
		Cursors m_cursors;
	};

#endif // MAINWINDOW_H
