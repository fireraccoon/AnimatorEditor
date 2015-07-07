#ifndef EDITORITEM_H
#define EDITORITEM_H

#include <QGraphicsItem>
#include <QPainter>



/**
 * @brief The EditorItem class
 * Represents a State in the EditorScene
 */
class StateItem : public QGraphicsRectItem{

public:
    StateItem(int x, int y, bool isEnterState = false);

    QRectF getBoundingRect() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);


private:
    QString name;   //Name of the state


    bool mIsSelected;  //Wether the current item is selected
    bool mIsEnterState; //Whether the state is the enter state

};

#endif // EDITORITEM_H
