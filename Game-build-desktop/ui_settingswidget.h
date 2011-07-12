/********************************************************************************
** Form generated from reading UI file 'settingswidget.ui'
**
** Created
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSWIDGET_H
#define UI_SETTINGSWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingsWidget
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_6;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_8;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_2;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_7;
    QCheckBox *windowMode;
    QCheckBox *virtualTexture;
    QCheckBox *bloom;
    QCheckBox *fog;
    QCheckBox *grass;
    QCheckBox *ssao;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *useShadow;
    QSlider *shadowQuality;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QDoubleSpinBox *cameraSpeed;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QSpinBox *messageShowTime;
    QSpacerItem *verticalSpacer_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *okButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *cansel;

    void setupUi(QWidget *SettingsWidget)
    {
        if (SettingsWidget->objectName().isEmpty())
            SettingsWidget->setObjectName(QString::fromUtf8("SettingsWidget"));
        SettingsWidget->resize(329, 408);
        verticalLayout = new QVBoxLayout(SettingsWidget);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox_3 = new QGroupBox(SettingsWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        verticalLayout_6 = new QVBoxLayout(groupBox_3);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        tabWidget = new QTabWidget(groupBox_3);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_8 = new QVBoxLayout(tab);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        widget_2 = new QWidget(tab);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        verticalLayout_2 = new QVBoxLayout(widget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupBox_2 = new QGroupBox(widget_2);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_9 = new QVBoxLayout(groupBox_2);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_9->addWidget(label_2);


        verticalLayout_2->addWidget(groupBox_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        groupBox_4 = new QGroupBox(widget_2);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        verticalLayout_7 = new QVBoxLayout(groupBox_4);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        windowMode = new QCheckBox(groupBox_4);
        windowMode->setObjectName(QString::fromUtf8("windowMode"));

        verticalLayout_7->addWidget(windowMode);

        virtualTexture = new QCheckBox(groupBox_4);
        virtualTexture->setObjectName(QString::fromUtf8("virtualTexture"));

        verticalLayout_7->addWidget(virtualTexture);

        bloom = new QCheckBox(groupBox_4);
        bloom->setObjectName(QString::fromUtf8("bloom"));

        verticalLayout_7->addWidget(bloom);

        fog = new QCheckBox(groupBox_4);
        fog->setObjectName(QString::fromUtf8("fog"));

        verticalLayout_7->addWidget(fog);

        grass = new QCheckBox(groupBox_4);
        grass->setObjectName(QString::fromUtf8("grass"));

        verticalLayout_7->addWidget(grass);

        ssao = new QCheckBox(groupBox_4);
        ssao->setObjectName(QString::fromUtf8("ssao"));

        verticalLayout_7->addWidget(ssao);


        verticalLayout_3->addWidget(groupBox_4);

        groupBox = new QGroupBox(widget_2);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout_3 = new QHBoxLayout(groupBox);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, -1, -1, 12);
        useShadow = new QCheckBox(groupBox);
        useShadow->setObjectName(QString::fromUtf8("useShadow"));

        horizontalLayout_3->addWidget(useShadow);

        shadowQuality = new QSlider(groupBox);
        shadowQuality->setObjectName(QString::fromUtf8("shadowQuality"));
        shadowQuality->setMaximum(2);
        shadowQuality->setPageStep(1);
        shadowQuality->setOrientation(Qt::Horizontal);
        shadowQuality->setTickPosition(QSlider::TicksBothSides);
        shadowQuality->setTickInterval(1);

        horizontalLayout_3->addWidget(shadowQuality);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_3->addWidget(label);


        verticalLayout_3->addWidget(groupBox);


        verticalLayout_2->addLayout(verticalLayout_3);

        verticalSpacer = new QSpacerItem(20, 200, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        verticalLayout_8->addWidget(widget_2);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout_5 = new QVBoxLayout(tab_2);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        groupBox_5 = new QGroupBox(tab_2);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        verticalLayout_4 = new QVBoxLayout(groupBox_5);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(-1, -1, -1, 9);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_3 = new QLabel(groupBox_5);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_4->addWidget(label_3);

        cameraSpeed = new QDoubleSpinBox(groupBox_5);
        cameraSpeed->setObjectName(QString::fromUtf8("cameraSpeed"));
        cameraSpeed->setMinimum(0.01);
        cameraSpeed->setSingleStep(0.01);

        horizontalLayout_4->addWidget(cameraSpeed);


        verticalLayout_4->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(-1, -1, -1, 7);
        label_4 = new QLabel(groupBox_5);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_5->addWidget(label_4);

        messageShowTime = new QSpinBox(groupBox_5);
        messageShowTime->setObjectName(QString::fromUtf8("messageShowTime"));
        messageShowTime->setMaximum(999);
        messageShowTime->setSingleStep(5);
        messageShowTime->setValue(20);

        horizontalLayout_5->addWidget(messageShowTime);


        verticalLayout_4->addLayout(horizontalLayout_5);


        verticalLayout_5->addWidget(groupBox_5);

        verticalSpacer_2 = new QSpacerItem(20, 168, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_2);

        tabWidget->addTab(tab_2, QString());

        verticalLayout_6->addWidget(tabWidget);

        widget = new QWidget(groupBox_3);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        okButton = new QPushButton(widget);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(okButton->sizePolicy().hasHeightForWidth());
        okButton->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(okButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        cansel = new QPushButton(widget);
        cansel->setObjectName(QString::fromUtf8("cansel"));
        sizePolicy.setHeightForWidth(cansel->sizePolicy().hasHeightForWidth());
        cansel->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(cansel);


        verticalLayout_6->addWidget(widget);


        verticalLayout->addWidget(groupBox_3);


        retranslateUi(SettingsWidget);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SettingsWidget);
    } // setupUi

    void retranslateUi(QWidget *SettingsWidget)
    {
        SettingsWidget->setWindowTitle(QApplication::translate("SettingsWidget", "Settings", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("SettingsWidget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Serif'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">\320\230\320\267\320\274\320\265\320\275\320\265\320\275\320\270\321\217 \320\262\321\201\321\202\321\203\320\277\321\217\321\202 \320\262 \321\201\320\270\320\273\321\203</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">\320\277\320\276\321\201\320\273\320\265 \320\277\320\265\321\200\320\265\320\267\320\260\320\277\321\203\321\201\320\272\320\260 \320\270\320\263\321\200\321\213"
                        "!</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        windowMode->setText(QApplication::translate("SettingsWidget", "\320\236\320\272\320\276\320\275\320\275\321\213\320\271 \321\200\320\265\320\266\320\270\320\274", 0, QApplication::UnicodeUTF8));
        virtualTexture->setText(QApplication::translate("SettingsWidget", "\320\222\320\270\321\200\321\202\321\203\320\260\320\273\321\214\320\275\321\213\320\265 \321\202\320\265\320\272\321\201\321\202\321\203\321\200\321\213", 0, QApplication::UnicodeUTF8));
        bloom->setText(QApplication::translate("SettingsWidget", "\320\221\320\273\321\203\320\274 \321\215\321\204\320\265\320\272\321\202", 0, QApplication::UnicodeUTF8));
        fog->setText(QApplication::translate("SettingsWidget", "\320\242\321\203\320\274\320\260\320\275", 0, QApplication::UnicodeUTF8));
        grass->setText(QApplication::translate("SettingsWidget", "\320\242\321\200\320\260\320\262\320\260", 0, QApplication::UnicodeUTF8));
        ssao->setText(QApplication::translate("SettingsWidget", "SSAO", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("SettingsWidget", "\320\242\320\265\320\275\320\270", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("SettingsWidget", "\320\223\321\200\320\260\321\204\320\270\320\272\320\260", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("SettingsWidget", "\320\241\320\272\320\276\321\200\320\276\321\201\321\202\321\214 \320\277\321\200\320\276\320\272\321\200\321\203\321\202\320\272\320\270 \321\215\320\272\321\200\320\260\320\275\320\260", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("SettingsWidget", "\320\222\321\200\320\265\320\274\321\217 \320\276\321\202\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\321\217 \321\201\320\276\320\276\320\261\321\211\320\265\320\275\320\270\321\217", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("SettingsWidget", "\320\230\320\263\321\200\320\260", 0, QApplication::UnicodeUTF8));
        okButton->setText(QApplication::translate("SettingsWidget", "OK", 0, QApplication::UnicodeUTF8));
        cansel->setText(QApplication::translate("SettingsWidget", "Cansel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SettingsWidget: public Ui_SettingsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSWIDGET_H
