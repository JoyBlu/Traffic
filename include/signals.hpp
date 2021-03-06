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
    // can pass or not at this position
    bool canPass(const QPointF pos, const QPoint dire);
    // TODO(daiz) a function to update signal color
    void changeColor(bool toYellow);
    void slowBeforeLine(QPointF pos, QPointF& next_pos);
    inline int getTime(int idx)
    {
        return time_[idx];
    }

  private:
    // color of 18(1 crossing has 2 signal lights) signal lights:
    // up-down use even index
    // left-right use odd index
    QVector<QColor> color_;
    // display time for 3 colors
    // 0: red(longest) 1: green 2: yellow(shortest)
    int time_[3];
    // the center of 9 crossings
    QVector<QPoint> centers_;
};