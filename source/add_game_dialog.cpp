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
