#ifndef TASK_H
#define TASK_H

#include <QDate>
#include <QJsonObject>
#include <QObject>
#include <QString>

enum class State {
    InProgress,
    Done
};

class Task
{

public:
    explicit Task();
    Task(QString task_name);
    Task(QString task_name, QDate date);
    Task(QString task_name, QDate date, QString description);
    Task(QString task_name, QString description);

    const QString& getTaskName() const;
    const QDate& getDate() const;
    const QString& getDescription() const;
    State getState() const;

    void setTaskName(const QString& task_name);
    void setDate(const QDate& date);
    void setDescription(const QString& description);
    void setState(State state);

    QJsonObject convertToJson() const;
    static Task* createFromJson(QJsonObject json);

private:
    QString task_name;
    QDate date;
    QString description;
    State state;
};

#endif // TASK_H
