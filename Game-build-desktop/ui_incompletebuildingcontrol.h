/********************************************************************************
** Form generated from reading UI file 'incompletebuildingcontrol.ui'
**
** Created
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INCOMPLETEBUILDINGCONTROL_H
#define UI_INCOMPLETEBUILDINGCONTROL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QProgressBar>
#include <QtGui/QSpacerItem>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IncompleteBuildingControl
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QToolButton *canselBtn;
    QProgressBar *progress;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *IncompleteBuildingControl)
    {
        if (IncompleteBuildingControl->objectName().isEmpty())
            IncompleteBuildingControl->setObjectName(QString::fromUtf8("IncompleteBuildingControl"));
        IncompleteBuildingControl->resize(208, 198);
        verticalLayout = new QVBoxLayout(IncompleteBuildingControl);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 72, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        canselBtn = new QToolButton(IncompleteBuildingControl);
        canselBtn->setObjectName(QString::fromUtf8("canselBtn"));
        canselBtn->setMinimumSize(QSize(40, 40));
        canselBtn->setMaximumSize(QSize(40, 40));
        canselBtn->setIconSize(QSize(30, 30));

        horizontalLayout->addWidget(canselBtn);

        progress = new QProgressBar(IncompleteBuildingControl);
        progress->setObjectName(QString::fromUtf8("progress"));
        progress->setValue(24);

        horizontalLayout->addWidget(progress);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 72, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        retranslateUi(IncompleteBuildingControl);

        QMetaObject::connectSlotsByName(IncompleteBuildingControl);
    } // setupUi

    void retranslateUi(QWidget *IncompleteBuildingControl)
    {
        IncompleteBuildingControl->setWindowTitle(QApplication::translate("IncompleteBuildingControl", "Form", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class IncompleteBuildingControl: public Ui_IncompleteBuildingControl {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INCOMPLETEBUILDINGCONTROL_H
