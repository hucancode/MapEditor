#include "Element.h"
#include <QGraphicsScene>
#include <QPixmapCache>
#include <QPainter>
#include <QBrush>
#include <QPen>
#include <QStyleOption>
#include <QXmlStreamReader>
#include <QFile>
#include <QFileInfo>
#include <QDir>
#include <iostream>
using namespace std;
Element::Element()
{
    mAnchorX = 0;
    mAnchorY = 0;
    mWidth = 1;
    mHeight = 1;
    mLinkObject = 0;
    mTexture = 0;
    mXmlFile = "";
    mLocked = false;
    if(!QPixmapCache::find("resources/childish_Lock.png",mLockTexture))
    {
        mLockTexture = new QPixmap("resources/childish_Lock.png");
    }
}

void Element::readXml(QString xmlFile)
{
    mXmlFile = xmlFile;
    QXmlStreamReader reader;
    QFile file("DA/"+xmlFile);
    QFileInfo info(file);
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
    if(reader.name()=="element")
    {
        {
            mAnchorX = reader.attributes().value("anchor_x").toString().toInt();
            mAnchorY = reader.attributes().value("anchor_y").toString().toInt();
            mWidth = reader.attributes().value("width").toString().toInt();
            mHeight = reader.attributes().value("height").toString().toInt();
            reader.readNext();// element inner text
        }
        {
            reader.readNext();// <sprites>
            int count = reader.attributes().value("count").toString().toInt();
            reader.readNext();
            //cout<<"sprite count="<<count<<endl;
            Element* lastElement = 0;
            int lastOffsetX = 0;
            int lastOffsetY = 0;
            Element* element;
            for(int i=0;i<count;i++)
            {
                reader.readNext();//<sprite>
                int offset_x = reader.attributes().value("offset_x").toString().toInt();
                int offset_y = reader.attributes().value("offset_y").toString().toInt();
                int anchor_x = reader.attributes().value("anchor_x").toString().toInt();
                int anchor_y = reader.attributes().value("anchor_y").toString().toInt();

                QString texture = info.absoluteDir().absolutePath()+"/"+
                        reader.attributes().value("texture").toString();
                element = new Element();
                element->setPos(this->x(),this->y());
                element->setFlags(QGraphicsItem::ItemSendsGeometryChanges);
                element->setOpacity(this->opacity());
                element->mAnchorX = anchor_x;
                element->mAnchorY = anchor_y;
                QPixmap* pixmap;
                if(!QPixmapCache::find(texture,pixmap))
                {
                    pixmap = new QPixmap(texture);
                }
                element->mTexture = pixmap;
                element->mWidth = pixmap->width();
                element->mHeight = pixmap->height();
                if(i==0)
                {
                    lastElement = element;
                    lastOffsetX = offset_x;
                    lastOffsetY = offset_y;
                }
                else
                {
                    element->mLinkObject = lastElement;
                    element->mLinkOffset = QPoint(lastOffsetX - offset_x, lastOffsetY - offset_y);
                    lastElement = element;
                    lastOffsetX = offset_x;
                    lastOffsetY = offset_y;
                }
                this->scene()->addItem(element);
                //cout<<this->scene()->items().count()<<endl;
                reader.readNext();// sprite inner text
                reader.readNext();// </sprite>
            }
            this->mLinkObject = lastElement;
            this->mLinkOffset = QPoint(lastOffsetX,lastOffsetY);
            reader.readNext();//</sprites>
            reader.readNext();
        }
        {
            reader.readNext();// <polygons>
            int count = reader.attributes().value("count").toString().toInt();
            reader.readNext();// polygons inner text
            //cout<<"polygon count="<<count<<endl;
            for(int i=0;i<count;i++)
            {
                reader.readNext();//<polygon>
                int vcount = reader.attributes().value("count").toString().toInt();
                reader.readNext();// polygon innertext
                QPolygon polygon;
                for(int j = 0;j<vcount;j++)
                {
                    reader.readNext();// <vertex>
                    int x = reader.attributes().value("x").toString().toInt();
                    int y = reader.attributes().value("y").toString().toInt();
                    QPoint point;
                    point.setX(x);
                    point.setY(y);
                    polygon.append(point);
                    reader.readNext();// vertex inner text
                    reader.readNext();// </vertex>
                }
                reader.readNext();//</polygon>
                reader.readNext();// polygons inner text
                mPolygons<<polygon;
                mPath.addPolygon(polygon);
            }
            reader.readNext();//</polygons>
        }
    }
    else
    {
        cout << "this is not element file"<<endl;
    }
    file.close();
    this->setZValue(10000);
    QPointF position = this->pos();
    position += mLinkOffset;
    mLinkObject->setPos(position);
}
void Element::lockUnlock()
{
    mLocked = !mLocked;
    setFlag(QGraphicsItem::ItemIsMovable,!mLocked);
}
QRectF Element::boundingRect() const
{
    return QRectF(-mAnchorX,-mAnchorY,mWidth, mHeight);
}
QPainterPath Element::shape() const
{
    return mPath;
}

void Element::paint(QPainter *painter,
                    const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);
    Q_UNUSED(option);
    if(mTexture == 0)
    {
        painter->setPen(QPen(QBrush(QColor(0,0,255)),5));
        painter->drawPoint(0,0);
    }
    else
    {
        painter->drawPixmap(-mAnchorX, -mAnchorY, mWidth, mHeight, *mTexture);
    }
    if(mLocked)
    {
        painter->drawPixmap(-24, -24, 48, 48, *mLockTexture);
        //painter->drawPixmap("resources/childish_Lock.png"
    }
    if(this->isSelected())
    {
        painter->setPen(QPen(QBrush(QColor(0,0,0,150)),1,Qt::SolidLine));
        painter->setBrush(QBrush(QColor(0,128,255,60)));
    }
    else
    {
        painter->setPen(QPen(QBrush(QColor(0,0,0,150)),1,Qt::DashLine));
        painter->setBrush(QBrush(QColor(0,128,255,30)));
    }
    painter->drawPath(mPath);
}
QVariant Element::itemChange(GraphicsItemChange change, const QVariant &value)
{
    if (change == ItemPositionHasChanged)
    {
        QPointF position = value.toPoint();
        if(mPolygons.size() == 0)
            setZValue(position.y());
        if(mLinkObject)
        {
            position += mLinkOffset;
            mLinkObject->setPos(position);
        }
    }
    return QGraphicsItem::itemChange(change, value);
}
