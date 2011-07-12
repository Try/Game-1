/********************************************************************************
** Form generated from reading UI file 'saveloaddialog.ui'
**
** Created
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAVELOADDIALOG_H
#define UI_SAVELOADDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SaveLoadDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *caption;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *fname;
    QListWidget *files;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *mapFormat;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QPushButton *action;
    QSpacerItem *horizontalSpacer;
    QPushButton *cansel;

    void setupUi(QDialog *SaveLoadDialog)
    {
        if (SaveLoadDialog->objectName().isEmpty())
            SaveLoadDialog->setObjectName(QString::fromUtf8("SaveLoadDialog"));
        SaveLoadDialog->resize(320, 343);
        verticalLayout = new QVBoxLayout(SaveLoadDialog);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox_2 = new QGroupBox(SaveLoadDialog);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_3 = new QVBoxLayout(groupBox_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        groupBox = new QGroupBox(groupBox_2);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout_2 = new QHBoxLayout(groupBox);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        caption = new QLabel(groupBox);
        caption->setObjectName(QString::fromUtf8("caption"));
        caption->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(caption);


        verticalLayout_3->addWidget(groupBox);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        fname = new QLineEdit(groupBox_2);
        fname->setObjectName(QString::fromUtf8("fname"));

        horizontalLayout_3->addWidget(fname);


        verticalLayout_3->addLayout(horizontalLayout_3);

        files = new QListWidget(groupBox_2);
        files->setObjectName(QString::fromUtf8("files"));

        verticalLayout_3->addWidget(files);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        mapFormat = new QCheckBox(groupBox_2);
        mapFormat->setObjectName(QString::fromUtf8("mapFormat"));

        verticalLayout_2->addWidget(mapFormat);

        frame = new QFrame(groupBox_2);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        action = new QPushButton(frame);
        action->setObjectName(QString::fromUtf8("action"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(action->sizePolicy().hasHeightForWidth());
        action->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(action);

        horizontalSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        cansel = new QPushButton(frame);
        cansel->setObjectName(QString::fromUtf8("cansel"));
        sizePolicy.setHeightForWidth(cansel->sizePolicy().hasHeightForWidth());
        cansel->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(cansel);


        verticalLayout_2->addWidget(frame);


        verticalLayout_3->addLayout(verticalLayout_2);


        verticalLayout->addWidget(groupBox_2);


        retranslateUi(SaveLoadDialog);

        QMetaObject::connectSlotsByName(SaveLoadDialog);
    } // setupUi

    void retranslateUi(QDialog *SaveLoadDialog)
    {
        SaveLoadDialog->setWindowTitle(QApplication::translate("SaveLoadDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        caption->setText(QApplication::translate("SaveLoadDialog", "Save Game", 0, QApplication::UnicodeUTF8));
        mapFormat->setText(QApplication::translate("SaveLoadDialog", "\320\272\320\260\320\272 \320\272\320\260\321\200\321\202\321\203(*.map)", 0, QApplication::UnicodeUTF8));
        action->setText(QApplication::translate("SaveLoadDialog", "Save", 0, QApplication::UnicodeUTF8));
        cansel->setText(QApplication::translate("SaveLoadDialog", "Cansel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SaveLoadDialog: public Ui_SaveLoadDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAVELOADDIALOG_H
