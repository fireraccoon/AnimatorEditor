#include "animator.h"

#include <QFile>
#include <QXmlStreamWriter>

Animator::Animator(){

}


void Animator::addParameter(QString name, Parameter &p){
    this->parameters.insert(name, p);
}

void Animator::addState(GraphicsStateItem &s){
    //this->states.push_back(s);
}

void Animator::saveToXml(const QString &filename){
    QFile file(filename);
    file.open(QIODevice::WriteOnly);

    QXmlStreamWriter xmlWriter(&file);
    xmlWriter.setAutoFormatting(true);

    xmlWriter.writeStartDocument(); //Start Document

    xmlWriter.writeStartElement("machine");

    //Parameters
    xmlWriter.writeStartElement("parameters");
    QHashIterator<QString, Parameter> it(parameters);
    while(it.hasNext()){
        it.next();
        QString name = it.key();
        Parameter p = it.value();
        p.writeXml(name, xmlWriter);
    }
    xmlWriter.writeEndElement();
    //<parameters/>

    //States
   /* xmlWriter.writeStartElement("states");
    for(std::vector<State>::iterator it = states.begin(); it != states.end(); ++it){
        it->writeXml(xmlWriter);
    }

    xmlWriter.writeEndElement();*/
    //<states/>



    xmlWriter.writeEndElement(); //</machine>

    xmlWriter.writeEndDocument();  //End Document
}

