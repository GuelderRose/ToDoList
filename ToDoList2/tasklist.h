#ifndef TASKLIST_H
#define TASKLIST_H

#include "task.h"

#include <QJsonArray>
#include <QJsonObject>
#include <QObject>
#include <QSet>

class TaskList
{
public:
    explicit TaskList();

    QDate getMinDate() const;
    QDate getMaxDate() const;
    int size() const { return tasks.size(); }

    void addTask(Task* task);
    void deleteTask(Task* task);

    TaskList filterFromDate(QDate start)const;
    TaskList filterToDate(QDate finish)const;
    TaskList filterByState(State state)const;
    TaskList filterByName(QString pattern)const;
    TaskList filterByDescription(QString pattern)const;

    QJsonArray convertToJson() const;
    static TaskList createFromJson(QJsonArray json);

    friend QVector<Task*>::iterator begin(TaskList &x);
    friend QVector<Task*>::iterator end(TaskList &x);

private:
    QVector<Task*> tasks;
};

#endif // TASKLIST_H
