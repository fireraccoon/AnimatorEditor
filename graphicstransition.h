#ifndef GRAPHICSTRANSITION_H
#define GRAPHICSTRANSITION_H

#include "condition.h"
#include "graphicsstateitem.h"

#include <QGraphicsLineItem>

class GraphicsStateItem; //forward declaration


class GraphicsTransition : public QGraphicsLineItem
{
public:
    GraphicsTransition(GraphicsStateItem *from, GraphicsStateItem *to, QGraphicsItem *parent = 0);

    //Redefined for selection collision detection
    QRectF boundingRect();
    QPainterPath shape();


    GraphicsStateItem* getCurrentState() { return mCurrentState; }
    GraphicsStateItem* getNextState() { return mNextState; }


    void setNextState(GraphicsStateItem *state);
    void setCurrentState(GraphicsStateItem *state);

    void setCondition(Condition *cond){ mCondition = cond; }
    Condition* getCondition(){ return mCondition; }




    void updatePosition();

    void writeXml(QXmlStreamWriter &writer);


private:

    GraphicsStateItem *mCurrentState;
    GraphicsStateItem *mNextState;
    QPolygonF mArrowHead;

    Condition *mCondition;



};

#endif // GRAPHICSTRANSITION_H
