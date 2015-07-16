#ifndef EDITORSCENE_H
#define EDITORSCENE_H

#include "animator.h"
#include "graphicsstateitem.h"


#include <QGraphicsScene>
#include <QGraphicsSceneContextMenuEvent>



class EditorScene : public QGraphicsScene{

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


    /**
     * @brief addState
     * Adds a new Visual StateItem
     * @param pos
     */
    void addState(QPointF pos);


    /**
     * Displays the animator on the scene
     * @brief displayAnimator
     * @param animator
     */
    void displayAnimator(Animator &animator);



public slots:
    void setMode(Mode mode); //Changes the mode

signals:
    void stateInserted(GraphicsStateItem *state);    // Triggered when a state is added to the scene
    //void transitionInserted(Transition)
    void itemSelected(QGraphicsItem *item);  // Triggered when an Item is selected on the scene




protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);       //Called only when the mouse isPressed
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event);






private:


    Mode mMode;   // The current mode of the editor




};

#endif // EDITORSCENE_H
