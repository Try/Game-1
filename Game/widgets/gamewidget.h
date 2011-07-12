#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include <QVector>
#include "glwidget.h"

namespace Ui {
    class GameWidget;
}

class MiniMap;
class BuildButton;

class GameWidget : public GLWidget{
    Q_OBJECT
  public:
    explicit GameWidget(MainWindow *w, QWidget *parent = 0);
    ~GameWidget();

  public slots:
    void setPlIDE();

    void showIDE(bool);

    void showEditorGoroup( const QString& str );

    void setPauseIde(bool);

		void groundDown();
		void groundUp();
		void groundNo();

		void setTailToDraw(int id, int size);
		void setTailToDraw(int id);
		void setTailWidth (int size);

		void setStdTail_Grass(){ setTailToDraw(2); }
		void setStdTail_Sand (){ setTailToDraw(1); }
	private:
		Ui::GameWidget *ui;
		void resizeEvent(QResizeEvent *);

    void buildButtons();
    void ideEvents();

    float dHeight;
    struct {
      int id, size;
      } tail;

    MiniMap*         miniMap;

    QVector<BuildButton*> btns;

    void loadIcons();
    void displayDipCount( size_t, size_t, size_t  );

    struct {
      int framesCount,
          time;
      } fpsCounter;
};

#endif // GAMEWIDGET_H
