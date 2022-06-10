#include "mainwindow.h"
#include "ui_mainwindow.h"
# include <QDebug>

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


void MainWindow::on_pushButton_clicked()
{
    QStringListModel *model;
        model = new QStringListModel(this);
    QStringList filenames = QFileDialog::getOpenFileNames(this, tr("Open Files"), "/home");
    model->setStringList(filenames);
    ui->listView->setModel(model);

}
void MainWindow::on_pushButton_2_clicked()
{

    QProcess *runBuild = new QProcess(this);
    QStringList arguments;
        arguments <<  "a" << "-mx5" << "-r0" << "D:/testarchive/archive.zip" << "D:/testarchive";
     runBuild->start("D:/7-Zip/7z.exe",arguments);

}
