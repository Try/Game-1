#include <QtGui/QApplication>
#include "mainwindow.h"

#include <QDebug>
#include "style/norwegianwoodstyle.h"

int main(int argc, char *argv[])
{
		QApplication a(argc, argv);
		QApplication::setStyle(new NorwegianWoodStyle);

		MainWindow w;
		w.show();

		return a.exec();
}
