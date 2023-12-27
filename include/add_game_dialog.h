#ifndef ADD_GAME_DIALOG_H
#define ADD_GAME_DIALOG_H

#include <QDialog>
#include <QFileDialog>

namespace Ui {
class AddGameDialog;
}

class AddGameDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddGameDialog(QWidget *parent = nullptr);
    ~AddGameDialog();

private slots:
    void on_select_file_button_clicked();

private:
    Ui::AddGameDialog *ui;
    QString file_path;
    QString directory_path;
};

#endif // ADD_GAME_DIALOG_H
