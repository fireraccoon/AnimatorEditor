#ifndef TRANSITION_H
#define TRANSITION_H

#include "condition.h"

#include <QXmlStreamWriter>



class Transition
{
public:
    Transition(const QString &fromId, const QString &toId, Condition *cond);
    ~Transition();


    void writeXml(QXmlStreamWriter &writer);


private:
    QString mNext;
    QString mCurrent;
    Condition *mCondition;

};

#endif // TRANSITION_H
