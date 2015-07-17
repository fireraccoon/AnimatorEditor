#include "graphicstransition.h"


#include <math.h>


#include <QPen>
#include <QPainter>

const qreal PI = 3.14;

GraphicsTransition::GraphicsTransition(GraphicsStateItem *from, GraphicsStateItem *to, QGraphicsItem *parent)
    : QGraphicsLineItem(parent){

    mCurrentState = from;
    mNextState = to;
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setPen(QPen(Qt::white, 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));

}

QRectF GraphicsTransition::boundingRect(){
    qreal extra = (pen().width() + 20) / 2.0;

        return QRectF(line().p1(), QSizeF(line().p2().x() - line().p1().x(),
                                          line().p2().y() - line().p1().y()))
            .normalized()
                .adjusted(-extra, -extra, extra, extra);
}

QPainterPath GraphicsTransition::shape(){
    QPainterPath path = QGraphicsLineItem::shape();
    path.addPolygon(mArrowHead);
    return path;
}



void GraphicsTransition::setNextState(GraphicsStateItem *state){
    mNextState = state;

}

void GraphicsTransition::setCurrentState(GraphicsStateItem *state){
    mCurrentState = state;

}

void GraphicsTransition::updatePosition(){

    if(mCurrentState != nullptr && mNextState != nullptr){
        QLineF line(mapFromItem(mCurrentState, 20, 0), mapFromItem(mNextState, 0, 0));
        setLine(line);
    }
}



void GraphicsTransition::writeXml(QXmlStreamWriter &writer){

    writer.writeStartElement("transition");
    writer.writeAttribute("target", mNextState->getId());


    //TODO for Each condition
    writer.writeStartElement("conditions");
    mCondition->writeXml(writer);
    writer.writeEndElement();


    writer.writeEndElement();
}

void GraphicsTransition::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){

    if (mCurrentState->collidesWithItem(mNextState))
       return;

    QPen myPen = pen();
    myPen.setColor(Qt::white);
    qreal arrowSize = 20;
    painter->setPen(myPen);
    painter->setBrush(Qt::white);


    QLineF centerLine(mCurrentState->getCenterPoint(), mNextState->getCenterPoint());
    QPolygonF endPolygon = mNextState->boundingRect();
    QPointF p1 = endPolygon.first() + mNextState->getCenterPoint();
    QPointF p2;
    QPointF intersectPoint;
    QLineF polyLine;
    for (int i = 1; i < endPolygon.count(); ++i) {
    p2 = endPolygon.at(i) + mNextState->getCenterPoint();
    polyLine = QLineF(p1, p2);
    QLineF::IntersectType intersectType =
        polyLine.intersect(centerLine, &intersectPoint);
    if (intersectType == QLineF::BoundedIntersection)
        break;
        p1 = p2;
    }

    setLine(QLineF(intersectPoint, mCurrentState->getCenterPoint()));

    double angle = ::acos(line().dx() / line().length());
    if (line().dy() >= 0){
        angle = (PI * 2) - angle;

        QPointF arrowP1 = line().p1() + QPointF(sin(angle + PI / 3) * arrowSize,
                                        cos(angle + PI / 3) * arrowSize);
        QPointF arrowP2 = line().p1() + QPointF(sin(angle + PI - PI / 3) * arrowSize,
                                        cos(angle + PI - PI / 3) * arrowSize);

        mArrowHead.clear();
        mArrowHead << line().p1() << arrowP1 << arrowP2;


        painter->drawLine(line());
        painter->drawPolygon(mArrowHead);
        if (isSelected()) {
            painter->setPen(QPen(Qt::white, 1, Qt::DashLine));
        QLineF myLine = line();
        myLine.translate(0, 2.0);
        painter->drawLine(myLine);
        myLine.translate(0,-4.0);
        painter->drawLine(myLine);
        }
    }

    QGraphicsLineItem::paint(painter, option, widget);


}

