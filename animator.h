#ifndef ANIMATOR_H
#define ANIMATOR_H

#include "vector"
#include "map"
#include "QString"

#include "state.h"
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
    void addState(State &s);


    /**
     * @brief saveToXml
     * @param filename
     */
    void saveToXml(const QString &filename);



private:
    std::vector<State> states;
    QHash<QString, Parameter> parameters;

};

#endif // ANIMATOR_H
