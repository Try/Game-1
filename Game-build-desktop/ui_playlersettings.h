/********************************************************************************
** Form generated from reading UI file 'playlersettings.ui'
**
** Created
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYLERSETTINGS_H
#define UI_PLAYLERSETTINGS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QStackedWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PlaylerSettings
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_5;
    QCheckBox *used;
    QLabel *plLabel;
    QStackedWidget *botSettings;
    QWidget *page;
    QHBoxLayout *horizontalLayout;
    QComboBox *ai_level;
    QWidget *page_2;
    QComboBox *isHuman;
    QFrame *line;

    void setupUi(QWidget *PlaylerSettings)
    {
        if (PlaylerSettings->objectName().isEmpty())
            PlaylerSettings->setObjectName(QString::fromUtf8("PlaylerSettings"));
        PlaylerSettings->resize(378, 45);
        verticalLayout = new QVBoxLayout(PlaylerSettings);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(PlaylerSettings);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout_5 = new QHBoxLayout(groupBox);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        used = new QCheckBox(groupBox);
        used->setObjectName(QString::fromUtf8("used"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(used->sizePolicy().hasHeightForWidth());
        used->setSizePolicy(sizePolicy);
        used->setChecked(true);

        horizontalLayout_5->addWidget(used);

        plLabel = new QLabel(groupBox);
        plLabel->setObjectName(QString::fromUtf8("plLabel"));

        horizontalLayout_5->addWidget(plLabel);

        botSettings = new QStackedWidget(groupBox);
        botSettings->setObjectName(QString::fromUtf8("botSettings"));
        sizePolicy.setHeightForWidth(botSettings->sizePolicy().hasHeightForWidth());
        botSettings->setSizePolicy(sizePolicy);
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        horizontalLayout = new QHBoxLayout(page);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        ai_level = new QComboBox(page);
        ai_level->setObjectName(QString::fromUtf8("ai_level"));
        ai_level->setEnabled(false);

        horizontalLayout->addWidget(ai_level);

        botSettings->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        botSettings->addWidget(page_2);

        horizontalLayout_5->addWidget(botSettings);

        isHuman = new QComboBox(groupBox);
        isHuman->setObjectName(QString::fromUtf8("isHuman"));

        horizontalLayout_5->addWidget(isHuman);


        verticalLayout->addWidget(groupBox);

        line = new QFrame(PlaylerSettings);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);


        retranslateUi(PlaylerSettings);

        botSettings->setCurrentIndex(0);
        ai_level->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(PlaylerSettings);
    } // setupUi

    void retranslateUi(QWidget *PlaylerSettings)
    {
        PlaylerSettings->setWindowTitle(QApplication::translate("PlaylerSettings", "Form", 0, QApplication::UnicodeUTF8));
        plLabel->setText(QApplication::translate("PlaylerSettings", "\320\230\320\263\321\200\320\276\320\272 ", 0, QApplication::UnicodeUTF8));
        ai_level->clear();
        ai_level->insertItems(0, QStringList()
         << QApplication::translate("PlaylerSettings", "\320\235\320\276\320\262\320\270\321\207\321\221\320\272", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PlaylerSettings", "\320\237\320\276\321\201\321\202\320\276\321\217\320\273\320\265\321\206", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PlaylerSettings", "\320\243\321\207\320\260\321\201\321\202\320\275\320\270\320\272", 0, QApplication::UnicodeUTF8)
        );
        isHuman->clear();
        isHuman->insertItems(0, QStringList()
         << QApplication::translate("PlaylerSettings", "\320\247\320\265\320\273\320\276\320\262\320\265\320\272", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PlaylerSettings", "\320\232\320\276\320\274\320\277\321\214\321\216\321\202\320\265\321\200", 0, QApplication::UnicodeUTF8)
        );
    } // retranslateUi

};

namespace Ui {
    class PlaylerSettings: public Ui_PlaylerSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYLERSETTINGS_H
