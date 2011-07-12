/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStackedWidget>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QTabWidget *gameTabs;
    QWidget *tab_3;
    QHBoxLayout *horizontalLayout_15;
    QStackedWidget *mainPages;
    QWidget *menuPage;
    QHBoxLayout *horizontalLayout_20;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_13;
    QSpacerItem *verticalSpacer_3;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_12;
    QPushButton *play;
    QPushButton *load;
    QHBoxLayout *horizontalLayout_17;
    QPushButton *save;
    QPushButton *autor;
    QPushButton *settings;
    QPushButton *exit;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_8;
    QCheckBox *showIDE;
    QSpacerItem *horizontalSpacer_2;
    QWidget *startGamePage;
    QHBoxLayout *horizontalLayout_21;
    QVBoxLayout *startFFALayout;
    QWidget *tab;
    QVBoxLayout *verticalLayout;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_6;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_23;
    QVBoxLayout *layGl;
    QWidget *tab_2;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *manLayout;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(755, 555);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        gameTabs = new QTabWidget(centralWidget);
        gameTabs->setObjectName(QString::fromUtf8("gameTabs"));
        gameTabs->setTabPosition(QTabWidget::West);
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        horizontalLayout_15 = new QHBoxLayout(tab_3);
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        horizontalLayout_15->setContentsMargins(4, -1, -1, -1);
        mainPages = new QStackedWidget(tab_3);
        mainPages->setObjectName(QString::fromUtf8("mainPages"));
        menuPage = new QWidget();
        menuPage->setObjectName(QString::fromUtf8("menuPage"));
        horizontalLayout_20 = new QHBoxLayout(menuPage);
        horizontalLayout_20->setSpacing(6);
        horizontalLayout_20->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_20->setObjectName(QString::fromUtf8("horizontalLayout_20"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_20->addItem(horizontalSpacer);

        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setSpacing(6);
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        verticalLayout_13->setContentsMargins(-1, -1, -1, 0);
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_13->addItem(verticalSpacer_3);

        groupBox_3 = new QGroupBox(menuPage);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setMinimumSize(QSize(141, 0));
        verticalLayout_12 = new QVBoxLayout(groupBox_3);
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setContentsMargins(11, 11, 11, 11);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        play = new QPushButton(groupBox_3);
        play->setObjectName(QString::fromUtf8("play"));

        verticalLayout_12->addWidget(play);

        load = new QPushButton(groupBox_3);
        load->setObjectName(QString::fromUtf8("load"));

        verticalLayout_12->addWidget(load);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setSpacing(6);
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        horizontalLayout_17->setContentsMargins(-1, 11, -1, -1);
        save = new QPushButton(groupBox_3);
        save->setObjectName(QString::fromUtf8("save"));

        horizontalLayout_17->addWidget(save);


        verticalLayout_12->addLayout(horizontalLayout_17);

        autor = new QPushButton(groupBox_3);
        autor->setObjectName(QString::fromUtf8("autor"));
        autor->setEnabled(true);

        verticalLayout_12->addWidget(autor);

        settings = new QPushButton(groupBox_3);
        settings->setObjectName(QString::fromUtf8("settings"));

        verticalLayout_12->addWidget(settings);

        exit = new QPushButton(groupBox_3);
        exit->setObjectName(QString::fromUtf8("exit"));

        verticalLayout_12->addWidget(exit);


        verticalLayout_13->addWidget(groupBox_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_13->addItem(verticalSpacer);

        groupBox = new QGroupBox(menuPage);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_8 = new QVBoxLayout(groupBox);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        showIDE = new QCheckBox(groupBox);
        showIDE->setObjectName(QString::fromUtf8("showIDE"));

        verticalLayout_8->addWidget(showIDE);


        verticalLayout_13->addWidget(groupBox);


        horizontalLayout_20->addLayout(verticalLayout_13);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_20->addItem(horizontalSpacer_2);

        mainPages->addWidget(menuPage);
        startGamePage = new QWidget();
        startGamePage->setObjectName(QString::fromUtf8("startGamePage"));
        horizontalLayout_21 = new QHBoxLayout(startGamePage);
        horizontalLayout_21->setSpacing(6);
        horizontalLayout_21->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_21->setObjectName(QString::fromUtf8("horizontalLayout_21"));
        startFFALayout = new QVBoxLayout();
        startFFALayout->setSpacing(6);
        startFFALayout->setObjectName(QString::fromUtf8("startFFALayout"));

        horizontalLayout_21->addLayout(startFFALayout);

        mainPages->addWidget(startGamePage);

        horizontalLayout_15->addWidget(mainPages);

        gameTabs->addTab(tab_3, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tab->setEnabled(true);
        verticalLayout = new QVBoxLayout(tab);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget_4 = new QWidget(tab);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        horizontalLayout_6 = new QHBoxLayout(widget_4);
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        widget = new QWidget(widget_4);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout_23 = new QHBoxLayout(widget);
        horizontalLayout_23->setSpacing(6);
        horizontalLayout_23->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_23->setObjectName(QString::fromUtf8("horizontalLayout_23"));
        layGl = new QVBoxLayout();
        layGl->setSpacing(0);
        layGl->setObjectName(QString::fromUtf8("layGl"));

        horizontalLayout_23->addLayout(layGl);


        horizontalLayout_6->addWidget(widget);


        verticalLayout->addWidget(widget_4);

        gameTabs->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        horizontalLayout_4 = new QHBoxLayout(tab_2);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        manLayout = new QVBoxLayout();
        manLayout->setSpacing(6);
        manLayout->setObjectName(QString::fromUtf8("manLayout"));

        horizontalLayout_4->addLayout(manLayout);

        gameTabs->addTab(tab_2, QString());

        horizontalLayout_2->addWidget(gameTabs);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        gameTabs->setCurrentIndex(0);
        mainPages->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        play->setText(QApplication::translate("MainWindow", "\320\230\320\263\321\200\320\260\321\202\321\214!", 0, QApplication::UnicodeUTF8));
        load->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        save->setText(QApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        autor->setText(QApplication::translate("MainWindow", "\320\220\320\262\321\202\320\276\321\200\321\213", 0, QApplication::UnicodeUTF8));
        settings->setText(QApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", 0, QApplication::UnicodeUTF8));
        exit->setText(QApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", 0, QApplication::UnicodeUTF8));
        showIDE->setText(QApplication::translate("MainWindow", "IDE", 0, QApplication::UnicodeUTF8));
        gameTabs->setTabText(gameTabs->indexOf(tab_3), QApplication::translate("MainWindow", "\320\234\320\265\320\275\321\216", 0, QApplication::UnicodeUTF8));
        gameTabs->setTabText(gameTabs->indexOf(tab), QApplication::translate("MainWindow", "\320\230\320\263\321\200\320\260", 0, QApplication::UnicodeUTF8));
        gameTabs->setTabText(gameTabs->indexOf(tab_2), QApplication::translate("MainWindow", "\320\241\320\277\321\200\320\260\320\262\320\272\320\260", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
