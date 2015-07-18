#include "newanimatordialog.h"
#include "ui_newanimatordialog.h"

#include <QFileDialog>

#include <QDebug>

NewAnimatorDialog::NewAnimatorDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewAnimatorDialog)
{
    ui->setupUi(this);


    ui->buttonBox->buttons().at(0)->setText("Finish");
}

NewAnimatorDialog::~NewAnimatorDialog()
{
    delete ui;
}

QString NewAnimatorDialog::getSource()
{
    return ui->lineEditSourcePath->text();
}

QString NewAnimatorDialog::getOutput()
{
    return ui->lineEditOutputPath->text();
}

void NewAnimatorDialog::on_btnBrowseSource_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Animation File"), "", tr("Spriter Animation Files (*.scml)"));
    ui->lineEditSourcePath->setText(fileName);
}

void NewAnimatorDialog::on_btnBrowseOutput_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save Animator"), "", tr("Goat Animator (*.gaml)"));
    ui->lineEditOutputPath->setText(fileName);
}
