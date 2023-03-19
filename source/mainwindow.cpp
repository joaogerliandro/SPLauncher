#include "mainwindow.h"
#include "./ui_mainwindow.h"

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

void MainWindow::on_start_button_clicked()
{
    if(!file_path.isEmpty())
    {
        QProcess::startDetached(file_path);
    }
}

void MainWindow::on_open_file_button_clicked()
{
    file_path = QFileDialog::getOpenFileName(this, "Open a file", "C://", "Executable (*.exe)");

    if(!file_path.isEmpty())
        ui->file_path->setText(file_path);
}
