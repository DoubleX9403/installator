#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QListView>
#include <QStringListModel>
#include <QProcess>
#include <QDir>
#include <QFile>
#include <QString>
#include <iostream>
#include <cstddef>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QStringListModel *model;
    QStringList filenames;
        QStringList oldlist;

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
