#include "Mapview.h"

#include <QScrollBar>
#include <iostream>
#include <QFile>
#include <QFileInfo>
#include <QXmlStreamWriter>
#include <iostream>
using namespace std;


MapView::MapView(QWidget *parent) :
    QGraphicsView(parent)
{
    hold = false;
    currentElement = 0;
    mapSolver = 0;
    tileMatrix = 0;
    initContextMenu();
}
void MapView::initContextMenu()
{
    lockUnlockAct = new QAction(tr("&Lock/Unlock"), this);
    lockUnlockAct->setStatusTip(tr("Lock/Unlock Element"));
    connect(lockUnlockAct, SIGNAL(triggered()), this, SLOT(doLockUnlock()));
    contextMenu.addAction(lockUnlockAct);
    cutAct = new QAction(tr("Cu&t"), this);
    cutAct->setStatusTip(tr("Cut"));
    connect(cutAct, SIGNAL(triggered()), this, SLOT(doCut()));
    contextMenu.addAction(cutAct);
    copyAct = new QAction(tr("&Copy"), this);
    copyAct->setStatusTip(tr("Copy"));
    connect(copyAct, SIGNAL(triggered()), this, SLOT(doCopy()));
    contextMenu.addAction(copyAct);
    pasteAct = new QAction(tr("&Paste"), this);
    pasteAct->setStatusTip(tr("Paste"));
    connect(pasteAct, SIGNAL(triggered()), this, SLOT(doPaste()));
    contextMenu.addAction(pasteAct);
    delAct = new QAction(tr("D&elete"), this);
    delAct->setStatusTip(tr("Delete element"));
    connect(delAct, SIGNAL(triggered()), this, SLOT(doDelete()));
    contextMenu.addAction(delAct);
}
void MapView::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        if(mode==CREATE_ELEMENT)
        {
            if(currentXml == "") return;
            int off_y = this->verticalScrollBar()->value();
            int off_x = this->horizontalScrollBar()->value();
            createElement(event->x()+off_x,event->y()+off_y, currentXml);
            if(!hold)
            {
                trackElementFalse();
                mode = EDIT_ELEMENT;
                emit drawModeChanged();
            }
        }
        else if(mode==EDIT_ELEMENT)
        {
            QGraphicsView::mousePressEvent(event);
            if(hold)
            {
                foreach(QGraphicsItem* item, scene()->selectedItems())
                {
                    Element* element = (Element*)item;
                    createElement(element->x(),element->y(),element->mXmlFile);
                }
                //std::cout<<"scene item count "<<this->scene()->items().size()<<std::endl;
            }
        }
        else if(mode == CREATE_TILE)
        {
            int off_y = this->verticalScrollBar()->value();
            int off_x = this->horizontalScrollBar()->value();
            int gx = (event->x()+off_x)/64;
            int gy = (event->y()+off_y)/64;
            setTileA(gx,gy);
        }
    }
    else
    {
        if(mode == EDIT_ELEMENT)
        {
            contextMenu.exec(event->globalPos());
        }
        else if(mode == CREATE_TILE)
        {
            int off_y = this->verticalScrollBar()->value();
            int off_x = this->horizontalScrollBar()->value();
            int gx = (event->x()+off_x)/64;
            int gy = (event->y()+off_y)/64;
            setTileB(gx,gy);
        }
    }
}

void MapView::mouseMoveEvent(QMouseEvent *event)
{
    if(currentElement && mode == CREATE_ELEMENT)
    {
        int off_y = this->verticalScrollBar()->value();
        int off_x = this->horizontalScrollBar()->value();
        currentElement->setPos(event->x()+off_x,event->y()+off_y);
    }
    QGraphicsView::mouseMoveEvent(event);
}

void MapView::mouseReleaseEvent(QMouseEvent *event)
{
    QGraphicsView::mouseReleaseEvent(event);
}
void MapView::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Shift)
    {
        hold = true;
    }
    QGraphicsView::keyPressEvent(event);
}

void MapView::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Shift)
    {
        hold = false;
    }
    QGraphicsView::keyReleaseEvent(event);
}

