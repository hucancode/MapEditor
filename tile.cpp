#include "tile.h"
#include <QPixmapCache>
#include <QPainter>
Tile::Tile()
{
    mPath.addRect(0,0,64,64);
}
void Tile::setTexture(QString texturePath)
{
    if(!QPixmapCache::find(texturePath,mTexture))
    {
        mTexture = new QPixmap(texturePath);
    }
}
QRectF Tile::boundingRect() const
{
    return QRectF(0,0,64,64);
}
QPainterPath Tile::shape() const
{
    return mPath;
}
void Tile::paint(QPainter *painter,
                    const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);
    Q_UNUSED(option);
    painter->drawPixmap(0,0,64,64,*mTexture);
    painter->setPen(QPen(QBrush(QColor(0,0,0,80)),1,Qt::DashLine));
    painter->drawRect(0,0,64,64);
}
