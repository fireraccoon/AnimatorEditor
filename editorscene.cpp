#include "editorscene.h"


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

void EditorScene::mousePressEvent(QGraphicsSceneMouseEvent *event){
    qDebug("PRESS");
}

void EditorScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event){
     qDebug("MOVE");
}

void EditorScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){
     qDebug("RELEASE");
     addItem(new StateItem(50,50,200,50));
}
