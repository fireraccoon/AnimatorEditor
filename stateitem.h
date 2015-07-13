#ifndef EDITORITEM_H
#define EDITORITEM_H

#include <QGraphicsItem>
#include <QGraphicsSceneContextMenuEvent>
#include <QKeyEvent>
#include <QPainter>
#include <QStyleOptionGraphicsItem>



/**
 * @brief The EditorItem class
 * Represents a State in the EditorScene
 */
class StateItem : public QGraphicsTextItem{

Q_OBJECT

public:
    StateItem(int x, int y, bool isEnterState = false, QGraphicsItem *parent=0);

    QRectF getBoundingRect() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);


signals:
    void lostFocus(StateItem *item);            //Triggered when a state items looses the focus
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
    QString name;   //Name of the state


    bool mIsSelected;  //Wether the current item is selected
    bool mIsEnterState; //Whether the state is the enter state

};

#endif // EDITORITEM_H
