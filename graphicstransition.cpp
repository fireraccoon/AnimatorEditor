#include "graphicstransition.h"

GraphicsTransition::GraphicsTransition(GraphicsStateItem *from, GraphicsStateItem *to, QGraphicsItem *parent)
    : QGraphicsLineItem(parent){

    mCurrentState = from;
    mNextState = to;
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setPen(QPen(Qt::white, 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));

}



void GraphicsTransition::setNextState(GraphicsStateItem *state){
    mNextState = state;

}

void GraphicsTransition::setCurrentState(GraphicsStateItem *state){
    mCurrentState = state;

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

void GraphicsTransition::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

}

