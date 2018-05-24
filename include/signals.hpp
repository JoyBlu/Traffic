#pragma once
#include <QGraphicsItem>
#include <QtCore>

class Signals : public QGraphicsItem
{
  public:
    Signals(QGraphicsItem* parent = 0);
    ~Signals();

    QRectF boundingRect() const;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
    // get the color of the nearest signal light
    QColor getColor(const QPoint pos);
    // TODO(daiz) a function to update signal color

  private:
    // color of 18(1 crossing has 2 signal lights) signal lights:
    // up-down use even index
    // left-right use odd index
    QVector<QColor> color_;
    // display time for 3 colors
    // 0: red 1: green 2: yellow
    int time_[3];
    // the center of 9 crossings
    QVector<QPoint> centers_;
};