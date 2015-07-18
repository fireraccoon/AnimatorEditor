#ifndef NEWANIMATORDIALOG_H
#define NEWANIMATORDIALOG_H

#include <QDialog>

namespace Ui {
class NewAnimatorDialog;
}

class NewAnimatorDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewAnimatorDialog(QWidget *parent = 0);
    ~NewAnimatorDialog();



    QString getSource();
    QString getOutput();


private slots:
    void on_btnBrowseSource_clicked();

    void on_btnBrowseOutput_clicked();

private:
    Ui::NewAnimatorDialog *ui;
};

#endif // NEWANIMATORDIALOG_H
