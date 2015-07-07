#include "stateitem.h"

#include <QPainter>
#include <QPen>

StateItem::StateItem(int x, int y, bool isEnterState)
    : QGraphicsRectItem(x, y, x+200, y+30){

    mIsSelected = false;
    mIsEnterState = isEnterState;

    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setAcceptHoverEvents(true);
}


QRectF StateItem::getBoundingRect() const{
    return this->rect();
}

void StateItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    if(mIsSelected){
         QPen pen(Qt::red, 3);
         painter->setPen(pen);
    }else{
         QPen pen(Qt::black, 3);
         painter->setPen(pen);
    }

    if(mIsEnterState){
        painter->setBrush(Qt::green);
    }else{
        painter->setBrush(Qt::blue);
    }


    painter->drawRect(this->getBoundingRect());

}

void StateItem::mousePressEvent(QGraphicsSceneMouseEvent *event){
    mIsSelected = true;
}

void StateItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){
    mIsSelected = false;
}

void StateItem::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event){

}

