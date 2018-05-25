#pragma once
#include <QGraphicsItem>

class Car : public QGraphicsItem
{
  public:
    Car(QGraphicsItem* parent = 0);
    ~Car();

    QRectF boundingRect() const;

    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
    inline int getWidth()
    {
        return w_;
    }
    inline int getHeight()
    {
        return h_;
    }

  private:
    // width and height of car in graphics
    int w_, h_;
    // if the car has decided the direction to go at crossing
    bool dire_decided_;
    // speed of car(1-5)
    float speed_;
    // unit vector
    QPoint direction_;
    // TODO(daiz) use a counter to change speed after some time
};