void MapView::paintEvent(QPaintEvent *event)
{
    QGraphicsView::paintEvent(event);

}
void MapView::drawForeground(QPainter *painter, const QRectF &rect)
{
    QGraphicsView::drawForeground(painter,rect);
    return;
    if(mode== CREATE_TILE)
    {
        painter->setPen(QPen(QBrush(QColor(0,0,0,200)),1));
        for(int i=0;i<width();i+=64)
        {
            painter->drawLine(QPoint(i,0),QPoint(i,rect.height()));
        }
        for(int j = 0;j<height();j+=64)
        {
            painter->drawLine(QPoint(0,j),QPoint(rect.width(),j));
        }
    }
}
void MapView::clearMap()
{
    scene()->clear();
    gridHeight = 1;
    gridWidth = 1;
    mapSolver = 0;
    currentElement = 0;
    tileMatrix = 0;
    hold = false;
}

void MapView::loadXml(QString xmlFile)
{
    clearMap();
    QXmlStreamReader reader;
    QFile file(xmlFile);
    if (!file.open(QFile::ReadOnly | QFile::Text))
    {
        cout << "Error: Cannot read file " << qPrintable(xmlFile)
                  << ": " << qPrintable(file.errorString())
                  << endl;
    }
    reader.setDevice(&file);
    reader.readNext();
    if(reader.isStartDocument())
        reader.readNext();
    if(reader.name()=="map")
    {
        reader.readNext();// map inner text
        {
            reader.readNext();// <elements>
            int count = reader.attributes().value("count").toString().toInt();
            reader.readNext();// elements inner text
            for(int i=0;i<count;i++)
            {
                reader.readNext();//<element>
                QString file = reader.attributes().value("file").toString();
                int x = reader.attributes().value("x").toString().toInt();
                int y = reader.attributes().value("y").toString().toInt();
                createElement(x, y, file);
                reader.readNext();// element inner text
                reader.readNext();// </element>
            }
            reader.readNext();// </elements>
        }
        reader.readNext();// map inner text
        {
            reader.readNext();// <tiles>
            tileSet = reader.attributes().value("tileset").toString();
            int w = reader.attributes().value("width").toString().toInt();
            int h = reader.attributes().value("height").toString().toInt();
            resize(w,h);
            int count = reader.attributes().value("count").toString().toInt();
            reader.readNext();// tiles inner text
            for(int i=0;i<count;i++)
            {
                reader.readNext();//<tile>
                int id = reader.attributes().value("id").toString().toInt();
                int x = reader.attributes().value("x").toString().toInt();
                int y = reader.attributes().value("y").toString().toInt();
                setTileID(x,y,id);
                reader.readNext();// tile inner text
                reader.readNext();// </tile>
            }
            reader.readNext();// tiles inner text
            reader.readNext();// </tiles>
        }
    }
    else
    {
        cout << "this is not map file"<<endl;
    }
    file.close();
}

void MapView::saveXml(QString xmlFile)
{
    QXmlStreamWriter writer;
    QFile file(xmlFile);
    if (!file.open(QFile::WriteOnly | QFile::Text))
    {
        cout << "Error: Cannot read file " << qPrintable(xmlFile)
                  << ": " << qPrintable(file.errorString())
                  << endl;
    }
    writer.setAutoFormatting(true);
    writer.setDevice(&file);
    writer.writeStartDocument();
    writer.writeStartElement("map");
    {
        writer.writeStartElement("elements");
        int count = 0;
        foreach(QGraphicsItem* item, scene()->items())
        {
            if(!item->flags().testFlag(QGraphicsItem::ItemIsSelectable)) continue;
            if(item == currentElement) continue;
            count++;
        }
        writer.writeAttribute("count",QString::number(count));
        foreach(QGraphicsItem* item, scene()->items())
        {
            if(!item->flags().testFlag(QGraphicsItem::ItemIsSelectable)) continue;
            if(item == currentElement) continue;
            Element* element = (Element*)item;
            writer.writeStartElement("element");
            writer.writeAttribute("file",element->getXmlFile());
            writer.writeAttribute("x",QString::number(element->x()));
            writer.writeAttribute("y",QString::number(element->y()));
            writer.writeEndElement();
        }
        writer.writeEndElement();
        writer.writeStartElement("tiles");
        writer.writeAttribute("width",QString::number(gridWidth));
        writer.writeAttribute("height",QString::number(gridHeight));
        writer.writeAttribute("tileset",tileSet);
        count = 0;
        for(int i=0;i<gridWidth;i++)
        {
            for(int j = 0;j<gridHeight;j++)
            {
                int id = mapSolver->GetTileID(i,j);
                if(id == 14) continue;
                count++;
            }
        }
        writer.writeAttribute("count",QString::number(count));
        for(int i=0;i<gridWidth;i++)
        {
            for(int j = 0;j<gridHeight;j++)
            {
                int id = mapSolver->GetTileID(i,j);
                if(id == 14) continue;
                writer.writeStartElement("tile");
                writer.writeAttribute("x",QString::number(i));
                writer.writeAttribute("y",QString::number(j));
                writer.writeAttribute("id",QString::number(id));
                writer.writeEndElement();
            }
        }
        writer.writeEndElement();
    }
    writer.writeEndElement();
    writer.writeEndDocument();
    file.close();
}

