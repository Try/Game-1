#ifndef SETTINGSWIDGET_H
#define SETTINGSWIDGET_H

#include <QDialog>

namespace Ui {
    class SettingsWidget;
}

class SettingsWidget : public QDialog {
    Q_OBJECT
  public:
    explicit SettingsWidget(QWidget *parent = 0);
    ~SettingsWidget();

    class SettingsData{
      public:
        bool virtualTexture, bloom, fog, shadows, grass, ssao, windowMode;
        int  shadowQuality, messageShowTime;
        float cameraSpeed;
      };

    static SettingsData settings;

    static void load();
    static void save();

  public slots:
    void okSettings();
    void cansel();

    void upsetWidget();
    void upsetData();
  private:
    Ui::SettingsWidget *ui;

    static void load( const QString &file );

    class Parser;
    class Data;
    Data *data;
  };

#endif // SETTINGSWIDGET_H
