#include "mainwindow.h"
#include "ui_mainwindow.h"





MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){


    ui->setupUi(this);

    //SetUp Editor Scene
    scene = new EditorScene(this);
    scene->setSceneRect(QRectF(0, 0, 500, 500));
    ui->graphicsView->setScene(scene);

    //NAME
    setWindowTitle("Animator Editor (GoatEngine)");
    setUnifiedTitleAndToolBarOnMac(true);




}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_actionExit_triggered()
{
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

void MainWindow::on_btnAddParameter_clicked(){

}
