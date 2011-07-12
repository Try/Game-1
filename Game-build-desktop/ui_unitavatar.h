/********************************************************************************
** Form generated from reading UI file 'unitavatar.ui'
**
** Created
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UNITAVATAR_H
#define UI_UNITAVATAR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QProgressBar>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UnitAvatar
{
public:
    QVBoxLayout *verticalLayout;
    QToolButton *icon;
    QProgressBar *hp;

    void setupUi(QWidget *UnitAvatar)
    {
        if (UnitAvatar->objectName().isEmpty())
            UnitAvatar->setObjectName(QString::fromUtf8("UnitAvatar"));
        UnitAvatar->resize(116, 165);
        verticalLayout = new QVBoxLayout(UnitAvatar);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        icon = new QToolButton(UnitAvatar);
        icon->setObjectName(QString::fromUtf8("icon"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(icon->sizePolicy().hasHeightForWidth());
        icon->setSizePolicy(sizePolicy);
        icon->setMaximumSize(QSize(116, 149));
        icon->setIconSize(QSize(50, 75));

        verticalLayout->addWidget(icon);

        hp = new QProgressBar(UnitAvatar);
        hp->setObjectName(QString::fromUtf8("hp"));
        hp->setMaximumSize(QSize(16777215, 16));
        hp->setMaximum(10);
        hp->setValue(1);

        verticalLayout->addWidget(hp);


        retranslateUi(UnitAvatar);

        QMetaObject::connectSlotsByName(UnitAvatar);
    } // setupUi

    void retranslateUi(QWidget *UnitAvatar)
    {
        UnitAvatar->setWindowTitle(QApplication::translate("UnitAvatar", "Form", 0, QApplication::UnicodeUTF8));
        hp->setFormat(QApplication::translate("UnitAvatar", "%v/100500", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class UnitAvatar: public Ui_UnitAvatar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UNITAVATAR_H
