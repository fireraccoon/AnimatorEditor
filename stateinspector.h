#ifndef STATEINSPECTOR_H
#define STATEINSPECTOR_H

#include "graphicsstateitem.h"
#include "ui_stateinspector.h"

class StateInspector : public QFrame, Ui::Frame{
    Q_OBJECT
public:
    explicit StateInspector(GraphicsStateItem *state, QWidget *parent = 0);

signals:

public slots:


private:


};

#endif // STATEINSPECTOR_H
