#include "state.h"

State::State(QString id, QString animName){
    mId = id;
    mAnimName = animName;
}


void State::addTransition(Transition &t){
    this->transitions.push_back(t);
}

void State::writeXml(QXmlStreamWriter &writer){

    writer.writeStartElement("state");
    writer.writeAttribute("id", mId);
    writer.writeAttribute("animName", mAnimName);

    // TODO isEnter State
    //writer.writeAttribute("isStart", m);


    writer.writeStartElement("transitions");
    for(std::vector<Transition>::iterator it = transitions.begin(); it != transitions.end(); ++it){
       it->writeXml(writer);
    }
    writer.writeEndElement();


    writer.writeEndElement();
}

