#include "task.h"

Task::Task():state(State::InProgress)
{}

Task::Task(QString task_name)
    :task_name(task_name), date(), description(""), state(State::InProgress)
{
}

Task::Task(QString task_name, QDate date) :Task(task_name)
{
    this->date = date;
}

Task::Task(QString task_name, QDate date, QString description) :Task(task_name, date)
{
    this->description = description;
}

Task::Task(QString task_name, QString description) :Task(task_name)
{
    this->description = description;
}

const QString& Task::getTaskName() const
{
    return task_name;
}

const QDate& Task::getDate() const
{
    return date;
}

const QString& Task::getDescription()const
{
    return description;
}

State Task::getState() const
{
    return state;
}

void Task::setTaskName(const QString& task_name)
{
    this->task_name = task_name;
}

void Task::setDate(const QDate& date)
{
    this->date = date;
}

void Task::setDescription(const QString& description)
{
    this->description = description;
}

void Task::setState(State state)
{
    this->state = state;
}

QJsonObject Task::convertToJson() const
{
    QJsonObject record_object;
    record_object.insert("TaskName", QJsonValue::fromVariant(task_name));
    record_object.insert("Description", QJsonValue::fromVariant(description));
    record_object.insert("IsDone", QJsonValue::fromVariant(bool(state)));
    record_object.insert("Date", QJsonValue::fromVariant(date.toString("dd.MM.yyyy")));
    return record_object;
}

Task* Task::createFromJson(QJsonObject json)
{
    Task* task = new Task();
    if(json.contains("TaskName"))
        task->setTaskName(json["TaskName"].toString());
    if(json.contains("Description"))
        task->setDescription(json["Description"].toString());
    if(json.contains("IsDone"))
        task->setState(State(json["IsDone"].toBool()));
    if(json.contains("Date")){
        if (json["Date"].isNull())
            task->setDate(QDate());
        else {
            task->setDate(QDate::fromString(json["Date"].toString(), "dd.MM.yyyy"));
        }
    }
    return task;
}
