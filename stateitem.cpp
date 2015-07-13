#include "stateitem.h"

#include <QMenu>
#include <QPainter>
#include <QPen>
#include <QTextCursor>

StateItem::StateItem(int x, int y, bool isEnterState, QGraphicsItem *parent)
    : QGraphicsTextItem(parent){

    mIsSelected = false;
    mIsEnterState = isEnterState;

    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);

    setPos(x,y);
    setFont(QFont("Arial"));

    setPlainText("New State");

    setDefaultTextColor(Qt::white);


}



void StateItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){

    if(mIsSelected){
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
    QRect rect = option->rect;
    int margin = 50;
    rect = rect.marginsAdded(QMargins(margin, margin, margin, margin));
    painter->drawRect(rect);

    QGraphicsTextItem::paint(painter, option, widget);

}

void StateItem::mousePressEvent(QGraphicsSceneMouseEvent *event){
    QGraphicsTextItem::mousePressEvent(event);
    mIsSelected = true;
}

void StateItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){
    QGraphicsTextItem::mouseReleaseEvent(event);
    mIsSelected = false;
}

void StateItem::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event){

    if(textInteractionFlags() == Qt::NoTextInteraction)
        setTextInteractionFlags(Qt::TextEditorInteraction);
    QGraphicsTextItem::mouseDoubleClickEvent(event);

}

void StateItem::contextMenuEvent(QGraphicsSceneContextMenuEvent *event){
    qDebug("OK");

    QString createTransition = "Create Transition";

    QString markEnter = "Mark Enter";
    QString unMarkEnter = "Unmark enter";

    QString deleteState = "Delete State";

    QMenu menu(event->widget());

    if(mIsEnterState){
        menu.addAction(unMarkEnter);
    }else{
        menu.addAction(markEnter);
    }


    menu.addAction(createTransition);
    menu.addAction(deleteState);
    QAction *a = menu.exec(event->screenPos());

    if(a != NULL){

        if(a->text() == markEnter){
            this->mIsEnterState = true;
            this->update();

        }else if(a->text() == unMarkEnter){
            this->mIsEnterState = false;
            this->update();
        }
    }





}

QVariant StateItem::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value){
    QGraphicsItem::itemChange(change,value);
    if(change == QGraphicsItem::ItemSelectedHasChanged){
        emit selectedChange(this);
    }

    //Clear Selection
    QTextCursor cursor(this->textCursor());
    cursor.clearSelection();
    this->setTextCursor(cursor);


    return value;
}

void StateItem::focusOutEvent(QFocusEvent *event){
    //When loosing focus, we no longer can edit the text
    setTextInteractionFlags(Qt::NoTextInteraction);
    emit lostFocus(this);
    QGraphicsTextItem::focusOutEvent(event);
}

void StateItem::keyPressEvent(QKeyEvent *event){
    if(event->key() == 16777220 || event->key() == Qt::Key_Enter){
        return;
    }
    QGraphicsTextItem::keyPressEvent(event);
}

