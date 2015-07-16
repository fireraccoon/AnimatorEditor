#ifndef PARAMETER_H
#define PARAMETER_H

#include <QString>
#include <QXmlStreamWriter>

namespace ParameterType{
    static const QString Integer = "Integer";
    static const QString Float = "Float";
    static const QString Boolean = "Boolean";
    static const QString Trigger = "Trigger";
};

class Parameter
{
public:
    Parameter(QString type);

    void writeXml(QString paramName, QXmlStreamWriter &writer);
private:
    QString mType;
};

#endif // PARAMETER_H
