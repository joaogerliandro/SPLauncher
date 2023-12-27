#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QStringList header_labels;
    header_labels << "Title" << "File Path";

    ui->game_list->setColumnCount(2);
    ui->game_list->setHorizontalHeaderLabels(header_labels);
    ui->game_list->horizontalHeader()->setStretchLastSection(true);
    ui->game_list->horizontalHeader()->setSectionResizeMode (QHeaderView::Fixed);
    ui->game_list->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->game_list->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->game_list->setFocusPolicy(Qt::NoFocus);
    ui->game_list->verticalHeader()->hide();

    load_game_list();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::load_game_list(std::string_view file_stream)
{
    std::fstream game_list_file(file_stream.data());

    if(!game_list_file.is_open())
    {
        game_list_file.open(file_stream.data(), std::fstream::in | std::fstream::out | std::fstream::trunc);

        if(!game_list_file.is_open())
            throw "[ERROR]: Unable to create settings file ! Leaving the program ...";
    }
    else
    {
        std::string file_line;

        while(std::getline(game_list_file, file_line))
        {
            std::stringstream str_stream(file_line);

            std::string game_name;
            std::string file_path;

            str_stream >> game_name;
            str_stream >> file_path;

            int row_count = ui->game_list->rowCount();

            QTableWidgetItem* game_name_wgt = new QTableWidgetItem(QString::fromStdString(game_name));
            QTableWidgetItem* file_path_wgt = new QTableWidgetItem(QString::fromStdString(file_path));

            game_name_wgt->setTextAlignment(Qt::AlignCenter);
            file_path_wgt->setTextAlignment(Qt::AlignCenter);

            ui->game_list->insertRow(row_count);

            ui->game_list->setItem(row_count, 0, game_name_wgt);
            ui->game_list->setItem(row_count, 1, file_path_wgt);
        }
    }

    game_list_file.close();
}

void MainWindow::on_start_button_clicked()
{
    /*if(!file_path.isEmpty())
    {
        QProcess::startDetached(file_path, QStringList(), directory_path);

        this->close();
    }*/
}

void MainWindow::on_add_button_clicked()
{
    AddGameDialog *add_game_dialog = new AddGameDialog(this);

    add_game_dialog->show();
}

