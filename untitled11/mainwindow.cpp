#include "mainwindow.h"
#include "ui_mainwindow.h"
# include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    model = new QStringListModel(this);
}



MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
//    QStringList oldlist;
    oldlist= model->stringList();
//    QStringList filenames;
    filenames = QFileDialog::getOpenFileNames(this, tr("Open Files"), "/home");
   filenames = filenames + oldlist;
   filenames.removeDuplicates();
    model->setStringList(filenames);
    ui->listView->setModel(model);

}
void MainWindow::on_pushButton_2_clicked()
{

    QProcess *runBuild = new QProcess(this);
    QStringList arguments;
    QDir dir("temp");

    for (int i=0; i<=filenames.size();i++ )
    {
        QStringList parts = filenames.at(i).split("/");
        QString lastBit = parts.at(parts.size()-1);
        QFile::copy(filenames.at(i) , "temp/" + lastBit);
    }

        arguments <<  "a" << "-mx5" << "-r0" << "D:/testarchive/archive.zip" << "D:/testarchive";
     runBuild->start("D:/7-Zip/7z.exe",arguments);

}
void MainWindow::on_pushButton_3_clicked() {
 filenames.clear();
 oldlist.clear();
  model->setStringList(filenames);
 ui->listView->setModel(model);
}
