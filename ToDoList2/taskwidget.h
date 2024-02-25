#ifndef TASKWIDGET_H
#define TASKWIDGET_H

#include "task.h"

#include <QCheckBox>
#include <QCoreApplication>
#include <QHBoxLayout>
#include <QLabel>
#include <QListWidgetItem>
#include <QPalette>
#include <QPixmap>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

class TaskWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TaskWidget(QWidget *parent = nullptr);
    TaskWidget(const Task* task, QWidget *parent = nullptr);

    void updateView(const Task* task);
    void changeTaskState();

signals:
    void taskDeleted(TaskWidget* task);
    void taskChanged(TaskWidget* task);
    void taskEdited(TaskWidget* task);

private slots:
    void onDeleteButtonClicked();
    void onEditButtonClicked();
    void onCheckBoxClicked();

private:
    QCheckBox *check_box;

    QPushButton *delete_button;
    QPushButton *edit_button;

    QPixmap delete_icon;
    QPixmap edit_icon;

    QLabel *task_name;
    QLabel *task_date;
    QLabel *task_description;    
};

#endif // TASKWIDGET_H
