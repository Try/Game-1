/********************************************************************************
** Form generated from reading UI file 'unitctrl.ui'
**
** Created
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UNITCTRL_H
#define UI_UNITCTRL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UnitCtrl
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *horizontalWidget;
    QHBoxLayout *horizontalLayout;
    QToolButton *move;
    QToolButton *cansel;
    QToolButton *toolButton_4;
    QToolButton *toolButton_3;
    QToolButton *atack;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *layAdd;

    void setupUi(QWidget *UnitCtrl)
    {
        if (UnitCtrl->objectName().isEmpty())
            UnitCtrl->setObjectName(QString::fromUtf8("UnitCtrl"));
        UnitCtrl->resize(218, 197);
        UnitCtrl->setMinimumSize(QSize(200, 167));
        verticalLayout = new QVBoxLayout(UnitCtrl);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(-1, -1, -1, 16);
        horizontalWidget = new QWidget(UnitCtrl);
        horizontalWidget->setObjectName(QString::fromUtf8("horizontalWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(horizontalWidget->sizePolicy().hasHeightForWidth());
        horizontalWidget->setSizePolicy(sizePolicy);
        horizontalWidget->setMinimumSize(QSize(180, 40));
        horizontalLayout = new QHBoxLayout(horizontalWidget);
        horizontalLayout->setSpacing(2);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        move = new QToolButton(horizontalWidget);
        move->setObjectName(QString::fromUtf8("move"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(move->sizePolicy().hasHeightForWidth());
        move->setSizePolicy(sizePolicy1);
        move->setMinimumSize(QSize(40, 40));
        move->setIconSize(QSize(28, 28));

        horizontalLayout->addWidget(move);

        cansel = new QToolButton(horizontalWidget);
        cansel->setObjectName(QString::fromUtf8("cansel"));
        sizePolicy1.setHeightForWidth(cansel->sizePolicy().hasHeightForWidth());
        cansel->setSizePolicy(sizePolicy1);
        cansel->setMinimumSize(QSize(40, 40));
        cansel->setIconSize(QSize(28, 28));

        horizontalLayout->addWidget(cansel);

        toolButton_4 = new QToolButton(horizontalWidget);
        toolButton_4->setObjectName(QString::fromUtf8("toolButton_4"));
        toolButton_4->setEnabled(false);
        sizePolicy1.setHeightForWidth(toolButton_4->sizePolicy().hasHeightForWidth());
        toolButton_4->setSizePolicy(sizePolicy1);
        toolButton_4->setMinimumSize(QSize(40, 40));

        horizontalLayout->addWidget(toolButton_4);

        toolButton_3 = new QToolButton(horizontalWidget);
        toolButton_3->setObjectName(QString::fromUtf8("toolButton_3"));
        toolButton_3->setEnabled(false);
        sizePolicy1.setHeightForWidth(toolButton_3->sizePolicy().hasHeightForWidth());
        toolButton_3->setSizePolicy(sizePolicy1);
        toolButton_3->setMinimumSize(QSize(40, 40));

        horizontalLayout->addWidget(toolButton_3);

        atack = new QToolButton(horizontalWidget);
        atack->setObjectName(QString::fromUtf8("atack"));
        sizePolicy1.setHeightForWidth(atack->sizePolicy().hasHeightForWidth());
        atack->setSizePolicy(sizePolicy1);
        atack->setMinimumSize(QSize(40, 40));
        atack->setIconSize(QSize(28, 28));

        horizontalLayout->addWidget(atack);


        verticalLayout->addWidget(horizontalWidget);

        widget = new QWidget(UnitCtrl);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        layAdd = new QVBoxLayout();
        layAdd->setObjectName(QString::fromUtf8("layAdd"));

        horizontalLayout_2->addLayout(layAdd);


        verticalLayout->addWidget(widget);


        retranslateUi(UnitCtrl);

        QMetaObject::connectSlotsByName(UnitCtrl);
    } // setupUi

    void retranslateUi(QWidget *UnitCtrl)
    {
        UnitCtrl->setWindowTitle(QApplication::translate("UnitCtrl", "Form", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        move->setToolTip(QApplication::translate("UnitCtrl", "\320\230\320\264\321\202\320\270", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        cansel->setToolTip(QApplication::translate("UnitCtrl", "\320\276\321\202\321\201\321\202\320\260\320\262\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        toolButton_4->setToolTip(QApplication::translate("UnitCtrl", "\321\203\320\264\320\265\321\200\320\266\320\270\320\262\320\260\321\202\321\214 \320\277\320\276\320\267\320\270\321\206\320\270\321\216", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        toolButton_3->setToolTip(QApplication::translate("UnitCtrl", "\320\277\320\260\321\202\321\200\321\203\320\273\320\270\321\200\320\276\320\262\320\260\321\202\321\214", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        atack->setToolTip(QApplication::translate("UnitCtrl", "\320\220\321\202\320\260\320\272\320\260!", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class UnitCtrl: public Ui_UnitCtrl {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UNITCTRL_H
