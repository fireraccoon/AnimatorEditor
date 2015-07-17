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
    GraphicsStateItem(int x, int y, bool isEnterState = false, QGraphicsItem *parent=0);

    QRectF getBoundingRect() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);



    void addTransition(GraphicsTransition *tran);
    void removeTransition(GraphicsTransition *tran);
    void removeTransitions();



    QPointF getCenterPoint(){
        QPointF pos = this->scenePos();
        pos.setX(pos.x() + boundingRect().width()/2);
        pos.setY(pos.y() + boundingRect().height()/2);
        return pos;
    }



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

    ///
    /// \brief Triggered when the users wants to delete the current state
    /// \param item
    ///
    void deleteRequest(GraphicsStateItem *item);

    ///
    /// \brief Triggered when the item is selected
    /// \param item
    ///
    void itemSelected(QGraphicsItem *item);


    ///
    /// \brief When a state is marked or unmarked as enter state
    /// \param item
    /// \param isEnterState the desired state
    ///
    void stateMarked(GraphicsStateItem *item, bool isEnterState);

    ///
    /// \brief The user requested to add a new transition starting from the current state
    /// \param item
    ///
    void transitionInsertionRequest(GraphicsStateItem *item);



protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);

    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event);


    QVariant itemChange(GraphicsItemChange change, const QVariant &value);


    void focusOutEvent(QFocusEvent *event);


    void keyPressEvent(QKeyEvent *event);



private slots:

    void createContextMenu();

    void onAddTransitionAction();
    void onDeleteAction();
    void onMarkUpdateAction();
    void onNameChangeAction();






private:

    QString mAnimName;
    bool mIsEnterState; //Whether the state is the enter state

    QList<GraphicsTransition *> mTransitions;



    //Context Menu
    QMenu *mContextMenu;
    QAction *mAddTransitionAction;
    QAction *mMarkEnterAction;
    QAction *mUnmarkEnterAction;
    QAction *mDeleteAction;







};

#endif // EDITORITEM_H
