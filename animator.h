#ifndef ANIMATOR_H
#define ANIMATOR_H

#include "vector"
#include "map"
#include "QString"

#include "graphicsstateitem.h"
#include "parameter.h"

#include <QHash>


class Animator
{
public:
    Animator();

    /**
     * @brief addParameter
     * @param name
     * @param p
     * @return
     */
    void addParameter(QString name, Parameter &p);

    /**
     * @brief addState
     * @param s
     * @return
     */
    void addState(GraphicsStateItem &s);


    /**
     * @brief saveToXml
     * @param filename
     */
    void saveToXml(const QString &filename);



private:
    QHash<QString, Parameter> parameters;

};

#endif // ANIMATOR_H
