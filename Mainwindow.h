#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QModelIndexList>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT
public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

    void initScene();
    void initListItem();
    void initTerrainList();
private slots:


    void on_listWidget_currentRowChanged(int currentRow);

    void on_actionEdit_triggered();

    void on_actionCreate_triggered();

    void on_graphicsView_drawModeChanged();

    void on_actionAbout_triggered();

    void on_actionTerrain_triggered();

    void on_actionSave_triggered();

    void on_actionOpen_triggered();

    void on_comboTileset_currentIndexChanged(int index);

    void on_btnResize_clicked();

    void on_actionNew_triggered();

private:
	Ui::MainWindow *ui;
    QGraphicsScene *scene;
};

#endif // MAINWINDOW_H
