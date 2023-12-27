#include "add_game_dialog.h"
#include "ui_add_game_dialog.h"

AddGameDialog::AddGameDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddGameDialog)
{
    ui->setupUi(this);
}

AddGameDialog::~AddGameDialog()
{
    delete ui;
}

void AddGameDialog::on_select_file_button_clicked()
{
    QString file_path = QFileDialog::getOpenFileName(this, "Open a file", ".", "Executable (*.exe)");

    if(!file_path.isEmpty())
        ui->file_path->setText(file_path);
}

void AddGameDialog::on_confirm_button_clicked()
{
    QString game_name = ui->game_name->text();
    QString game_file_path = ui->file_path->text();

    if(!game_name.isEmpty() && !game_file_path.isEmpty())
    {
        GameItem new_game_item(game_name, game_file_path);

        ui->game_name->clear();
        ui->file_path->clear();

        this->close();
        emit add_game_item(new_game_item);
    }
}

void AddGameDialog::on_cancel_button_clicked()
{
    ui->game_name->clear();
    ui->file_path->clear();

    this->close();
}

void AddGameDialog::on_AddGameDialog_finished(int result)
{
    ui->game_name->clear();
    ui->file_path->clear();
}

