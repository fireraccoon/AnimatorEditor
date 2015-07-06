#ifndef EDITORSCENE_H
#define EDITORSCENE_H

#include "stateitem.h"

#include <QGraphicsScene>



class EditorScene : public QGraphicsScene
{
    Q_OBJECT
public:
    /**
     * The possible modes of the editor
     */
    enum Mode {
        InsertState,            //When insering a new State
        InsertTransition,       //When insering a new Transition
        MoveState               //When moving a State
    };

    EditorScene(QObject *parent);

public slots:
    void setMode(Mode mode); //Changes the mode



signals:
    void stateInserted(StateItem *state);    // Triggered when a state is added to the scene
    void itemSelected(QGraphicsItem *item);  // Triggered when an Item is selected on the scene


protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);       //Called only when the mouse isPressed
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);




private:



    Mode mMode;                // The current mode of the editor

    //TODO add a Context Menu

    QColor mTextColor;
    QColor mStateColor;
    QColor mLineColor;
};

#endif // EDITORSCENE_H
