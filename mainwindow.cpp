#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "newparamdialog.h"

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
    scene->setSceneRect(QRectF(-5000, -500, 500, 500));
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHints( QPainter::Antialiasing );
}

void MainWindow::on_btnAddParameter_clicked(){

    NewParamDialog *d = new NewParamDialog(this);
    d->exec();


}


























