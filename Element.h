#ifndef ELEMENT_H
#define ELEMENT_H

#include <QGraphicsItem>
#include <QString>
#include <QList>

class Element : public QGraphicsItem
{
    friend class MapView;
private:
    int mAnchorX;
    int mAnchorY;
    int mWidth;
    int mHeight;
    bool mLocked;
    QPixmap* mTexture;
    QPixmap* mLockTexture;
    QList<QPolygon> mPolygons;
    QPainterPath mPath;
    Element* mLinkObject;
    QPoint mLinkOffset;
    QString mXmlFile;
public:
    Element();
    void readXml(QString);
    void lockUnlock();
    QString getXmlFile(){return mXmlFile;}
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option, QWidget *widget);
    QVariant Element::itemChange(GraphicsItemChange change, const QVariant &value);
};

#endif // ELEMENT_H
