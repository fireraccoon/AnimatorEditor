#include "editorscene.h"

#include <QMenu>
#include <QSignalMapper>
#include <QDebug>
#include <QGraphicsView>

EditorScene::EditorScene(QObject *parent)
    : QGraphicsScene(parent){

    mMode = MoveState;

    setBackgroundBrush(QPixmap(":/res/background.jpg"));


}

void EditorScene::setMode(EditorScene::Mode mode){
    mMode = mode;
}

void EditorScene::selectItem(QGraphicsItem *item){
    emit itemSelected(item);
}

void EditorScene::deleteItem(GraphicsStateItem *state){
    this->removeItem(state);
}

void EditorScene::onTransitionInsertion(GraphicsStateItem *state){
    mMode = InsertTransition;

   QPointF pos = state->scenePos();
   pos.setX(pos.x() + state->boundingRect().width()/2);
   pos.setY(pos.y() + state->boundingRect().height()/2);

    mLine = new QGraphicsLineItem(QLineF(pos,pos));
    mLine->setPen(QPen(Qt::white, 2));
    addItem(mLine);

}



void EditorScene::createState(QPointF pos){
    qDebug() << pos;


    GraphicsStateItem *state = new GraphicsStateItem(pos.x(),pos.y());
    addState(state);
}

void EditorScene::addState(GraphicsStateItem *state){

    //Connect
    connect(state, SIGNAL(itemSelected(QGraphicsItem*)), this, SLOT(selectItem(QGraphicsItem*)));
    connect(state, SIGNAL(deleteRequest(GraphicsStateItem*)), this, SLOT(deleteItem(GraphicsStateItem*)));
    connect(state, SIGNAL(transitionInsertionRequest(GraphicsStateItem*)), this, SLOT(onTransitionInsertion(GraphicsStateItem*)));

    addItem(state);
    emit stateInserted(state);
}

void EditorScene::spreadStates()
{

    QGraphicsView *view = views().first();



    QRect viewportRect(0, 0, view->viewport()->width(), view->viewport()->height());
    QRectF visibleRect = view->mapToScene(viewportRect).boundingRect();




    int itemCount = items().count();

    for(int i =0; i<itemCount; i++){
        QGraphicsItem *item = items().at(i);

        while(item->collidingItems().count()){

            qreal randX = qrand() % (int)visibleRect.width();
            qreal randY = qrand() % (int)visibleRect.height();

            item->setPos(randX, randY);

        }
    }

}

void EditorScene::clear(){



}


void EditorScene::mousePressEvent(QGraphicsSceneMouseEvent *event){
     QGraphicsScene::mousePressEvent(event);

}

void EditorScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event){

    //If we are in the add transition mode the transition follows the mouse
    if(mMode == InsertTransition){
        QLineF newLine(mLine->line().p1(), event->scenePos());
        mLine->setLine(newLine);
        mLine->setZValue(-1000);
    }else if(mMode == MoveState){
        QGraphicsScene::mouseMoveEvent(event);
    }
}


void EditorScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){
    QGraphicsScene::mouseReleaseEvent(event);

    if(mMode == InsertTransition){
        QList<QGraphicsItem *> startItems = items(mLine->line().p1());
        if (startItems.count() && startItems.first() == mLine)
            startItems.removeFirst();
        QList<QGraphicsItem *> endItems = items(mLine->line().p2());
        if (endItems.count() && endItems.first() == mLine)
            endItems.removeFirst();

        //removeItem(mLine);
        //delete mLine;

        if (startItems.count() > 0 && endItems.count() > 0 &&
            /*startItems.first()->type() == DiagramItem::Type &&
            endItems.first()->type() == DiagramItem::Type &&*/
            startItems.first() != endItems.first()) {

            GraphicsStateItem *startItem = qgraphicsitem_cast<GraphicsStateItem *>(startItems.first());
            GraphicsStateItem *endItem = qgraphicsitem_cast<GraphicsStateItem *>(endItems.first());
            GraphicsTransition *transition = new GraphicsTransition(startItem, endItem);
            startItem->addTransition(transition);
            transition->setZValue(-1000.0);
            addItem(transition);
            transition->updatePosition();


            removeItem(mLine);
            mLine = nullptr;

            setMode(MoveState);

        }


    }

    QGraphicsScene::mouseMoveEvent(event);

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
                    createState(event->scenePos());
                }
            }
        }

}


