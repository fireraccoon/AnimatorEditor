#ifndef EDITORITEM_H
#define EDITORITEM_H

#include <QGraphicsPolygonItem>


/**
 * @brief The EditorItem class
 * Represents a State in the EditorScene
 */
class StateItem : public QGraphicsRectItem{

public:
    StateItem(int x1, int y1, int x2, int y2);



};

#endif // EDITORITEM_H
