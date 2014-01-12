#ifndef MAPVIEW_H
#define MAPVIEW_H

#include <QWidget>
#include <QGraphicsView>
#include <QMouseEvent>
#include <QString>
#include <QMenu>
#include "Element.h"
#include "tile.h"
#include "Tilemap.h"
enum DRAW_MODE
{
    CREATE_ELEMENT,
    EDIT_ELEMENT,
    CREATE_TILE
};

class MapView : public QGraphicsView
{
    Q_OBJECT
private:
    QString currentXml;
    Element* currentElement;
    DRAW_MODE mode;
    bool hold;

    Tilemap* mapSolver;
    int gridWidth;
    int gridHeight;
    QString tileSet;
    Tile*** tileMatrix;

    QMenu contextMenu;
    QAction *lockUnlockAct;
    QAction *cutAct;
    QAction *copyAct;
    QAction *pasteAct;
    QAction *delAct;
    QList<Element*> clipElement;
public:
    explicit MapView(QWidget *parent = 0);
    void setTileset(QString name);
    void setTileA(int x, int y);
    void setTileB(int x, int y);
    void setTileID(int x, int y, int id);
    void resize(int width, int height);

    void setElement(QString xmlFile);
    void setDrawMode(DRAW_MODE mode);
    DRAW_MODE getDrawMode(){ return mode;}
    void createElement(int x, int y, QString xml);
    void trackElementTrue();
    void trackElementFalse();

    void saveXml(QString xmlFile);
    void loadXml(QString xmlFile);
    void clearMap();
    void initContextMenu();
signals:
    void drawModeChanged();
protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void drawForeground(QPainter *painter, const QRectF &rect);
private slots:
     void doLockUnlock();
     void doCut();
     void doCopy();
     void doPaste();
     void doDelete();
};

#endif // MAPVIEW_H
