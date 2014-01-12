#ifndef TILE_H
#define TILE_H

#include <QGraphicsItem>

class Tile : public QGraphicsItem
{
private:
    QPixmap* mTexture;
    QPainterPath mPath;
public:
    Tile();
    void setTexture(QString);
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option, QWidget *widget);
};
#endif // TILE_H
