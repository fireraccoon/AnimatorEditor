#include "condition.h"
#include <QDebug>

Condition::Condition(QString left, QString op, QString right){
    mLeftTerm = left;
    mOperand = op;
    mRightTerm = right;

}

void Condition::writeXml(QXmlStreamWriter &writer){


    writer.writeStartElement("condition");

    writer.writeAttribute("parameter", mLeftTerm);
    writer.writeAttribute("operand", mOperand);
    writer.writeAttribute("value", mRightTerm);

    writer.writeEndElement();

}

