/********************************************************************************
** Form generated from reading UI file 'workercontroller.ui'
**
** Created
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WORKERCONTROLLER_H
#define UI_WORKERCONTROLLER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QSpacerItem>
#include <QtGui/QStackedWidget>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WorkerController
{
public:
    QHBoxLayout *horizontalLayout_2;
    QStackedWidget *pages;
    QWidget *page;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QToolButton *buildSome;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QGridLayout *layBtns;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *WorkerController)
    {
        if (WorkerController->objectName().isEmpty())
            WorkerController->setObjectName(QString::fromUtf8("WorkerController"));
        WorkerController->resize(96, 156);
        horizontalLayout_2 = new QHBoxLayout(WorkerController);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 10, 20);
        pages = new QStackedWidget(WorkerController);
        pages->setObjectName(QString::fromUtf8("pages"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        verticalLayout = new QVBoxLayout(page);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, -1, 0);
        verticalSpacer = new QSpacerItem(20, 90, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        buildSome = new QToolButton(page);
        buildSome->setObjectName(QString::fromUtf8("buildSome"));
        buildSome->setMinimumSize(QSize(40, 40));
        buildSome->setIconSize(QSize(30, 30));

        horizontalLayout->addWidget(buildSome);


        verticalLayout->addLayout(horizontalLayout);

        pages->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        verticalLayout_2 = new QVBoxLayout(page_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 15, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(-1, -1, -1, 8);
        layBtns = new QGridLayout();
        layBtns->setSpacing(2);
        layBtns->setObjectName(QString::fromUtf8("layBtns"));

        horizontalLayout_4->addLayout(layBtns);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_4);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        pages->addWidget(page_2);

        horizontalLayout_2->addWidget(pages);


        retranslateUi(WorkerController);

        pages->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(WorkerController);
    } // setupUi

    void retranslateUi(QWidget *WorkerController)
    {
        WorkerController->setWindowTitle(QApplication::translate("WorkerController", "Form", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class WorkerController: public Ui_WorkerController {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WORKERCONTROLLER_H
