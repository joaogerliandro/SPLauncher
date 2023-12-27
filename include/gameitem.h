#ifndef GAMEITEM_H
#define GAMEITEM_H

class GameItem
{
    public:
        GameItem(std::string name, std::string file_path) : m_name(QString::fromStdString(name)), m_file_path(QString::fromStdString(file_path)) {}

        QString m_name;
        QString m_file_path;
};

#endif // GAMEITEM_H
