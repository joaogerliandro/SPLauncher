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
    /*if(!file_path.isEmpty())
    {
        QProcess::startDetached(file_path, QStringList(), directory_path);

        this->close();
    }*/
}

void MainWindow::on_open_file_button_clicked()
{
    /*file_path = QFileDialog::getOpenFileName(this, "Open a file", ".", "Executable (*.exe)");

    QDir file_dir = QFileInfo(file_path).absoluteDir();

    directory_path = file_dir.absolutePath();

    if(!file_path.isEmpty())
        ui->file_path->setText(file_path);*/
}
