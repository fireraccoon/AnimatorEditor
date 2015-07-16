#ifndef STATE_H
#define STATE_H

#include "transition.h"

#include <QXmlStreamWriter>
#include <vector>



class State
{
public:
    State(QString id, QString animName);

    /**
     * Adds a to the state
     * @brief addTransition
     * @param t the transition
     * @return
     */
    void addTransition(Transition &t);



    void writeXml(QXmlStreamWriter &writer);


    QString& getId(){ return mId; }


private:
    QString mId;
    QString mAnimName;
    std::vector<Transition> transitions;

};

#endif // STATE_H
