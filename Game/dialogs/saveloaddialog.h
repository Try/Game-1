#ifndef SAVELOADDIALOG_H
#define SAVELOADDIALOG_H

#include <QDialog>

namespace Ui {
    class SaveLoadDialog;
}

class QListWidgetItem;
class QMainWindow;

class SaveLoadDialog : public QDialog {
    Q_OBJECT
  public:
    explicit SaveLoadDialog(bool& re, QWidget *parent = 0);
    ~SaveLoadDialog();

    static bool save();
    static bool load();

  private slots:
    void click( QListWidgetItem* str );
    void action( QListWidgetItem* str );
    void action();
  private:
    Ui::SaveLoadDialog *ui;

    bool isLoad;
    bool &ret;

    void serialize( QString );
  };

#endif // SAVELOADDIALOG_H
