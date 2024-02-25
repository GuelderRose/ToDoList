#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include "taskcreatordialog.h"
#include "tasklist.h"
#include "taskwidget.h"
#include "task.h"

#include <QDateEdit>
#include <QFile>
#include <QFileInfo>
#include <QHBoxLayout>
#include <QInputDialog>
#include <QJsonDocument>
#include <QLineEdit>
#include <QListWidget>
#include <QPixmap>
#include <QPushButton>
#include <QVBoxLayout>
#include <QVector>
#include <QWidget>

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

private slots:
    void onAddTaskButtonClicked();
    void onDeleteWidgetButtonClicked(TaskWidget* task_widget);
    void onEditWidgetButtonClicked(TaskWidget *task_widget);
    void onCheckBoxClicked(TaskWidget* task_widget);

    void resetFilters();
    void resetDateFilter();
    void resetStateFilter();
    void resetNameFilter();
    void resetDescriptionFilter();

    void redrawView();

private:
    void saveTasks();
    TaskList loadTasks();

    Task* getCorrespondingTask(TaskWidget *task_widget);

    void updateTaskWidgetList();
    void initTaskWidgetList(TaskList& tasks);
    void drawNewTaskWidget(Task* task, TaskWidget* task_widget);
    void updateFiltredTaskList();

    void closeEvent(QCloseEvent *event) override;

    std::pair<QDate, QDate> getDefaultDatesForFilterWidget();

    QLabel *filter_label;
    QLabel *state_filter_label;
    QLabel *date_filter_label;
    QLabel *name_filter_label;
    QLabel *desc_filter_label;

    QLineEdit *search_by_name_line;
    QLineEdit *search_by_desc_line;
    QDateEdit *left_date_edit;
    QDateEdit *right_date_edit;

    QPixmap reset_filters_icon;
    QPixmap reset_one_filter_icon;

    QComboBox *task_state_filter;    

    QPushButton *reset_all_filters_button;
    QPushButton *reset_filter_by_state_button;
    QPushButton *reset_filter_by_date_button;
    QPushButton *reset_filter_by_name_button;
    QPushButton *reset_filter_by_desc_button;
    QPushButton *add_task_button;

    TaskList full_task_list;
    TaskList showed_task_list;
    QListWidget *task_widget_list;
    QVector<std::pair<TaskWidget*, Task*>> showed_tasks;

};
#endif // MAINWIDGET_H
