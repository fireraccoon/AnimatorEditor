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


    ///
    /// \brief Adds a new Visual StateItem at a given position
    /// \param pos
    ///
    void addState(QPointF pos);


    ///
    /// \brief Displays the animator on the scene
    /// \param animator
    ///
    void displayAnimator(Animator &animator);



public slots:
    void setMode(Mode mode); //Changes the mode


    void selectItem(QGraphicsItem *item);



    void deleteItem(GraphicsStateItem *state);





signals:
    ///
    /// \brief  Triggered when a state is added to the scene
    /// \param state
    ///
    void stateInserted(GraphicsStateItem *state);

    ///
    /// \brief Triggered when a state is deleted from the scene
    /// \param state
    ///
    void stateDeleted(GraphicsStateItem *state);

    ///
    /// \briefTriggered when the id of a text is changed
    /// \param state
    ///
    void stateUpdated(GraphicsStateItem *state);


    ///
    /// \brief Triggered when transition is inserted
    /// \param transition
    ///
    void transitionInserted(GraphicsTransition *transition);

    ///
    /// \brief Triggered when transition is deleted
    /// \param transition
    ///
    void transitionDeleted(GraphicsTransition *transition);

    ///
    /// \brief Triggered when an Item is selected
    /// \param item
    ///
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
