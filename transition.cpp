#include "transition.h"

Transition::Transition(const QString &fromId, const QString &toId, Condition *cond){
    mCurrent = fromId;
    mNext = toId;
    mCondition = cond;
}

Transition::~Transition(){
    //delete(mCondition);
}

void Transition::writeXml(QXmlStreamWriter &writer){

    writer.writeStartElement("transition");
    writer.writeAttribute("target", mNext);



    //TODO for Each condition
    writer.writeStartElement("conditions");
    mCondition->writeXml(writer);
    writer.writeEndElement();


    writer.writeEndElement();
}
