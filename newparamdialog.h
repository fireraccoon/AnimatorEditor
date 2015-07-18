#ifndef NEWPARAMDIALOG_H
#define NEWPARAMDIALOG_H

#include "ui_newparameterdialog.h"



class NewParamDialog : public QDialog, Ui::Dialog{
    Q_OBJECT
public:
    NewParamDialog(QWidget *parent = 0);
    ~NewParamDialog();






private:
    Ui::Dialog *ui;

};

#endif // NEWPARAMDIALOG_H
