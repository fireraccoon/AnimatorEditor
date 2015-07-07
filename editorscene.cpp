#include "editorscene.h"

#include <QMenu>


EditorScene::EditorScene(QObject *parent)
    : QGraphicsScene(parent){

    mMode = MoveState;

    mTextColor = Qt::black;
    mStateColor = Qt::white;
    mLineColor = Qt::black;

    setBackgroundBrush(Qt::gray);

    addItem(new StateItem(50,50));
}

void EditorScene::setMode(EditorScene::Mode mode){
    mMode = mode;
}

void EditorScene::mousePressEvent(QGraphicsSceneMouseEvent *event){
     QGraphicsScene::mousePressEvent(event);
}

void EditorScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event){
    QGraphicsScene::mouseMoveEvent(event);
}

void EditorScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){
    QGraphicsScene::mouseReleaseEvent(event);

}

void EditorScene::contextMenuEvent(QGraphicsSceneContextMenuEvent *event){
    QMenu menu(event->widget());
    menu.addAction("Add State");
    menu.addAction("Create transition");
    menu.exec(event->screenPos());
}
