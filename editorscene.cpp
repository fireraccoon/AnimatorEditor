#include "editorscene.h"

#include <QMenu>
#include <QSignalMapper>
#include <QDebug>

EditorScene::EditorScene(QObject *parent)
    : QGraphicsScene(parent){

    mMode = MoveState;

    mTextColor = Qt::black;
    mStateColor = Qt::white;
    mLineColor = Qt::black;

    setBackgroundBrush(Qt::gray);



}

void EditorScene::setMode(EditorScene::Mode mode){
    mMode = mode;
}

void EditorScene::addState(QPointF pos){
    StateItem *item = new StateItem(pos.x(),pos.y());
    qDebug() << "created";
    addItem(item);
    qDebug() << "added";
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
