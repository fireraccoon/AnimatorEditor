#include "newparamdialog.h"

NewParamDialog::NewParamDialog(QWidget *parent) : QDialog(parent){
    setupUi(this);
    this->setWindowTitle("Add new animation Parameter");


    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    //connect(ui->buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

}

