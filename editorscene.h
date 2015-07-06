#ifndef EDITORSCENE_H
#define EDITORSCENE_H

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

    EditorScene();

private:
    Mode m_mode;                // The current mode of the editor

    //TODO add a Context Menu


    QColor m_textColor;
    QColor m_stateColor;
    QColor m_lineColor;
};

#endif // EDITORSCENE_H
