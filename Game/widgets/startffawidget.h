#ifndef STARTFFAWIDGET_H
#define STARTFFAWIDGET_H

#include <QWidget>
#include <vector>

namespace Ui {
    class StartFFAWidget;
}

class MapFileWidget;
class PlaylerSettings;

class StartFFAWidget : public QWidget
{
    Q_OBJECT

public:
    explicit StartFFAWidget(QWidget *parent = 0);
    ~StartFFAWidget();

    void upsetInform( MapFileWidget* );

    struct PlInfo{
      bool exist;
      bool isHuman;
      int  level;
      };


signals:
  void backToMenu();
  void startGame( QString mapfile, std::vector<StartFFAWidget::PlInfo> &info );

private slots:
  void backToMenuSlot();
  void startGameSlot();

  void updateDir();
private:
    Ui::StartFFAWidget *ui;
    MapFileWidget *priview;
    std::vector< PlaylerSettings* > plSettings;

    void createPlaylers();
    void delPlaylers();
};

#endif // STARTFFAWIDGET_H
