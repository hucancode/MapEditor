/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Wed Jul 17 15:05:47 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

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
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "mapview.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionNew;
    QAction *actionSave;
    QAction *actionExit;
    QAction *actionOption;
    QAction *actionAbout;
    QAction *actionCut;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionDelete;
    QAction *actionEdit;
    QAction *actionCreate;
    QAction *actionTerrain;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_2;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QComboBox *comboTileset;
    QComboBox *comboTileID;
    QComboBox *comboBrush;
    QSpinBox *spinRadius;
    QLabel *label;
    QGroupBox *groupBox_2;
    QSpinBox *spinWidth;
    QSpinBox *spinHeight;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *btnResize;
    QListWidget *listWidget;
    MapView *graphicsView;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuTool;
    QMenu *menuHelp;
    QMenu *menuEdit;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/resources/childish_Folder.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icon/resources/childish_File.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew->setIcon(icon1);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icon/resources/childish_Floppy-Disk.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon2);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionOption = new QAction(MainWindow);
        actionOption->setObjectName(QString::fromUtf8("actionOption"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icon/resources/childish_Gears.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOption->setIcon(icon3);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionCut = new QAction(MainWindow);
        actionCut->setObjectName(QString::fromUtf8("actionCut"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icon/resources/cut.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCut->setIcon(icon4);
        actionCopy = new QAction(MainWindow);
        actionCopy->setObjectName(QString::fromUtf8("actionCopy"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icon/resources/childish_News.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCopy->setIcon(icon5);
        actionPaste = new QAction(MainWindow);
        actionPaste->setObjectName(QString::fromUtf8("actionPaste"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icon/resources/childish_Clipboard.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPaste->setIcon(icon6);
        actionDelete = new QAction(MainWindow);
        actionDelete->setObjectName(QString::fromUtf8("actionDelete"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/icon/resources/childish_Cross.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDelete->setIcon(icon7);
        actionEdit = new QAction(MainWindow);
        actionEdit->setObjectName(QString::fromUtf8("actionEdit"));
        actionEdit->setCheckable(true);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/icon/resources/childish_Tool.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionEdit->setIcon(icon8);
        actionEdit->setShortcutContext(Qt::WindowShortcut);
        actionCreate = new QAction(MainWindow);
        actionCreate->setObjectName(QString::fromUtf8("actionCreate"));
        actionCreate->setCheckable(true);
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/icon/resources/childish_Image.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCreate->setIcon(icon9);
        actionCreate->setShortcutContext(Qt::WindowShortcut);
        actionTerrain = new QAction(MainWindow);
        actionTerrain->setObjectName(QString::fromUtf8("actionTerrain"));
        actionTerrain->setCheckable(true);
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/icon/resources/childish_Brush.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionTerrain->setIcon(icon10);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setEnabled(true);
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(3, 3, 3, 3);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        frame_2 = new QFrame(frame);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setMinimumSize(QSize(165, 0));
        frame_2->setMaximumSize(QSize(165, 16777215));
        frame_2->setAutoFillBackground(false);
        frame_2->setFrameShape(QFrame::Panel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame_2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(frame_2);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(0, 150));
        comboTileset = new QComboBox(groupBox);
        comboTileset->setObjectName(QString::fromUtf8("comboTileset"));
        comboTileset->setGeometry(QRect(10, 20, 121, 22));
        comboTileID = new QComboBox(groupBox);
        comboTileID->setObjectName(QString::fromUtf8("comboTileID"));
        comboTileID->setGeometry(QRect(10, 50, 121, 22));
        comboBrush = new QComboBox(groupBox);
        comboBrush->setObjectName(QString::fromUtf8("comboBrush"));
        comboBrush->setGeometry(QRect(10, 80, 121, 22));
        spinRadius = new QSpinBox(groupBox);
        spinRadius->setObjectName(QString::fromUtf8("spinRadius"));
        spinRadius->setGeometry(QRect(71, 110, 61, 22));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(15, 114, 46, 13));

        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(frame_2);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(0, 120));
        spinWidth = new QSpinBox(groupBox_2);
        spinWidth->setObjectName(QString::fromUtf8("spinWidth"));
        spinWidth->setGeometry(QRect(70, 20, 61, 22));
        spinWidth->setMinimum(20);
        spinWidth->setMaximum(300);
        spinWidth->setValue(20);
        spinHeight = new QSpinBox(groupBox_2);
        spinHeight->setObjectName(QString::fromUtf8("spinHeight"));
        spinHeight->setGeometry(QRect(70, 50, 61, 22));
        spinHeight->setMinimum(20);
        spinHeight->setMaximum(300);
        spinHeight->setValue(20);
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 20, 46, 21));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 50, 46, 21));
        btnResize = new QPushButton(groupBox_2);
        btnResize->setObjectName(QString::fromUtf8("btnResize"));
        btnResize->setGeometry(QRect(10, 80, 121, 31));
        QFont font;
        font.setPointSize(8);
        btnResize->setFont(font);

        verticalLayout->addWidget(groupBox_2);

        listWidget = new QListWidget(frame_2);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setMaximumSize(QSize(150, 16777215));
        listWidget->setViewMode(QListView::IconMode);

        verticalLayout->addWidget(listWidget);


        horizontalLayout_2->addWidget(frame_2);

        graphicsView = new MapView(frame);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy);
        graphicsView->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_2->addWidget(graphicsView);


        horizontalLayout->addWidget(frame);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 21));
        menuBar->setDefaultUp(false);
        menuBar->setNativeMenuBar(true);
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuTool = new QMenu(menuBar);
        menuTool->setObjectName(QString::fromUtf8("menuTool"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setMovable(false);
        toolBar->setIconSize(QSize(32, 32));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuTool->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuTool->addAction(actionOption);
        menuHelp->addAction(actionAbout);
        menuEdit->addAction(actionCut);
        menuEdit->addAction(actionCopy);
        menuEdit->addAction(actionPaste);
        menuEdit->addAction(actionDelete);
        toolBar->addAction(actionNew);
        toolBar->addAction(actionOpen);
        toolBar->addAction(actionSave);
        toolBar->addSeparator();
        toolBar->addAction(actionCreate);
        toolBar->addAction(actionEdit);
        toolBar->addAction(actionTerrain);
        toolBar->addSeparator();
        toolBar->addAction(actionCut);
        toolBar->addAction(actionCopy);
        toolBar->addAction(actionPaste);
        toolBar->addAction(actionDelete);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Bamboo Map Editor", 0, QApplication::UnicodeUTF8));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionOpen->setToolTip(QApplication::translate("MainWindow", "Open(CTRL+O)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionOpen->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0, QApplication::UnicodeUTF8));
        actionNew->setText(QApplication::translate("MainWindow", "New", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionNew->setToolTip(QApplication::translate("MainWindow", "New(CTRL+N)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionNew->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", 0, QApplication::UnicodeUTF8));
        actionSave->setText(QApplication::translate("MainWindow", "Save", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionSave->setToolTip(QApplication::translate("MainWindow", "Save(CTRL+S)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionSave->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        actionOption->setText(QApplication::translate("MainWindow", "Option", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("MainWindow", "About", 0, QApplication::UnicodeUTF8));
        actionCut->setText(QApplication::translate("MainWindow", "Cut", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionCut->setToolTip(QApplication::translate("MainWindow", "Cut(CTRL+X)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionCut->setShortcut(QApplication::translate("MainWindow", "Ctrl+X", 0, QApplication::UnicodeUTF8));
        actionCopy->setText(QApplication::translate("MainWindow", "Copy", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionCopy->setToolTip(QApplication::translate("MainWindow", "Copy(CTRL+C)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionCopy->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", 0, QApplication::UnicodeUTF8));
        actionPaste->setText(QApplication::translate("MainWindow", "Paste", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionPaste->setToolTip(QApplication::translate("MainWindow", "Paste(CTRL+V)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionPaste->setShortcut(QApplication::translate("MainWindow", "Ctrl+V", 0, QApplication::UnicodeUTF8));
        actionDelete->setText(QApplication::translate("MainWindow", "Delete", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionDelete->setToolTip(QApplication::translate("MainWindow", "Delete (DEL)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionDelete->setShortcut(QApplication::translate("MainWindow", "Del", 0, QApplication::UnicodeUTF8));
        actionEdit->setText(QApplication::translate("MainWindow", "Edit", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionEdit->setToolTip(QApplication::translate("MainWindow", "Edit object(E)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionEdit->setShortcut(QApplication::translate("MainWindow", "E", 0, QApplication::UnicodeUTF8));
        actionCreate->setText(QApplication::translate("MainWindow", "Create", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionCreate->setToolTip(QApplication::translate("MainWindow", "Create object(R)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionCreate->setShortcut(QApplication::translate("MainWindow", "R", 0, QApplication::UnicodeUTF8));
        actionTerrain->setText(QApplication::translate("MainWindow", "terrain", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionTerrain->setToolTip(QApplication::translate("MainWindow", "Paint terrain(T)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionTerrain->setShortcut(QApplication::translate("MainWindow", "T", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "Paint", 0, QApplication::UnicodeUTF8));
        comboTileID->clear();
        comboTileID->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "A", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "B", 0, QApplication::UnicodeUTF8)
        );
        comboBrush->clear();
        comboBrush->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Rectangle", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Eclipse", 0, QApplication::UnicodeUTF8)
        );
        label->setText(QApplication::translate("MainWindow", "Radius", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Resize", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Width", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Height", 0, QApplication::UnicodeUTF8));
        btnResize->setText(QApplication::translate("MainWindow", "OK", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuTool->setTitle(QApplication::translate("MainWindow", "Tool", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
