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
    file_path = QFileDialog::getOpenFileName(this, "Open a file", ".", "Executable (*.exe)");

    QDir file_dir = QFileInfo(file_path).absoluteDir();

    directory_path = file_dir.absolutePath();

    if(!file_path.isEmpty())
        ui->file_path->setText(file_path);
}

