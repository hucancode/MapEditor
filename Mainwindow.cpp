#include "Mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileInfoList>
#include <QFileInfo>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QFileDialog>

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>

#include "Element.h"
#include "Mapview.h"
#include <iostream>
using namespace std;
void MainWindow::initListItem()
{
    QDir rootDir("DA/resources.pak");
    rootDir.setFilter(QDir::Dirs);
    foreach(QString entry, rootDir.entryList())
    {
        QDir childDir = QDir(rootDir.absolutePath()+"/"+entry);
        //cout<<"child dir: "<<qPrintable(childDir.absolutePath())<<endl;
        childDir.setFilter(QDir::Files);
        childDir.setNameFilters(QStringList("*.xml"));
        foreach(QString pngEntry, childDir.entryList())
        {
            QString path = childDir.absolutePath()+"/"+pngEntry;
            //cout<<"entry: "<<qPrintable(path)<<endl;
            QListWidgetItem *item = new QListWidgetItem(ui->listWidget);
            item->setText("resources.pak/"+entry+"/"+pngEntry);
            //item->setIcon();
        }
    }
}

void MainWindow::initScene()
{

    scene = new QGraphicsScene(this);
    //scene->setSceneRect(scene->itemsBoundingRect());
    ui->graphicsView->setScene(scene);
    ui->graphicsView->resize(20,20);
    ui->graphicsView->show();
    ui->graphicsView->setDragMode(QGraphicsView::NoDrag);
    ui->graphicsView->setTileset("375");
    connect(ui->actionDelete,SIGNAL(triggered()),ui->graphicsView,SLOT(doDelete()));
    connect(ui->actionCopy,SIGNAL(triggered()),ui->graphicsView,SLOT(doCopy()));
    connect(ui->actionCut,SIGNAL(triggered()),ui->graphicsView,SLOT(doCut()));
    connect(ui->actionPaste,SIGNAL(triggered()),ui->graphicsView,SLOT(doPaste()));
}

void MainWindow::initTerrainList()
{
    QFile file("DA/terrain_list.txt");
    if (!file.open(QFile::ReadOnly | QFile::Text))
    {
        cout << "Error: Cannot read file " << qPrintable("DA/terrain_list.txt")
                  << ": " << qPrintable(file.errorString())
                  << endl;
    }
    QTextStream stream( &file );
    while (!stream.atEnd())
    {
        QString line = stream.readLine();
        ui->comboTileset->addItem(line);
    }
    file.close();
}

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initListItem();
    initScene();
    initTerrainList();
}
MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::on_listWidget_currentRowChanged(int currentRow)
{
    Q_UNUSED(currentRow);
    QListWidgetItem* item = ui->listWidget->currentItem();
    ui->graphicsView->setElement(item->text());
}

void MainWindow::on_actionEdit_triggered()
{
    ui->graphicsView->setDrawMode(EDIT_ELEMENT);
    ui->graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);
}

void MainWindow::on_actionCreate_triggered()
{
    ui->graphicsView->setDrawMode(CREATE_ELEMENT);
    ui->graphicsView->setDragMode(QGraphicsView::NoDrag);
}
void MainWindow::on_actionTerrain_triggered()
{
    ui->graphicsView->setDrawMode(CREATE_TILE);
    ui->graphicsView->setDragMode(QGraphicsView::NoDrag);
}
void MainWindow::on_graphicsView_drawModeChanged()
{
    DRAW_MODE mode = ui->graphicsView->getDrawMode();
    if(mode == CREATE_ELEMENT)
    {
        ui->toolBar->actions().at(4)->setChecked(true);
        ui->toolBar->actions().at(5)->setChecked(false);
        ui->toolBar->actions().at(6)->setChecked(false);
        ui->statusBar->showMessage("create mode");
    }
    else if(mode == EDIT_ELEMENT)
    {
        ui->toolBar->actions().at(4)->setChecked(false);
        ui->toolBar->actions().at(5)->setChecked(true);
        ui->toolBar->actions().at(6)->setChecked(false);
        ui->statusBar->showMessage("edit mode");
    }
    else
    {
        ui->toolBar->actions().at(4)->setChecked(false);
        ui->toolBar->actions().at(5)->setChecked(false);
        ui->toolBar->actions().at(6)->setChecked(true);
        ui->statusBar->showMessage("paint mode");
    }
}


void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::about(this,"About","Too lazy to do this.");
}


void MainWindow::on_actionSave_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this,"Save file","","*.xml");
    ui->graphicsView->saveXml(fileName);
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,"Open file","","*.xml");
    ui->graphicsView->loadXml(fileName);
}

void MainWindow::on_comboTileset_currentIndexChanged(int index)
{
    Q_UNUSED(index);
    ui->graphicsView->setTileset(ui->comboTileset->currentText());
}

void MainWindow::on_btnResize_clicked()
{
    ui->graphicsView->resize(ui->spinWidth->value(),
                             ui->spinHeight->value());
}

void MainWindow::on_actionNew_triggered()
{
    ui->graphicsView->clearMap();
}
