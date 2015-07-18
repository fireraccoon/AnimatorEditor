#include "stateinspector.h"

StateInspector::StateInspector(GraphicsStateItem *state, QWidget *parent) : QFrame(parent){
    setupUi(this);

     lblIdValue->setText(state->getId());
     lblAnimationNameValue->setText(state->getAnimName());
     lblPlaybackValue->setText(QString::number(1));

     checkBoxEnterState->setChecked(state->isEnterState());

     checkBoxOrphan->setChecked(state->isOrphan());



}

