#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    add_game_dialog = new AddGameDialog();

    connect(add_game_dialog, SIGNAL(add_game_item(GameItem)), this, SLOT(add_game_item(GameItem)));

    load_game_list();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::load_game_list_file(std::string_view file_stream)
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

            GameItem new_game_item(game_name, file_path);
            game_item_list.push_back(new_game_item);
        }
    }

    game_list_file.close();
}

void MainWindow::load_game_list_grid()
{
    for(GameItem game_item : game_item_list)
    {
        int row_count = ui->game_list->rowCount();

        QTableWidgetItem* game_name_wgt = new QTableWidgetItem(game_item.m_name);
        QTableWidgetItem* file_path_wgt = new QTableWidgetItem(game_item.m_file_path);

        game_name_wgt->setTextAlignment(Qt::AlignCenter);
        file_path_wgt->setTextAlignment(Qt::AlignCenter);

        ui->game_list->insertRow(row_count);

        ui->game_list->setItem(row_count, 0, game_name_wgt);
        ui->game_list->setItem(row_count, 1, file_path_wgt);
    }
}

void MainWindow::load_game_list()
{
    header_labels << "Title" << "File Path";

    ui->game_list->setColumnCount(2);
    ui->game_list->setHorizontalHeaderLabels(header_labels);
    ui->game_list->horizontalHeader()->setStretchLastSection(true);
    ui->game_list->horizontalHeader()->setSectionResizeMode (QHeaderView::Fixed);
    ui->game_list->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->game_list->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->game_list->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->game_list->setFocusPolicy(Qt::NoFocus);
    ui->game_list->verticalHeader()->hide();

    load_game_list_file();

    load_game_list_grid();
}

void MainWindow::reload_game_list_grid()
{
    ui->game_list->clear();
    ui->game_list->setRowCount(0);

    ui->game_list->setHorizontalHeaderLabels(header_labels);

    load_game_list_grid();
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
    add_game_dialog->show();
}

void MainWindow::add_game_item(GameItem new_game_item)
{
    game_item_list.push_back(new_game_item);

    reload_game_list_grid();
}

GameItem* MainWindow::get_selected_game_item()
{
    QItemSelectionModel *select = ui->game_list->selectionModel();
    QAbstractItemModel *model = ui->game_list->model();

    if(select->hasSelection())
    {
        QModelIndexList index_list = select->selectedRows();

        for(QModelIndex index : index_list)
        {
            QModelIndex game_name_model = model->index(index.row(), 0);
            QModelIndex file_path_model = model->index(index.row(), 1);

            return new GameItem(game_name_model.data().toString(), file_path_model.data().toString());
        }
    }
    else
    {
        return nullptr;
    }
}

void MainWindow::on_remove_button_clicked()
{
    GameItem *selected_game_item = get_selected_game_item();

    if(selected_game_item != nullptr)
    {
        std::vector<GameItem>::iterator selected_game_itr = game_item_list.begin();

        for(GameItem game_item : game_item_list)
        {
            if(game_item.m_name != selected_game_item->m_name)
            {
                selected_game_itr++;
            }
            else
            {
                break;
            }
        }

        game_item_list.erase(selected_game_itr);

        reload_game_list_grid();
    }
    else
    {
        std::cout << "Não" << std::endl;
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (!ui->game_list->indexAt(event->pos()).isValid())
        ui->game_list->clearSelection();
}
