#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>

#include <QMainWindow>
#include <QProcess>
#include <QFileDialog>
#include <QMessageBox>

#include <add_game_dialog.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QString file_path;
    QString directory_path;

private slots:
    void on_start_button_clicked();

    void on_open_file_button_clicked();

    void on_add_button_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
