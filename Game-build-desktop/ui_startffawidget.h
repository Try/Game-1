/********************************************************************************
** Form generated from reading UI file 'startffawidget.ui'
**
** Created
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTFFAWIDGET_H
#define UI_STARTFFAWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StartFFAWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *verticalWidget;
    QVBoxLayout *verticalLayout_14;
    QFrame *frame_3;
    QVBoxLayout *verticalLayout_10;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_7;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_6;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_4;
    QVBoxLayout *verticalLayout_4;
    QLabel *name;
    QLabel *size;
    QLabel *label_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *back_to_menu;
    QWidget *widget_2;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *priviewMap;
    QGroupBox *groupBox_9;
    QVBoxLayout *verticalLayout_3;
    QScrollArea *scrollArea;
    QWidget *maps;
    QHBoxLayout *horizontalLayout_9;
    QGridLayout *layMaps;
    QFrame *frame_4;
    QVBoxLayout *verticalLayout_15;
    QWidget *widget_10;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *layPlaylers;
    QSpacerItem *verticalSpacer;
    QWidget *widget_11;
    QHBoxLayout *horizontalLayout_22;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *play;
    QSpacerItem *horizontalSpacer_5;

    void setupUi(QWidget *StartFFAWidget)
    {
        if (StartFFAWidget->objectName().isEmpty())
            StartFFAWidget->setObjectName(QString::fromUtf8("StartFFAWidget"));
        StartFFAWidget->resize(616, 497);
        horizontalLayout = new QHBoxLayout(StartFFAWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalWidget = new QWidget(StartFFAWidget);
        verticalWidget->setObjectName(QString::fromUtf8("verticalWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(verticalWidget->sizePolicy().hasHeightForWidth());
        verticalWidget->setSizePolicy(sizePolicy);
        verticalLayout_14 = new QVBoxLayout(verticalWidget);
        verticalLayout_14->setContentsMargins(0, 0, 0, 0);
        verticalLayout_14->setObjectName(QString::fromUtf8("verticalLayout_14"));
        frame_3 = new QFrame(verticalWidget);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame_3->sizePolicy().hasHeightForWidth());
        frame_3->setSizePolicy(sizePolicy1);
        frame_3->setMaximumSize(QSize(16777215, 16777215));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        verticalLayout_10 = new QVBoxLayout(frame_3);
        verticalLayout_10->setContentsMargins(0, 0, 0, 0);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        groupBox_3 = new QGroupBox(frame_3);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy2);
        horizontalLayout_7 = new QHBoxLayout(groupBox_3);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        groupBox = new QGroupBox(groupBox_3);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy3);
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(-1, -1, -1, 5);
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy4);

        verticalLayout_6->addWidget(label);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy4.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy4);

        verticalLayout_6->addWidget(label_3);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy4.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy4);

        verticalLayout_6->addWidget(label_4);


        horizontalLayout_5->addLayout(verticalLayout_6);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        name = new QLabel(groupBox);
        name->setObjectName(QString::fromUtf8("name"));
        sizePolicy4.setHeightForWidth(name->sizePolicy().hasHeightForWidth());
        name->setSizePolicy(sizePolicy4);

        verticalLayout_4->addWidget(name);

        size = new QLabel(groupBox);
        size->setObjectName(QString::fromUtf8("size"));
        sizePolicy4.setHeightForWidth(size->sizePolicy().hasHeightForWidth());
        size->setSizePolicy(sizePolicy4);

        verticalLayout_4->addWidget(size);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy4.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy4);

        verticalLayout_4->addWidget(label_2);


        horizontalLayout_5->addLayout(verticalLayout_4);


        verticalLayout_2->addLayout(horizontalLayout_5);

        widget = new QWidget(groupBox);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        back_to_menu = new QPushButton(widget);
        back_to_menu->setObjectName(QString::fromUtf8("back_to_menu"));
        QSizePolicy sizePolicy5(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(back_to_menu->sizePolicy().hasHeightForWidth());
        back_to_menu->setSizePolicy(sizePolicy5);
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        back_to_menu->setFont(font);

        horizontalLayout_2->addWidget(back_to_menu);

        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));

        horizontalLayout_2->addWidget(widget_2);


        verticalLayout_2->addWidget(widget);


        horizontalLayout_7->addWidget(groupBox);

        frame = new QFrame(groupBox_3);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_8 = new QHBoxLayout(frame);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        priviewMap = new QVBoxLayout();
        priviewMap->setObjectName(QString::fromUtf8("priviewMap"));

        horizontalLayout_8->addLayout(priviewMap);


        horizontalLayout_7->addWidget(frame);


        verticalLayout_10->addWidget(groupBox_3);

        groupBox_9 = new QGroupBox(frame_3);
        groupBox_9->setObjectName(QString::fromUtf8("groupBox_9"));
        verticalLayout_3 = new QVBoxLayout(groupBox_9);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        scrollArea = new QScrollArea(groupBox_9);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        maps = new QWidget();
        maps->setObjectName(QString::fromUtf8("maps"));
        maps->setGeometry(QRect(0, 0, 272, 284));
        horizontalLayout_9 = new QHBoxLayout(maps);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        layMaps = new QGridLayout();
        layMaps->setObjectName(QString::fromUtf8("layMaps"));

        horizontalLayout_9->addLayout(layMaps);

        scrollArea->setWidget(maps);

        verticalLayout_3->addWidget(scrollArea);


        verticalLayout_10->addWidget(groupBox_9);


        verticalLayout_14->addWidget(frame_3);


        horizontalLayout->addWidget(verticalWidget);

        frame_4 = new QFrame(StartFFAWidget);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        QSizePolicy sizePolicy6(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(frame_4->sizePolicy().hasHeightForWidth());
        frame_4->setSizePolicy(sizePolicy6);
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        verticalLayout_15 = new QVBoxLayout(frame_4);
        verticalLayout_15->setObjectName(QString::fromUtf8("verticalLayout_15"));
        widget_10 = new QWidget(frame_4);
        widget_10->setObjectName(QString::fromUtf8("widget_10"));
        verticalLayout_5 = new QVBoxLayout(widget_10);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        layPlaylers = new QVBoxLayout();
        layPlaylers->setObjectName(QString::fromUtf8("layPlaylers"));

        verticalLayout_5->addLayout(layPlaylers);

        verticalSpacer = new QSpacerItem(20, 324, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer);


        verticalLayout_15->addWidget(widget_10);

        widget_11 = new QWidget(frame_4);
        widget_11->setObjectName(QString::fromUtf8("widget_11"));
        sizePolicy2.setHeightForWidth(widget_11->sizePolicy().hasHeightForWidth());
        widget_11->setSizePolicy(sizePolicy2);
        horizontalLayout_22 = new QHBoxLayout(widget_11);
        horizontalLayout_22->setObjectName(QString::fromUtf8("horizontalLayout_22"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_22->addItem(horizontalSpacer_6);

        play = new QPushButton(widget_11);
        play->setObjectName(QString::fromUtf8("play"));
        play->setMinimumSize(QSize(150, 60));
        QPalette palette;
        QBrush brush(QColor(245, 245, 245, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        play->setPalette(palette);
        QFont font1;
        font1.setPointSize(18);
        font1.setBold(true);
        font1.setWeight(75);
        play->setFont(font1);

        horizontalLayout_22->addWidget(play);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_22->addItem(horizontalSpacer_5);


        verticalLayout_15->addWidget(widget_11);


        horizontalLayout->addWidget(frame_4);


        retranslateUi(StartFFAWidget);

        QMetaObject::connectSlotsByName(StartFFAWidget);
    } // setupUi

    void retranslateUi(QWidget *StartFFAWidget)
    {
        StartFFAWidget->setWindowTitle(QApplication::translate("StartFFAWidget", "Form", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("StartFFAWidget", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("StartFFAWidget", "\320\230\320\274\321\217", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("StartFFAWidget", "\320\240\320\260\320\267\320\274\320\265\321\200", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("StartFFAWidget", "\320\242\320\270\320\277", 0, QApplication::UnicodeUTF8));
        name->setText(QApplication::translate("StartFFAWidget", "Name", 0, QApplication::UnicodeUTF8));
        size->setText(QApplication::translate("StartFFAWidget", "128x128", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("StartFFAWidget", "FFA", 0, QApplication::UnicodeUTF8));
        back_to_menu->setText(QApplication::translate("StartFFAWidget", "  \320\235\320\260\320\267\320\260\320\264  ", 0, QApplication::UnicodeUTF8));
        play->setText(QApplication::translate("StartFFAWidget", "\320\230\320\263\321\200\320\260\321\202\321\214!", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class StartFFAWidget: public Ui_StartFFAWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTFFAWIDGET_H
