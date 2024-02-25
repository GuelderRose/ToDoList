#ifndef TASKCREATORDIALOG_H
#define TASKCREATORDIALOG_H

#include "task.h"

#include <QCalendarWidget>
#include <QComboBox>
#include <QDialog>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <QPushButton>
#include <QVariant>
#include <QVBoxLayout>

class TaskCreatorDialog : public QDialog
{
    Q_OBJECT

public:
    TaskCreatorDialog(QWidget* parent=nullptr, Task task = Task());

    static QVariant getTask(Task task, QWidget *parent);

public slots:
    void taskNameChanged(const QString &text);
    void taskDescriptionChanged(const QString &text);
    void taskStateChanged(int idx);
    void taskDateChanged(QDate date);
    void okButtonClicked();

private:
    Task default_task;

    QCalendarWidget* calendar_widget;

    QLabel *task_name_label;
    QLabel *task_description_label;
    QLabel *task_state_label;

    QLineEdit* task_name_edit;   
    QLineEdit* task_description_edit;

    QComboBox* task_state_edit;

    QPushButton* ok_button;
    QPushButton* cancel_button;
};

#endif // TASKCREATORDIALOG_H
