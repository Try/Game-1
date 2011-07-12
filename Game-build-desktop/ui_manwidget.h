/********************************************************************************
** Form generated from reading UI file 'manwidget.ui'
**
** Created
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANWIDGET_H
#define UI_MANWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ManWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QFrame *frame_4;
    QVBoxLayout *verticalLayout_3;
    QPushButton *priview;
    QComboBox *groups;
    QGroupBox *groupBox_10;
    QVBoxLayout *verticalLayout;
    QListWidget *unitsList;
    QFrame *line_4;
    QFrame *frame_5;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_3;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *layShow;
    QHBoxLayout *horizontalLayout_18;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_4;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_12;
    QGroupBox *groupBox_9;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLabel *speed;
    QGroupBox *groupBox_6;
    QHBoxLayout *horizontalLayout_11;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_4;
    QLabel *hp;
    QWidget *widget_51;
    QHBoxLayout *hboxLayout;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_9;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_3;
    QLabel *damage;
    QFrame *line;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label;
    QLabel *atkTime;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_14;
    QGroupBox *groupBox_4;
    QHBoxLayout *_3;
    QHBoxLayout *_2;
    QLabel *label_6;
    QLabel *buildTime;
    QFrame *line_3;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_5;
    QLabel *hKey;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_15;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_8;
    QLabel *cost;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_7;
    QLabel *houses;
    QSpacerItem *verticalSpacer_2;
    QFrame *frame_7;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *groupBox_8;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_9;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_21;
    QHBoxLayout *layRecruts;
    QSpacerItem *horizontalSpacer_7;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_20;
    QLabel *text;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_4;
    QGroupBox *groupBox_7;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_10;
    QWidget *widget_7;
    QHBoxLayout *horizontalLayout_17;
    QHBoxLayout *layOwners;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QWidget *ManWidget)
    {
        if (ManWidget->objectName().isEmpty())
            ManWidget->setObjectName(QString::fromUtf8("ManWidget"));
        ManWidget->resize(810, 483);
        horizontalLayout = new QHBoxLayout(ManWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        frame_4 = new QFrame(ManWidget);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame_4->sizePolicy().hasHeightForWidth());
        frame_4->setSizePolicy(sizePolicy);
        frame_4->setMaximumSize(QSize(210, 16777215));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frame_4);
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        priview = new QPushButton(frame_4);
        priview->setObjectName(QString::fromUtf8("priview"));
        priview->setMinimumSize(QSize(200, 200));
        priview->setMaximumSize(QSize(200, 200));
        priview->setIconSize(QSize(200, 200));

        verticalLayout_3->addWidget(priview);

        groups = new QComboBox(frame_4);
        groups->setObjectName(QString::fromUtf8("groups"));

        verticalLayout_3->addWidget(groups);

        groupBox_10 = new QGroupBox(frame_4);
        groupBox_10->setObjectName(QString::fromUtf8("groupBox_10"));
        verticalLayout = new QVBoxLayout(groupBox_10);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        unitsList = new QListWidget(groupBox_10);
        unitsList->setObjectName(QString::fromUtf8("unitsList"));

        verticalLayout->addWidget(unitsList);


        verticalLayout_3->addWidget(groupBox_10);


        horizontalLayout->addWidget(frame_4);

        line_4 = new QFrame(ManWidget);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_4);

        frame_5 = new QFrame(ManWidget);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame_5->sizePolicy().hasHeightForWidth());
        frame_5->setSizePolicy(sizePolicy1);
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame_5);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        widget = new QWidget(frame_5);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout_3 = new QHBoxLayout(widget);
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        widget_4 = new QWidget(widget);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(widget_4->sizePolicy().hasHeightForWidth());
        widget_4->setSizePolicy(sizePolicy2);
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(255, 254, 253, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 255, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(255, 254, 254, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(127, 127, 126, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(170, 169, 169, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush3);
        QBrush brush6(QColor(255, 255, 220, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        widget_4->setPalette(palette);
        verticalLayout_8 = new QVBoxLayout(widget_4);
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        layShow = new QVBoxLayout();
        layShow->setObjectName(QString::fromUtf8("layShow"));

        verticalLayout_8->addLayout(layShow);


        horizontalLayout_3->addWidget(widget_4);


        verticalLayout_2->addWidget(widget);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        groupBox = new QGroupBox(frame_5);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_4 = new QVBoxLayout(groupBox);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        widget_3 = new QWidget(groupBox);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_12 = new QHBoxLayout(widget_3);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        groupBox_9 = new QGroupBox(widget_3);
        groupBox_9->setObjectName(QString::fromUtf8("groupBox_9"));
        sizePolicy1.setHeightForWidth(groupBox_9->sizePolicy().hasHeightForWidth());
        groupBox_9->setSizePolicy(sizePolicy1);
        horizontalLayout_5 = new QHBoxLayout(groupBox_9);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(groupBox_9);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        speed = new QLabel(groupBox_9);
        speed->setObjectName(QString::fromUtf8("speed"));

        horizontalLayout_2->addWidget(speed);


        horizontalLayout_5->addLayout(horizontalLayout_2);


        horizontalLayout_12->addWidget(groupBox_9);

        groupBox_6 = new QGroupBox(widget_3);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        horizontalLayout_11 = new QHBoxLayout(groupBox_6);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_4 = new QLabel(groupBox_6);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_8->addWidget(label_4);

        hp = new QLabel(groupBox_6);
        hp->setObjectName(QString::fromUtf8("hp"));

        horizontalLayout_8->addWidget(hp);


        horizontalLayout_11->addLayout(horizontalLayout_8);


        horizontalLayout_12->addWidget(groupBox_6);


        verticalLayout_4->addWidget(widget_3);

        widget_51 = new QWidget(groupBox);
        widget_51->setObjectName(QString::fromUtf8("widget_51"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(widget_51->sizePolicy().hasHeightForWidth());
        widget_51->setSizePolicy(sizePolicy3);
        hboxLayout = new QHBoxLayout(widget_51);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        groupBox_2 = new QGroupBox(widget_51);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        horizontalLayout_9 = new QHBoxLayout(groupBox_2);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_6->addWidget(label_3);

        damage = new QLabel(groupBox_2);
        damage->setObjectName(QString::fromUtf8("damage"));

        horizontalLayout_6->addWidget(damage);


        horizontalLayout_9->addLayout(horizontalLayout_6);

        line = new QFrame(groupBox_2);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_9->addWidget(line);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_10->addWidget(label);

        atkTime = new QLabel(groupBox_2);
        atkTime->setObjectName(QString::fromUtf8("atkTime"));

        horizontalLayout_10->addWidget(atkTime);


        horizontalLayout_9->addLayout(horizontalLayout_10);


        hboxLayout->addWidget(groupBox_2);


        verticalLayout_4->addWidget(widget_51);

        widget_6 = new QWidget(groupBox);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        sizePolicy3.setHeightForWidth(widget_6->sizePolicy().hasHeightForWidth());
        widget_6->setSizePolicy(sizePolicy3);
        horizontalLayout_14 = new QHBoxLayout(widget_6);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        groupBox_4 = new QGroupBox(widget_6);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        _3 = new QHBoxLayout(groupBox_4);
        _3->setObjectName(QString::fromUtf8("_3"));
        _2 = new QHBoxLayout();
        _2->setObjectName(QString::fromUtf8("_2"));
        label_6 = new QLabel(groupBox_4);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        _2->addWidget(label_6);

        buildTime = new QLabel(groupBox_4);
        buildTime->setObjectName(QString::fromUtf8("buildTime"));

        _2->addWidget(buildTime);


        _3->addLayout(_2);

        line_3 = new QFrame(groupBox_4);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        _3->addWidget(line_3);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(-1, -1, 5, -1);
        label_5 = new QLabel(groupBox_4);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_7->addWidget(label_5);

        hKey = new QLabel(groupBox_4);
        hKey->setObjectName(QString::fromUtf8("hKey"));

        horizontalLayout_7->addWidget(hKey);


        _3->addLayout(horizontalLayout_7);


        horizontalLayout_14->addWidget(groupBox_4);

        groupBox_3 = new QGroupBox(widget_6);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        horizontalLayout_15 = new QHBoxLayout(groupBox_3);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_13->addWidget(label_8);

        cost = new QLabel(groupBox_3);
        cost->setObjectName(QString::fromUtf8("cost"));

        horizontalLayout_13->addWidget(cost);


        horizontalLayout_15->addLayout(horizontalLayout_13);

        line_2 = new QFrame(groupBox_3);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout_15->addWidget(line_2);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_16->addWidget(label_7);

        houses = new QLabel(groupBox_3);
        houses->setObjectName(QString::fromUtf8("houses"));

        horizontalLayout_16->addWidget(houses);


        horizontalLayout_15->addLayout(horizontalLayout_16);


        horizontalLayout_14->addWidget(groupBox_3);


        verticalLayout_4->addWidget(widget_6);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);

        frame_7 = new QFrame(groupBox);
        frame_7->setObjectName(QString::fromUtf8("frame_7"));
        verticalLayout_5 = new QVBoxLayout(frame_7);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        groupBox_8 = new QGroupBox(frame_7);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        verticalLayout_7 = new QVBoxLayout(groupBox_8);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        label_9 = new QLabel(groupBox_8);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        verticalLayout_7->addWidget(label_9);

        widget_2 = new QWidget(groupBox_8);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout_21 = new QHBoxLayout(widget_2);
        horizontalLayout_21->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_21->setObjectName(QString::fromUtf8("horizontalLayout_21"));
        layRecruts = new QHBoxLayout();
        layRecruts->setObjectName(QString::fromUtf8("layRecruts"));

        horizontalLayout_21->addLayout(layRecruts);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_21->addItem(horizontalSpacer_7);


        verticalLayout_7->addWidget(widget_2);


        verticalLayout_5->addWidget(groupBox_8);


        verticalLayout_4->addWidget(frame_7);


        horizontalLayout_18->addWidget(groupBox);

        groupBox_5 = new QGroupBox(frame_5);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        verticalLayout_6 = new QVBoxLayout(groupBox_5);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setObjectName(QString::fromUtf8("horizontalLayout_20"));
        text = new QLabel(groupBox_5);
        text->setObjectName(QString::fromUtf8("text"));
        QFont font;
        font.setPointSize(14);
        text->setFont(font);

        horizontalLayout_20->addWidget(text);

        horizontalSpacer_6 = new QSpacerItem(372, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_20->addItem(horizontalSpacer_6);


        verticalLayout_6->addLayout(horizontalLayout_20);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer);

        widget_5 = new QWidget(groupBox_5);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        horizontalLayout_4 = new QHBoxLayout(widget_5);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        groupBox_7 = new QGroupBox(widget_5);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        verticalLayout_9 = new QVBoxLayout(groupBox_7);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        label_10 = new QLabel(groupBox_7);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        verticalLayout_9->addWidget(label_10);

        widget_7 = new QWidget(groupBox_7);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        horizontalLayout_17 = new QHBoxLayout(widget_7);
        horizontalLayout_17->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        layOwners = new QHBoxLayout();
        layOwners->setObjectName(QString::fromUtf8("layOwners"));

        horizontalLayout_17->addLayout(layOwners);

        horizontalSpacer_4 = new QSpacerItem(351, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_17->addItem(horizontalSpacer_4);


        verticalLayout_9->addWidget(widget_7);


        horizontalLayout_4->addWidget(groupBox_7);


        verticalLayout_6->addWidget(widget_5);


        horizontalLayout_18->addWidget(groupBox_5);


        verticalLayout_2->addLayout(horizontalLayout_18);


        horizontalLayout->addWidget(frame_5);


        retranslateUi(ManWidget);

        QMetaObject::connectSlotsByName(ManWidget);
    } // setupUi

    void retranslateUi(QWidget *ManWidget)
    {
        ManWidget->setWindowTitle(QApplication::translate("ManWidget", "Form", 0, QApplication::UnicodeUTF8));
        groups->clear();
        groups->insertItems(0, QStringList()
         << QApplication::translate("ManWidget", "\320\256\320\275\320\270\321\202\321\213", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ManWidget", "\320\227\320\264\320\260\320\275\320\270\321\217", 0, QApplication::UnicodeUTF8)
        );
        label_2->setText(QApplication::translate("ManWidget", "\320\241\320\272\320\276\321\200\320\276\321\201\321\202\321\214 \320\264\320\262\320\270\320\266\320\265\320\275\320\270\321\217", 0, QApplication::UnicodeUTF8));
        speed->setText(QApplication::translate("ManWidget", "0", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("ManWidget", "\320\227\320\264\320\276\321\200\320\276\320\262\321\214\320\265", 0, QApplication::UnicodeUTF8));
        hp->setText(QApplication::translate("ManWidget", "1", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ManWidget", "\320\243\321\200\320\276\320\275", 0, QApplication::UnicodeUTF8));
        damage->setText(QApplication::translate("ManWidget", "0", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ManWidget", "\320\237\320\265\321\200\320\265\321\200\321\213\320\262 \320\274\320\265\320\266\320\264\321\203 \320\260\321\202\320\260\320\272\320\260\320\274\320\270", 0, QApplication::UnicodeUTF8));
        atkTime->setText(QApplication::translate("ManWidget", "1", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("ManWidget", "\320\222\321\200\320\265\320\274\321\217 \320\277\320\276\321\201\321\202\321\200\320\276\320\271\320\272\320\270", 0, QApplication::UnicodeUTF8));
        buildTime->setText(QApplication::translate("ManWidget", "0", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("ManWidget", "hot-\320\232\320\265\320\271:", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("ManWidget", "\320\241\321\202\320\276\320\270\320\274\320\276\321\201\321\202\321\214", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("ManWidget", "\320\227\320\276\320\273\320\276\321\202\320\276", 0, QApplication::UnicodeUTF8));
        cost->setText(QApplication::translate("ManWidget", "0", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("ManWidget", "\320\226\320\270\320\273\321\214\320\265", 0, QApplication::UnicodeUTF8));
        houses->setText(QApplication::translate("ManWidget", "0", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("ManWidget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Serif'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\235\320\260\320\275\320\270\320\274\320\260\320\265\320\274\321\213\320\265 \320\262\320\276\320\271\321\201\320\272\320\260</p></body></html>", 0, QApplication::UnicodeUTF8));
        text->setText(QString());
        label_10->setText(QApplication::translate("ManWidget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Serif'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\235\320\260\320\275\320\270\320\274\320\260\320\265\321\202\321\201\321\217 \320\262 ...</p></body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ManWidget: public Ui_ManWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANWIDGET_H
