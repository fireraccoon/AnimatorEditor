#include "editorscene.h"


EditorScene::EditorScene(QObject *parent)
    : QGraphicsScene(parent){

    mMode = MoveState;

    mTextColor = Qt::black;
    mStateColor = Qt::white;
    mLineColor = Qt::black;

}

void EditorScene::setMode(EditorScene::Mode mode){
    mMode = mode;
}

void EditorScene::mousePressEvent(QGraphicsSceneMouseEvent *event){
    qDebug("PRESS");
}

void EditorScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event){
     qDebug("MOVE");
}

void EditorScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){
     qDebug("RELEASE");
}
