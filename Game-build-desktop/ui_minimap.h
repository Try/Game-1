/********************************************************************************
** Form generated from reading UI file 'minimap.ui'
**
** Created
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MINIMAP_H
#define UI_MINIMAP_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MiniMap
{
public:

    void setupUi(QWidget *MiniMap)
    {
        if (MiniMap->objectName().isEmpty())
            MiniMap->setObjectName(QString::fromUtf8("MiniMap"));
        MiniMap->resize(288, 259);

        retranslateUi(MiniMap);

        QMetaObject::connectSlotsByName(MiniMap);
    } // setupUi

    void retranslateUi(QWidget *MiniMap)
    {
        MiniMap->setWindowTitle(QApplication::translate("MiniMap", "Form", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MiniMap: public Ui_MiniMap {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MINIMAP_H
