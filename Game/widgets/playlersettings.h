#ifndef PLAYLERSETTINGS_H
#define PLAYLERSETTINGS_H

#include <QWidget>
#include <QVector>

namespace Ui {
    class PlaylerSettings;
}

class PlaylerSettings : public QWidget
{
    Q_OBJECT

public:
    explicit PlaylerSettings(QWidget *parent = 0);
    ~PlaylerSettings();

    bool isUsed();
    bool isHuman();

    void setHuman();

    int level();
public slots:
    void onPlTypeChange();
private:
    Ui::PlaylerSettings *ui;

    static QVector<PlaylerSettings*> exemplars;
};

#endif // PLAYLERSETTINGS_H
