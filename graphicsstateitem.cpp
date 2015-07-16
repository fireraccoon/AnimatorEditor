#include "graphicsstateitem.h"

#include <QMenu>
#include <QPainter>
#include <QPen>
#include <QTextCursor>
#include <QGraphicsScene>


GraphicsStateItem::GraphicsStateItem(int x, int y, QMenu *contextMenu, bool isEnterState, QGraphicsItem *parent)
    : QGraphicsTextItem(parent){

    mIsEnterState = isEnterState;
    mContextMenu = contextMenu;

    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);

    setPos(x,y);
    setFont(QFont("Arial"));

    setPlainText("New State");

    setDefaultTextColor(Qt::white);
}

void GraphicsStateItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){

    if(isSelected()){
         QPen pen(Qt::yellow, 3);
         painter->setPen(pen);
    }else{
         QPen pen(Qt::white, 3);
         painter->setPen(pen);
    }

    //Fill Color
    if(mIsEnterState)
        painter->setBrush(QColor(0, 0xFF, 0, 0x80));
    else
        painter->setBrush(QColor(0, 0, 0, 0x80));

    int margin = 10;
    //painter->drawRect(option->rect.marginsAdded(QMargins(margin, margin, margin, margin)));
    painter->drawRect(option->rect);
    QGraphicsTextItem::paint(painter, option, widget);


}

void GraphicsStateItem::addTransition(GraphicsTransition *tran){

    mTransitions.append(tran);

}

void GraphicsStateItem::removeTransition(GraphicsTransition *tran){
    int index = mTransitions.indexOf(tran);

    if(index != -1){
        mTransitions.removeAt(index);
    }
}

void GraphicsStateItem::removeTransitions(){

    foreach(GraphicsTransition *tran, mTransitions){
        tran->getCurrentState()->removeTransition(tran);
        tran->getNextState()->removeTransition(tran);
        scene()->removeItem(tran);
        delete tran;
    }
}






void GraphicsStateItem::writeXml(QXmlStreamWriter &writer){

    writer.writeStartElement("state");
    writer.writeAttribute("id", getId());
    writer.writeAttribute("animName", mAnimName);

    // TODO isEnter State
    //writer.writeAttribute("isStart", m);


    writer.writeStartElement("transitions");
    QListIterator<GraphicsTransition *> it(mTransitions);
    while(it.hasNext()){
        GraphicsTransition *tran = it.next();
        tran->writeXml(writer);
    }
    writer.writeEndElement();


    writer.writeEndElement();
}












void GraphicsStateItem::mousePressEvent(QGraphicsSceneMouseEvent *event){
    QGraphicsTextItem::mousePressEvent(event);

}

void GraphicsStateItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){
    QGraphicsTextItem::mouseReleaseEvent(event);

}




void GraphicsStateItem::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event){
    if(textInteractionFlags() == Qt::NoTextInteraction)
        setTextInteractionFlags(Qt::TextEditorInteraction);
    QGraphicsTextItem::mouseDoubleClickEvent(event);
}


void GraphicsStateItem::contextMenuEvent(QGraphicsSceneContextMenuEvent *event){


    this->scene()->clearSelection();
    setSelected(true);
    mContextMenu->exec(event->screenPos());
}




QVariant GraphicsStateItem::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value){
    QGraphicsItem::itemChange(change,value);
    if(change == QGraphicsItem::ItemSelectedHasChanged){
        emit selectedChange(this);
    }

    //Clear Selection
    QTextCursor cursor(this->textCursor());
    cursor.clearSelection();
    this->setTextCursor(cursor);

    update();
    return value;
}

void GraphicsStateItem::focusOutEvent(QFocusEvent *event){
    //When loosing focus, we no longer can edit the text
    setTextInteractionFlags(Qt::NoTextInteraction);
    emit lostFocus(this);
    QGraphicsTextItem::focusOutEvent(event);
}

void GraphicsStateItem::keyPressEvent(QKeyEvent *event){
    if(event->key() == 16777220 || event->key() == Qt::Key_Enter){
        return;
    }
    QGraphicsTextItem::keyPressEvent(event);
}

