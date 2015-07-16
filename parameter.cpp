#include "parameter.h"

Parameter::Parameter(QString type){
    mType = type;
}

void Parameter::writeXml(QString paramName, QXmlStreamWriter &writer){


    writer.writeStartElement("parameter");
    writer.writeAttribute("name", paramName);
    writer.writeAttribute("type", mType);
    writer.writeEndElement();
}

