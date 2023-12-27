#ifndef ADD_GAME_DIALOG_H
#define ADD_GAME_DIALOG_H

#include <QDialog>
#include <QFileDialog>

#include <gameitem.h>

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
        void add_game_item(GameItem new_game_item);

    private slots:
        void on_select_file_button_clicked();

        void on_confirm_button_clicked();

        void on_cancel_button_clicked();

        void on_AddGameDialog_finished(int result);

    private:
        Ui::AddGameDialog *ui;
};

#endif // ADD_GAME_DIALOG_H
