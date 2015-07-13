#include "editorscene.h"

#include <QMenu>
#include <QSignalMapper>
#include <QDebug>

EditorScene::EditorScene(QObject *parent)
    : QGraphicsScene(parent){

    mMode = MoveState;

    setBackgroundBrush(QPixmap(":/res/background.jpg"));


}

void EditorScene::setMode(EditorScene::Mode mode){
    mMode = mode;
}

void EditorScene::addState(QPointF pos){
    StateItem *item = new StateItem(pos.x(),pos.y());
    addItem(item);
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

        QGraphicsScene::contextMenuEvent(event);

        if(!event->isAccepted()){
            QString addStateStr = "Add State";
            QMenu menu(event->widget());
            menu.addAction(addStateStr);
            QAction *a = menu.exec(event->screenPos());
            if(a != NULL){
                if(a->text() == addStateStr){
                    addState(event->scenePos());
                }

            }
        }






}


