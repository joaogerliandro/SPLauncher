#ifndef ADD_GAME_DIALOG_H
#define ADD_GAME_DIALOG_H

#include <QDialog>

namespace Ui {
class AddGameDialog;
}

class AddGameDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddGameDialog(QWidget *parent = nullptr);
    ~AddGameDialog();

private:
    Ui::AddGameDialog *ui;
};

#endif // ADD_GAME_DIALOG_H
