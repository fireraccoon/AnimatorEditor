#ifndef CONDITION_H
#define CONDITION_H

#include <QString>
#include <QXmlStreamWriter>


namespace ConditionOperand{
    static const QString GREATER_THAN = "GREATER_THAN";
    static const QString LESS_THAN = "LESS_THAN";
    static const QString EQUALS = "EQUALS";
}


class Condition
{
public:
    Condition(QString left, QString op, QString right);

    void writeXml(QXmlStreamWriter &writer);

private:
    QString mLeftTerm; //AnimatorParameter Name
    QString mOperand;
    QString mRightTerm;


};

#endif // CONDITION_H
