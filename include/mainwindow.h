#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>

#include <QMainWindow>
#include <QProcess>
#include <QMessageBox>
#include <QTableWidgetItem>

#include <string>
#include <fstream>
#include <sstream>

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

private slots:
    void on_start_button_clicked();

    void load_game_list(std::string_view file_stream = { "game_list.txt" });

    void on_add_button_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