void MapView::resize(int width, int height)
{
    if(width == gridWidth && height == gridHeight) return;
    scene()->items().clear();
    scene()->setSceneRect( 0, 0, width*64, height*64 );
    if(!tileMatrix)
    {
        tileMatrix = new Tile**[width];
        for(int i=0;i<width;i++)
        {
            tileMatrix[i] = new Tile*[height];
            for(int j=0;j<height;j++)
            {
                tileMatrix[i][j] = 0;
            }
        }
        mapSolver = new Tilemap(width, height);
    }
    else
    {
        mapSolver->Resize(width, height);
        Tile*** pMatrix = new Tile**[width];
        for(int i=0;i<width;i++)
        {
            pMatrix[i] = new Tile*[height];
            for(int j=0;j<height;j++)
            {
                if(i < gridWidth && j < gridHeight)
                {
                    pMatrix[i][j] = tileMatrix[i][j];
                    if(tileMatrix[i][j])
                        scene()->addItem(pMatrix[i][j]);
                }
                else
                {
                    pMatrix[i][j] = 0;
                }
            }
            if(i<gridWidth)
            {
                delete tileMatrix[i];
            }
        }
        tileMatrix = pMatrix;
    }

    gridWidth = width;
    gridHeight = height;
}

void MapView::setTileA(int x, int y)
{
    if(x < 3 || y < 3 || x > gridWidth - 4 || y > gridHeight - 4) return;
    // calculate transition
    mapSolver->SetTileA(x,y);
    // do render
    for(int i=-1;i<=1;i++)
    {
        for(int j = -1;j<=1;j++)
        {
            int xi = x+i;
            int yj = y+j;
            if(!tileMatrix[xi][yj])
            {
                tileMatrix[xi][yj] = new Tile();
                scene()->addItem(tileMatrix[xi][yj]);
                tileMatrix[xi][yj]->setPos(xi*64,yj*64);
            }
            tileMatrix[xi][yj]->
                    setTexture("DA/resources.pak/terrain/"+tileSet+"-"+
                               QString::number(mapSolver->GetTileID(xi,yj))+".png");
        }
    }
    // repaint the area that change
    scene()->invalidate((x-1)*64,(y-1)*64,192,192);
}

void MapView::setTileID(int x, int y, int id)
{
    if(x < 0 || y < 0 || x > gridWidth - 1 || y > gridHeight - 1) return;
    mapSolver->SetTileID(x,y,id);
    if(id==5) mapSolver->SetTileID(x,y,true);
    if(!tileMatrix[x][y])
    {
        tileMatrix[x][y] = new Tile();
        scene()->addItem(tileMatrix[x][y]);
        tileMatrix[x][y]->setPos(x*64,y*64);
    }
    tileMatrix[x][y]->
            setTexture("DA/resources.pak/terrain/"+tileSet+"-"+
                       QString::number(id)+".png");
    scene()->invalidate(x*64,y*64,64,64);
}

void MapView::setTileB(int x, int y)
{
    if(x < 3 || y < 3 || x > gridWidth - 4 || y> gridHeight - 4) return;
    // calculate transition
    mapSolver->SetTileB(x,y);
    // do render
    for(int i=-1;i<=1;i++)
    {
        for(int j = -1;j<=1;j++)
        {
            int xi = x+i;
            int yj = y+j;
            if(tileMatrix[xi][yj])
            {
                short id = mapSolver->GetTileID(xi,yj);
                if(id == 14 ||
                        id == 34 ||
                        id == 54)
                {
                    scene()->items().removeOne(tileMatrix[xi][yj]);
                    delete tileMatrix[xi][yj];
                    tileMatrix[xi][yj] = 0;
                }
                else
                {
                    tileMatrix[xi][yj]->
                            setTexture("DA/resources.pak/terrain/"+tileSet+"-"+
                                       QString::number(id)+".png");
                }
            }
        }
    }
    // repaint the area that change
    scene()->invalidate((x-1)*64,(y-1)*64,192,192);
}



