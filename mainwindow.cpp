#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "newanimatordialog.h"
#include "newparamdialog.h"
#include "spriteranimationreader.h"
#include "stateinspector.h"

#include <QTextStream>



MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);

    //SetUp Editor Scene
    setupEditor();

    //NAME
    setWindowTitle("Animator Editor (GoatEngine)");
    setUnifiedTitleAndToolBarOnMac(true);

    //STYLESHEET
    QFile f(":/qdarkstyle/style.qss");
    if (!f.exists()){
        qDebug("Unable to set stylesheet, file not found\n");
    }
    else
    {
        f.open(QFile::ReadOnly | QFile::Text);
        QTextStream ts(&f);
        qApp->setStyleSheet(ts.readAll());
    }


}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::sceneScaleChanged(const QString &scale)
{

}


void MainWindow::on_actionExit_triggered(){
    exitApp();
}


void MainWindow::exitApp(){

    //TODO Check if everything was saved
    //if not display dialog do you want to save
    // on yes open save dialog
    // on No exit
    // on cancel return
    qApp->exit(0);

}

void MainWindow::setupEditor(){
    scene = new EditorScene(this);
    scene->setSceneRect(QRectF(0, 0, 500, 500));
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHints(QPainter::Antialiasing);

    connect(scene,SIGNAL(itemSelected(QGraphicsItem*)), this, SLOT(onItemSelected(QGraphicsItem*)));


}

void MainWindow::on_btnAddParameter_clicked(){

    NewParamDialog *d = new NewParamDialog(this);
    int result = d->exec();

    if(result == QDialog::Accepted){

        /*QString source = d->;
        QString output = "";*/

    }





    delete(d);


}


void MainWindow::onItemSelected(QGraphicsItem *item){


    GraphicsStateItem *state = qgraphicsitem_cast<GraphicsStateItem*>(item);
    if(state != NULL){
        //Remove old child widgets
        QLayoutItem *child;
        child = ui->inspectorLayout->takeAt(0);
        while(child != NULL)
        {
            ui->verticalLayout->removeWidget(child->widget());
            delete child;
            child = ui->verticalLayout->takeAt(0);
        }

        StateInspector *ins = new StateInspector(state, this->ui->groupBoxInspector);

        ui->inspectorLayout->addWidget(ins);

    }else{
        GraphicsTransition *transition = qgraphicsitem_cast<GraphicsTransition*>(item);
        if(transition != NULL){

        }
    }


}


void MainWindow::on_actionNew_Animator_Machine_triggered(){

    NewAnimatorDialog *d = new NewAnimatorDialog(this);
    int result = d->exec();

    if(result == QDialog::Accepted){
        QString source = d->getSource();
        QString output = d->getOutput();



        //Read Source File
        SpriterAnimationReader reader(source);
        QStringList states = reader.read();


         //Create States
        for(int i=0; i<states.count(); i++){
            QString stateName = states.at(i);

            GraphicsStateItem *state = new GraphicsStateItem(-4774,-437);
            state->setId(stateName);
            state->setAnimName(stateName);

            scene->addState(state);

        }

        //ANY_STATE
        GraphicsStateItem *anyState = new GraphicsStateItem(-4774, -437);
        anyState->setId("ANY_STATE");
        scene->addState(anyState);

        //Spread all the states evenly accros the scene
        scene->spreadStates();




    }

    delete(d);
}
