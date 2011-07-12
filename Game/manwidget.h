#ifndef MANWIDGET_H
#define MANWIDGET_H

#include <QWidget>
#include <string>

namespace Ui {
    class ManWidget;
}

class QListWidgetItem;
class QPushButton;

class ShowWidget;

class ManWidget : public QWidget {
    Q_OBJECT
  public:
    explicit ManWidget(QWidget *parent = 0);
    ~ManWidget();

  public slots:
    void updateEvent( int );
    void showHelp( QListWidgetItem* );

  private:
    Ui::ManWidget *ui;

    static std::string filters[];

    void update( const std::string &group );

    void showEvent(QShowEvent *);

    QVector< QPushButton* > btns;
    void deleteBtns();

    void addUnitButton( QLayout *l, const std::string &name );
    ShowWidget *priviewWidget;
  };

#endif // MANWIDGET_H
