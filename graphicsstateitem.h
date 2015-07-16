#ifndef EDITORITEM_H
#define EDITORITEM_H

#include "graphicstransition.h"

#include <QGraphicsItem>
#include <QGraphicsSceneContextMenuEvent>
#include <QKeyEvent>
#include <QPainter>
#include <QStyleOptionGraphicsItem>

#include <QXmlStreamWriter>

class GraphicsTransition; //forward declaration


/**
 * @brief The EditorItem class
 * Represents a State in the EditorScene
 */
class GraphicsStateItem : public QGraphicsTextItem{

Q_OBJECT

public:
    GraphicsStateItem(int x, int y, QMenu *contextMenu, bool isEnterState = false, QGraphicsItem *parent=0);

    QRectF getBoundingRect() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);



    void addTransition(GraphicsTransition *tran);
    void removeTransition(GraphicsTransition *tran);
    void removeTransitions();






    QString getId(){
        return this->toPlainText();
    }

    QString getAnimName(){
        return mAnimName;
    }

    QString setAnimName(QString animName){
        mAnimName = animName;
    }


    void writeXml(QXmlStreamWriter &writer);


signals:
    void lostFocus(GraphicsStateItem *item);            //Triggered when a state items looses the focus
    void selectedChange(QGraphicsItem *item);


protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);

    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event);


    QVariant itemChange(GraphicsItemChange change, const QVariant &value);


    void focusOutEvent(QFocusEvent *event);


    void keyPressEvent(QKeyEvent *event);



private:

    QString mAnimName;
    bool mIsEnterState; //Whether the state is the enter state

    QMenu *mContextMenu; //The context menu to use when the state is right clicked



    QList<GraphicsTransition *> mTransitions;



};

#endif // EDITORITEM_H