void MapView::setTileset(QString name)
{
    tileSet = name;
    QPixmap pixmap(64*2,64*2);
    QPainter painter(&pixmap);
    painter.drawPixmap(0,0,64,64,
                       QPixmap("DA/resources.pak/terrain/"+tileSet+"-14.png"));
    painter.drawPixmap(64,0,64,64,
                       QPixmap("DA/resources.pak/terrain/"+tileSet+"-34.png"));
    painter.drawPixmap(64,64,64,64,
                       QPixmap("DA/resources.pak/terrain/"+tileSet+"-54.png"));
    painter.drawPixmap(0,64,64,64,
                       QPixmap("DA/resources.pak/terrain/"+tileSet+"-14.png"));
    this->setBackgroundBrush(pixmap);
}

void MapView::setElement(QString xmlFile)
{
    currentXml = xmlFile;
    if(currentElement)
    {
        this->scene()->removeItem(currentElement);
        currentElement = currentElement->mLinkObject;
        while(currentElement)
        {
            this->scene()->removeItem(currentElement);
            currentElement = currentElement->mLinkObject;
        }
    }
    currentElement = new Element();
    currentElement->setFlags(QGraphicsItem::ItemIsMovable |
                      QGraphicsItem::ItemSendsGeometryChanges);
    currentElement->setOpacity(0.5);
    this->scene()->addItem(currentElement);
    currentElement->readXml(xmlFile);
    if(mode != CREATE_ELEMENT)
    {
        trackElementTrue();
        mode = CREATE_ELEMENT;
        emit drawModeChanged();
    }
}
void MapView::trackElementTrue()
{
    if(!currentElement) return;
    this->setMouseTracking(true);
    currentElement->setVisible(true);
    Element* element = currentElement;
    element = element->mLinkObject;
    while(element)
    {
        element->setVisible(true);
        element = element->mLinkObject;
    }
}

void MapView::trackElementFalse()
{
    if(!currentElement) return;
    this->setMouseTracking(false);
    currentElement->setVisible(false);
    Element* element = currentElement;
    element = element->mLinkObject;
    while(element)
    {
        element->setVisible(false);
        element = element->mLinkObject;
    }
}

void MapView::setDrawMode(DRAW_MODE mode)
{
    if(mode == this->mode) return;
    if(mode == CREATE_ELEMENT)
    {
        trackElementTrue();
    }
    else
    {
        trackElementFalse();
    }
    this->mode = mode;
    emit drawModeChanged();
}

void MapView::createElement(int x, int y, QString xml)
{
    Element* element = new Element();
    element->setPos(x,y);
    element->setFlags(QGraphicsItem::ItemIsMovable |
                      QGraphicsItem::ItemIsSelectable |
                      QGraphicsItem::ItemIsFocusable |
                      QGraphicsItem::ItemSendsGeometryChanges);
    this->scene()->addItem(element);
    element->readXml(xml);
}



void MapView::doLockUnlock()
{
    foreach(QGraphicsItem* item, scene()->selectedItems())
    {
        Element* element = (Element*)item;
        element->lockUnlock();
    }
}

void MapView::doCut()
{
    doCopy();
    doDelete();
}

void MapView::doCopy()
{
    clipElement.clear();
    foreach(QGraphicsItem* item, scene()->selectedItems())
    {
        Element* element = (Element*)item;
        clipElement<<element;
    }
}

void MapView::doPaste()
{
    if(clipElement.count()==0) return;
    int paste_x = this->horizontalScrollBar()->value()
            +this->width()/2;
    int paste_y = this->verticalScrollBar()->value()
            +this->height()/2;
    int mid_x = 0;
    int mid_y = 0;
    foreach(Element* item, clipElement)
    {
        mid_x += item->x();
        mid_y += item->y();
    }
    mid_x /= clipElement.count();
    mid_y /= clipElement.count();
    int off_x = paste_x - mid_x;
    int off_y = paste_y - mid_y;
    foreach(Element* item, clipElement)
    {
        int x = item->x() + off_x;
        int y = item->y() + off_y;
        createElement(x,y,item->mXmlFile);
    }
}

void MapView::doDelete()
{
    foreach(QGraphicsItem* item, scene()->selectedItems())
    {
        Element* element = (Element*)item;
        element = element->mLinkObject;
        while(element)
        {
            this->scene()->removeItem(element);
            element = element->mLinkObject;
        }
        this->scene()->removeItem(item);
    }
}
