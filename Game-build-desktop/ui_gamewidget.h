/********************************************************************************
** Form generated from reading UI file 'gamewidget.ui'
**
** Created
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEWIDGET_H
#define UI_GAMEWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QScrollArea>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QStackedWidget>
#include <QtGui/QTabWidget>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameWidget
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupIdeBox;
    QVBoxLayout *verticalLayout;
    QTabWidget *ideBox;
    QWidget *ideBoxPage1;
    QVBoxLayout *verticalLayout_4;
    QComboBox *groups;
    QScrollArea *scrollArea;
    QWidget *buttonsBox;
    QVBoxLayout *verticalLayout_8;
    QWidget *widget_8;
    QVBoxLayout *verticalLayout_10;
    QVBoxLayout *buildButtonsLayout;
    QSpacerItem *verticalSpacer_3;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_11;
    QHBoxLayout *horizontalLayout_13;
    QCheckBox *useSnap;
    QToolButton *pause;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_4;
    QComboBox *curPl;
    QWidget *tab_4;
    QVBoxLayout *verticalLayout_14;
    QGridLayout *gridLayout_2;
    QToolButton *groundDown;
    QToolButton *groundNo;
    QToolButton *groundUp;
    QFrame *frame;
    QVBoxLayout *verticalLayout_15;
    QSlider *brushSize;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_4;
    QToolButton *setGrass;
    QToolButton *setSand;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer_4;
    QWidget *tab;
    QVBoxLayout *verticalLayout_17;
    QVBoxLayout *verticalLayout_16;
    QLabel *fps;
    QLabel *dipCount;
    QLabel *deltaTime;
    QLabel *bathCount;
    QSpacerItem *verticalSpacer_7;
    QSpacerItem *mainSpacer;
    QSpacerItem *verticalSpacer_6;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_12;
    QSpacerItem *verticalSpacer_5;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *layMiniMap;
    QVBoxLayout *verticalLayout_5;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout_14;
    QStackedWidget *stackedWidget_2;
    QWidget *stackedWidget_2Page1;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *unitsLay;
    QWidget *page;
    QHBoxLayout *horizontalLayout_5;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_12;
    QVBoxLayout *unitAvatarLayout;
    QVBoxLayout *verticalLayout_13;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox_7;
    QVBoxLayout *verticalLayout_6;
    QStackedWidget *stackedWidget;
    QWidget *page_2;
    QHBoxLayout *horizontalLayout_10;
    QVBoxLayout *layControl;
    QSpacerItem *horizontalSpacer_3;
    QWidget *page_3;
    QVBoxLayout *verticalLayout_7;
    QLabel *label;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_7;
    QDoubleSpinBox *posX;
    QDoubleSpinBox *posY;
    QDoubleSpinBox *posZ;
    QLabel *label_2;
    QWidget *widget_7;
    QHBoxLayout *horizontalLayout_9;
    QDoubleSpinBox *sizeX;
    QDoubleSpinBox *sizeY;
    QDoubleSpinBox *sizeZ;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_3;
    QDoubleSpinBox *rotOZ;

    void setupUi(QWidget *GameWidget)
    {
        if (GameWidget->objectName().isEmpty())
            GameWidget->setObjectName(QString::fromUtf8("GameWidget"));
        GameWidget->resize(708, 747);
        verticalLayout_3 = new QVBoxLayout(GameWidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, -1, -1, 12);
        groupIdeBox = new QGroupBox(GameWidget);
        groupIdeBox->setObjectName(QString::fromUtf8("groupIdeBox"));
        verticalLayout = new QVBoxLayout(groupIdeBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        ideBox = new QTabWidget(groupIdeBox);
        ideBox->setObjectName(QString::fromUtf8("ideBox"));
        ideBox->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ideBox->sizePolicy().hasHeightForWidth());
        ideBox->setSizePolicy(sizePolicy);
        ideBox->setMaximumSize(QSize(150, 16777215));
        ideBox->setTabPosition(QTabWidget::South);
        ideBoxPage1 = new QWidget();
        ideBoxPage1->setObjectName(QString::fromUtf8("ideBoxPage1"));
        verticalLayout_4 = new QVBoxLayout(ideBoxPage1);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        groups = new QComboBox(ideBoxPage1);
        groups->setObjectName(QString::fromUtf8("groups"));

        verticalLayout_4->addWidget(groups);

        scrollArea = new QScrollArea(ideBoxPage1);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setWidgetResizable(true);
        buttonsBox = new QWidget();
        buttonsBox->setObjectName(QString::fromUtf8("buttonsBox"));
        buttonsBox->setGeometry(QRect(0, 0, 115, 346));
        verticalLayout_8 = new QVBoxLayout(buttonsBox);
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        widget_8 = new QWidget(buttonsBox);
        widget_8->setObjectName(QString::fromUtf8("widget_8"));
        verticalLayout_10 = new QVBoxLayout(widget_8);
        verticalLayout_10->setContentsMargins(0, 0, 0, 0);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        buildButtonsLayout = new QVBoxLayout();
        buildButtonsLayout->setSpacing(0);
        buildButtonsLayout->setObjectName(QString::fromUtf8("buildButtonsLayout"));

        verticalLayout_10->addLayout(buildButtonsLayout);


        verticalLayout_8->addWidget(widget_8);

        verticalSpacer_3 = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8->addItem(verticalSpacer_3);

        scrollArea->setWidget(buttonsBox);

        verticalLayout_4->addWidget(scrollArea);

        groupBox_3 = new QGroupBox(ideBoxPage1);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        verticalLayout_11 = new QVBoxLayout(groupBox_3);
        verticalLayout_11->setContentsMargins(0, 0, 0, 0);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        useSnap = new QCheckBox(groupBox_3);
        useSnap->setObjectName(QString::fromUtf8("useSnap"));
        useSnap->setChecked(true);

        horizontalLayout_13->addWidget(useSnap);

        pause = new QToolButton(groupBox_3);
        pause->setObjectName(QString::fromUtf8("pause"));
        pause->setIconSize(QSize(20, 20));
        pause->setCheckable(true);

        horizontalLayout_13->addWidget(pause);


        verticalLayout_11->addLayout(horizontalLayout_13);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);

        horizontalLayout_11->addWidget(label_4);

        curPl = new QComboBox(groupBox_3);
        curPl->setObjectName(QString::fromUtf8("curPl"));

        horizontalLayout_11->addWidget(curPl);


        verticalLayout_11->addLayout(horizontalLayout_11);


        verticalLayout_4->addWidget(groupBox_3);

        QIcon icon;
        icon.addFile(QString::fromUtf8("../../Game-build-desktop/pixmaps/models.png"), QSize(), QIcon::Normal, QIcon::Off);
        ideBox->addTab(ideBoxPage1, icon, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        verticalLayout_14 = new QVBoxLayout(tab_4);
        verticalLayout_14->setObjectName(QString::fromUtf8("verticalLayout_14"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        groundDown = new QToolButton(tab_4);
        groundDown->setObjectName(QString::fromUtf8("groundDown"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../../Game-build-desktop/pixmaps/mountains_down.png"), QSize(), QIcon::Normal, QIcon::Off);
        groundDown->setIcon(icon1);
        groundDown->setIconSize(QSize(32, 32));

        gridLayout_2->addWidget(groundDown, 0, 2, 1, 1);

        groundNo = new QToolButton(tab_4);
        groundNo->setObjectName(QString::fromUtf8("groundNo"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("../../Game-build-desktop/pixmaps/ecursor.png"), QSize(), QIcon::Normal, QIcon::Off);
        groundNo->setIcon(icon2);
        groundNo->setIconSize(QSize(32, 32));

        gridLayout_2->addWidget(groundNo, 0, 0, 1, 1);

        groundUp = new QToolButton(tab_4);
        groundUp->setObjectName(QString::fromUtf8("groundUp"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("../../Game-build-desktop/pixmaps/mountains_up.png"), QSize(), QIcon::Normal, QIcon::Off);
        groundUp->setIcon(icon3);
        groundUp->setIconSize(QSize(32, 32));

        gridLayout_2->addWidget(groundUp, 0, 1, 1, 1);


        verticalLayout_14->addLayout(gridLayout_2);

        frame = new QFrame(tab_4);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_15 = new QVBoxLayout(frame);
        verticalLayout_15->setObjectName(QString::fromUtf8("verticalLayout_15"));
        brushSize = new QSlider(frame);
        brushSize->setObjectName(QString::fromUtf8("brushSize"));
        brushSize->setMaximum(30);
        brushSize->setOrientation(Qt::Horizontal);

        verticalLayout_15->addWidget(brushSize);

        widget = new QWidget(frame);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout_4 = new QHBoxLayout(widget);
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        setGrass = new QToolButton(widget);
        setGrass->setObjectName(QString::fromUtf8("setGrass"));

        horizontalLayout_4->addWidget(setGrass);

        setSand = new QToolButton(widget);
        setSand->setObjectName(QString::fromUtf8("setSand"));

        horizontalLayout_4->addWidget(setSand);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);


        verticalLayout_15->addWidget(widget);


        verticalLayout_14->addWidget(frame);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_14->addItem(verticalSpacer_4);

        QIcon icon4;
        icon4.addFile(QString::fromUtf8("../../Game-build-desktop/pixmaps/mountains.png"), QSize(), QIcon::Normal, QIcon::Off);
        ideBox->addTab(tab_4, icon4, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_17 = new QVBoxLayout(tab);
        verticalLayout_17->setObjectName(QString::fromUtf8("verticalLayout_17"));
        verticalLayout_16 = new QVBoxLayout();
        verticalLayout_16->setObjectName(QString::fromUtf8("verticalLayout_16"));
        fps = new QLabel(tab);
        fps->setObjectName(QString::fromUtf8("fps"));

        verticalLayout_16->addWidget(fps);

        dipCount = new QLabel(tab);
        dipCount->setObjectName(QString::fromUtf8("dipCount"));

        verticalLayout_16->addWidget(dipCount);

        deltaTime = new QLabel(tab);
        deltaTime->setObjectName(QString::fromUtf8("deltaTime"));

        verticalLayout_16->addWidget(deltaTime);

        bathCount = new QLabel(tab);
        bathCount->setObjectName(QString::fromUtf8("bathCount"));

        verticalLayout_16->addWidget(bathCount);


        verticalLayout_17->addLayout(verticalLayout_16);

        verticalSpacer_7 = new QSpacerItem(20, 411, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_17->addItem(verticalSpacer_7);

        ideBox->addTab(tab, QString());

        verticalLayout->addWidget(ideBox);


        horizontalLayout_3->addWidget(groupIdeBox);

        mainSpacer = new QSpacerItem(0, 500, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(mainSpacer);


        verticalLayout_3->addLayout(horizontalLayout_3);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_6);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        verticalSpacer_5 = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_12->addItem(verticalSpacer_5);

        groupBox_5 = new QGroupBox(GameWidget);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setMinimumSize(QSize(200, 200));
        groupBox_5->setMaximumSize(QSize(200, 200));
        verticalLayout_2 = new QVBoxLayout(groupBox_5);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        layMiniMap = new QVBoxLayout();
        layMiniMap->setObjectName(QString::fromUtf8("layMiniMap"));

        verticalLayout_2->addLayout(layMiniMap);


        verticalLayout_12->addWidget(groupBox_5);


        horizontalLayout_2->addLayout(verticalLayout_12);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(-1, 7, -1, -1);
        verticalSpacer_2 = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        groupBox_4 = new QGroupBox(GameWidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        horizontalLayout_14 = new QHBoxLayout(groupBox_4);
        horizontalLayout_14->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        stackedWidget_2 = new QStackedWidget(groupBox_4);
        stackedWidget_2->setObjectName(QString::fromUtf8("stackedWidget_2"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(stackedWidget_2->sizePolicy().hasHeightForWidth());
        stackedWidget_2->setSizePolicy(sizePolicy2);
        stackedWidget_2Page1 = new QWidget();
        stackedWidget_2Page1->setObjectName(QString::fromUtf8("stackedWidget_2Page1"));
        verticalLayout_9 = new QVBoxLayout(stackedWidget_2Page1);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(0, 0, 0, 5);
        unitsLay = new QHBoxLayout();
        unitsLay->setObjectName(QString::fromUtf8("unitsLay"));

        verticalLayout_9->addLayout(unitsLay);

        stackedWidget_2->addWidget(stackedWidget_2Page1);
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        horizontalLayout_5 = new QHBoxLayout(page);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        stackedWidget_2->addWidget(page);

        horizontalLayout_14->addWidget(stackedWidget_2);


        horizontalLayout->addWidget(groupBox_4);

        groupBox_2 = new QGroupBox(GameWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(110, 150));
        groupBox_2->setMaximumSize(QSize(110, 200));
        horizontalLayout_12 = new QHBoxLayout(groupBox_2);
        horizontalLayout_12->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        unitAvatarLayout = new QVBoxLayout();
        unitAvatarLayout->setObjectName(QString::fromUtf8("unitAvatarLayout"));

        horizontalLayout_12->addLayout(unitAvatarLayout);


        horizontalLayout->addWidget(groupBox_2);


        verticalLayout_5->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(verticalLayout_5);

        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_13->addItem(verticalSpacer);

        groupBox_7 = new QGroupBox(GameWidget);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(groupBox_7->sizePolicy().hasHeightForWidth());
        groupBox_7->setSizePolicy(sizePolicy3);
        groupBox_7->setMinimumSize(QSize(250, 200));
        groupBox_7->setMaximumSize(QSize(215, 200));
        verticalLayout_6 = new QVBoxLayout(groupBox_7);
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        stackedWidget = new QStackedWidget(groupBox_7);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        sizePolicy3.setHeightForWidth(page_2->sizePolicy().hasHeightForWidth());
        page_2->setSizePolicy(sizePolicy3);
        horizontalLayout_10 = new QHBoxLayout(page_2);
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        layControl = new QVBoxLayout();
        layControl->setObjectName(QString::fromUtf8("layControl"));

        horizontalLayout_10->addLayout(layControl);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_3);

        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        sizePolicy1.setHeightForWidth(page_3->sizePolicy().hasHeightForWidth());
        page_3->setSizePolicy(sizePolicy1);
        verticalLayout_7 = new QVBoxLayout(page_3);
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        label = new QLabel(page_3);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_7->addWidget(label);

        widget_5 = new QWidget(page_3);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        horizontalLayout_7 = new QHBoxLayout(widget_5);
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        posX = new QDoubleSpinBox(widget_5);
        posX->setObjectName(QString::fromUtf8("posX"));
        posX->setDecimals(1);
        posX->setSingleStep(0.1);

        horizontalLayout_7->addWidget(posX);

        posY = new QDoubleSpinBox(widget_5);
        posY->setObjectName(QString::fromUtf8("posY"));
        posY->setDecimals(1);
        posY->setSingleStep(0.1);

        horizontalLayout_7->addWidget(posY);

        posZ = new QDoubleSpinBox(widget_5);
        posZ->setObjectName(QString::fromUtf8("posZ"));
        posZ->setDecimals(1);

        horizontalLayout_7->addWidget(posZ);


        verticalLayout_7->addWidget(widget_5);

        label_2 = new QLabel(page_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_7->addWidget(label_2);

        widget_7 = new QWidget(page_3);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        horizontalLayout_9 = new QHBoxLayout(widget_7);
        horizontalLayout_9->setSpacing(0);
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        sizeX = new QDoubleSpinBox(widget_7);
        sizeX->setObjectName(QString::fromUtf8("sizeX"));
        sizeX->setDecimals(1);
        sizeX->setSingleStep(0.1);
        sizeX->setValue(1);

        horizontalLayout_9->addWidget(sizeX);

        sizeY = new QDoubleSpinBox(widget_7);
        sizeY->setObjectName(QString::fromUtf8("sizeY"));
        sizeY->setDecimals(1);
        sizeY->setSingleStep(0.1);
        sizeY->setValue(1);

        horizontalLayout_9->addWidget(sizeY);

        sizeZ = new QDoubleSpinBox(widget_7);
        sizeZ->setObjectName(QString::fromUtf8("sizeZ"));
        sizeZ->setDecimals(1);
        sizeZ->setSingleStep(0.1);
        sizeZ->setValue(1);

        horizontalLayout_9->addWidget(sizeZ);


        verticalLayout_7->addWidget(widget_7);

        widget_6 = new QWidget(page_3);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        horizontalLayout_8 = new QHBoxLayout(widget_6);
        horizontalLayout_8->setSpacing(0);
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_3 = new QLabel(widget_6);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_8->addWidget(label_3);

        rotOZ = new QDoubleSpinBox(widget_6);
        rotOZ->setObjectName(QString::fromUtf8("rotOZ"));
        rotOZ->setMaximum(360);
        rotOZ->setSingleStep(10);

        horizontalLayout_8->addWidget(rotOZ);


        verticalLayout_7->addWidget(widget_6);

        stackedWidget->addWidget(page_3);

        verticalLayout_6->addWidget(stackedWidget);


        verticalLayout_13->addWidget(groupBox_7);


        horizontalLayout_2->addLayout(verticalLayout_13);


        verticalLayout_3->addLayout(horizontalLayout_2);


        retranslateUi(GameWidget);

        ideBox->setCurrentIndex(2);
        stackedWidget_2->setCurrentIndex(0);
        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(GameWidget);
    } // setupUi

    void retranslateUi(QWidget *GameWidget)
    {
        useSnap->setText(QApplication::translate("GameWidget", "\320\241\320\265\321\202\320\272\320\260", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("GameWidget", "\320\270\320\263\321\200\320\276\320\272", 0, QApplication::UnicodeUTF8));
        curPl->clear();
        curPl->insertItems(0, QStringList()
         << QApplication::translate("GameWidget", "\320\235\320\265\320\271\321\202\321\200\320\260\320\273", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GameWidget", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GameWidget", "2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GameWidget", "3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GameWidget", "4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GameWidget", "5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GameWidget", "6", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GameWidget", "7", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GameWidget", "8", 0, QApplication::UnicodeUTF8)
        );
        ideBox->setTabText(ideBox->indexOf(ideBoxPage1), QString());
        setGrass->setText(QApplication::translate("GameWidget", "g", 0, QApplication::UnicodeUTF8));
        setSand->setText(QApplication::translate("GameWidget", "s", 0, QApplication::UnicodeUTF8));
        ideBox->setTabText(ideBox->indexOf(tab_4), QString());
        fps->setText(QApplication::translate("GameWidget", "TextLabel", 0, QApplication::UnicodeUTF8));
        dipCount->setText(QApplication::translate("GameWidget", "dipCount", 0, QApplication::UnicodeUTF8));
        deltaTime->setText(QApplication::translate("GameWidget", "dt", 0, QApplication::UnicodeUTF8));
        bathCount->setText(QApplication::translate("GameWidget", "bathCount", 0, QApplication::UnicodeUTF8));
        ideBox->setTabText(ideBox->indexOf(tab), QString());
        label->setText(QApplication::translate("GameWidget", "\320\272\320\276\320\276\321\200\320\264\320\270\320\275\320\260\321\202\321\213", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("GameWidget", "\321\200\320\260\320\267\320\274\320\265\321\200\321\213", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("GameWidget", "\320\277\320\276\320\262\320\276\321\200\320\276\321\202", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(GameWidget);
    } // retranslateUi

};

namespace Ui {
    class GameWidget: public Ui_GameWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEWIDGET_H
