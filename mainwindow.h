#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private:
    void exitApp(); //Exits the application

private slots:
    void on_actionExit_triggered();

private:
    Ui::MainWindow *ui;



};

#endif // MAINWINDOW_H
