#ifndef CONNECTION_H
#define CONNECTION_H

#include <QMessageBox>
#include <QtSql>
#include <QSqlDatabase>

inline bool createConnection()//соединение
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setDatabaseName("postgres");
    db.setUserName("postgres");
    db.setPassword("root");
    if(!db.open())
    {
        QMessageBox:: warning (0,"Ошибка",db.lastError().text());
        return false;
    }
    else
    {
        QMessageBox::information(0,"Успешно","Соединие установлено");
        return true;
    }
}

inline bool createTables()//создание таблиц
{
    QSqlQuery query;
    query.exec("CREATE TABLE passwords ("
               "id INTEGER PRIMARY KEY, "
               "login VARCHAR(10) NOT NULL, "
               "passwd VARCHAR(10) NOT NULL, "
               "datepass DATE NOT NULL)");
    return (1);
}
#endif // CONNECTION_H
