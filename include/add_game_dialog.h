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

signals:
    void add_game_item(QString game_name, QString file_path);

private slots:
    void on_select_file_button_clicked();

    void on_confirm_button_clicked();

private:
    Ui::AddGameDialog *ui;
    QString file_path;
    QString game_name;
    QString directory_path;
};

#endif // ADD_GAME_DIALOG_H
