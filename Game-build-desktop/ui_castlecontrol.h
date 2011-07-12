/********************************************************************************
** Form generated from reading UI file 'castlecontrol.ui'
**
** Created
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CASTLECONTROL_H
#define UI_CASTLECONTROL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QProgressBar>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CastleControl
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *buildButtons;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;
    QFrame *buildPanel;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *layCurrenBuild;
    QProgressBar *progress;
    QHBoxLayout *_2;
    QHBoxLayout *layBuild;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *CastleControl)
    {
        if (CastleControl->objectName().isEmpty())
            CastleControl->setObjectName(QString::fromUtf8("CastleControl"));
        CastleControl->resize(213, 185);
        verticalLayout = new QVBoxLayout(CastleControl);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(-1, -1, -1, 24);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        buildButtons = new QHBoxLayout();
        buildButtons->setObjectName(QString::fromUtf8("buildButtons"));

        horizontalLayout->addLayout(buildButtons);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        buildPanel = new QFrame(CastleControl);
        buildPanel->setObjectName(QString::fromUtf8("buildPanel"));
        buildPanel->setFrameShape(QFrame::StyledPanel);
        buildPanel->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(buildPanel);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        layCurrenBuild = new QVBoxLayout();
        layCurrenBuild->setObjectName(QString::fromUtf8("layCurrenBuild"));

        horizontalLayout_3->addLayout(layCurrenBuild);

        progress = new QProgressBar(buildPanel);
        progress->setObjectName(QString::fromUtf8("progress"));
        progress->setValue(24);

        horizontalLayout_3->addWidget(progress);


        verticalLayout_2->addLayout(horizontalLayout_3);

        _2 = new QHBoxLayout();
        _2->setObjectName(QString::fromUtf8("_2"));
        layBuild = new QHBoxLayout();
        layBuild->setSpacing(0);
        layBuild->setObjectName(QString::fromUtf8("layBuild"));

        _2->addLayout(layBuild);

        horizontalSpacer_2 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        _2->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(_2);


        verticalLayout->addWidget(buildPanel);


        retranslateUi(CastleControl);

        QMetaObject::connectSlotsByName(CastleControl);
    } // setupUi

    void retranslateUi(QWidget *CastleControl)
    {
        CastleControl->setWindowTitle(QApplication::translate("CastleControl", "Form", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CastleControl: public Ui_CastleControl {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CASTLECONTROL_H
