#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qmessagebox.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::isSnt(int n)
{
    if(n < 2)
        return false;

    for(int i = 2; i < n; i++)
    {
        if(n % i == 0)
        {
            return false;
        }
    }

    return true;
}

void MainWindow::on_pushButton_nhap_clicked()
{
    for(int i = 0; i < ui->lineEdit_n->text().length(); i++)
    {
        if(i >= 1)
        {
            if(ui->lineEdit_n->text().at(i) < '0' || ui->lineEdit_n->text().at(i) > '9')
            {
                QMessageBox a;
                a.setWindowTitle("GRRR!!");
                a.setText("Hay nhap vao so!!!");
                a.setButtonText(0, "OK");
                a.setDefaultButton(0);
                a.setIcon(QMessageBox::Warning);
                a.exec();
                return;
            }
        } else
        {
            if(ui->lineEdit_n->text().at(i) != "n" || ui->lineEdit_n->text().at(i) < '0' || ui->lineEdit_n->text().at(i) > '9')
            {
                QMessageBox a;
                a.setWindowTitle("GRRR!!");
                a.setText("Hay nhap vao so!!!");
                a.setButtonText(0, "OK");
                a.setDefaultButton(0);
                a.setIcon(QMessageBox::Warning);
                a.exec();
                return;
            }
        }
    }

    int n = ui->lineEdit_n->text().toInt();

    if(isSnt(n))
    {
        ui->lineEdit_kt->setText("La so nguyen to");
    } else
    {
        ui->lineEdit_kt->setText("Khong phai so nguyen to");
    }

    QString str = "";

    for(int i = 0; i < n; i++)
    {
        if(isSnt(i))
        {
            str += QString::number(i);
            str += " ";
        }
    }

    ui->lineEdit_nho->setText(str);
}
