#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <animator.h>

int main(int argc, char *argv[])
{


    //MACHINE
    Animator anim;

    anim.addParameter("speed", Parameter(ParameterType::Integer));
    anim.addParameter("isGrounded", Parameter(ParameterType::Boolean));

    State idle("IDLE", "Idle");
    State running("RUNNING", "running");
    running.addTransition(Transition(idle.getId(),running.getId(),new Condition("speed", ConditionOperand::EQUALS, "10")));


    anim.addState(idle);
    anim.addState(running);








    anim.saveToXml("../Choko.xml");


    QApplication a(argc, argv);

    MainWindow w;
    w.show();





    return a.exec();
}
