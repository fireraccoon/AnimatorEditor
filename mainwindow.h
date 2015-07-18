#ifndef MAINWINDOW_H
#define MAINWINDOW_H



#include "editorscene.h"

#include <QMainWindow>



namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();



signals:
    ///
    /// \brief Triggered when an item is selected
    /// \param item
    ///
    void itemSelected(QGraphicsItem *item);



private slots:
    //void transitionInserted(TransitionGraphicsItem *item) // TODO


    ///
    /// \brief Triggered when an item is selected
    /// \param scale the new desired scale
    ///
    void sceneScaleChanged(const QString &scale);



    void on_actionExit_triggered();
    void on_btnAddParameter_clicked();


    void onItemSelected(QGraphicsItem* item);


    void on_actionNew_Animator_Machine_triggered();

private:
    ///
    /// \brief Exits the application
    ///
    void exitApp();


    ///
    /// \brief initialises the editor
    ///
    void setupEditor();



private:
    Ui::MainWindow *ui;
    EditorScene *scene;


};

#endif // MAINWINDOW_H
