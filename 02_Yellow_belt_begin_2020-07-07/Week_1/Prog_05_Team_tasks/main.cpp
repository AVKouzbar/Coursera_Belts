#include <iostream>
#include <string>
#include <map>
#include <tuple>
#include <vector>

using namespace std;

// Перечислимый тип для статуса задачи
enum class TaskStatus {
    NEW,          // новая
    IN_PROGRESS,  // в разработке
    TESTING,      // на тестировании
    DONE          // завершена
};

// Объявляем тип-синоним для map<TaskStatus, int>,
// позволяющего хранить количество задач каждого статуса
using TasksInfo = map<TaskStatus, int>;

void PrintTasksInfo(TasksInfo tasks_info) {
    cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
         ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
         ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
         ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
}

void RemoveZeros(TasksInfo& tasks_info) {
    // Соберём те статусы, которые нужно убрать из словаря
    vector<TaskStatus> statuses_to_remove;
    for (const auto& task_item : tasks_info) {
        if (task_item.second == 0) {
            statuses_to_remove.push_back(task_item.first);
        }
    }
    for (const TaskStatus status : statuses_to_remove) {
        tasks_info.erase(status);
    }
    if (tasks_info[TaskStatus::NEW] == 0) {
        tasks_info.erase(TaskStatus::NEW);
    }
}

TaskStatus Next(TaskStatus task_status) {
    return static_cast<TaskStatus>(static_cast<int>(task_status) + 1);
}

class TeamTasks {
public:
    // Получить статистику по статусам задач конкретного разработчика
    const TasksInfo& GetPersonTasksInfo(const string& person) const {
        return person_tasks_.at(person);
    }

    // Добавить новую задачу (в статусе NEW) для конкретного разработчика
    void AddNewTask(const string& person) {
        ++person_tasks_[person][TaskStatus::NEW];
    }

    // Обновить статусы по данному количеству задач конкретного разработчика
    tuple<TasksInfo, TasksInfo> PerformPersonTasks(
            const string& person, int task_count) {
        TasksInfo updated_tasks, untouched_tasks;
        TasksInfo& tasks = person_tasks_[person];

        for (TaskStatus status = TaskStatus::NEW;
             status != TaskStatus::DONE;
             status = Next(status)) {
            // Считаем обновлённые
            updated_tasks[Next(status)] = min(task_count, tasks[status]);
            // Считаем, сколько осталось обновить
            task_count -= updated_tasks[Next(status)];
        }

        for (TaskStatus status = TaskStatus::NEW;
             status != TaskStatus::DONE;
             status = Next(status)) {
            untouched_tasks[status] = tasks[status] - updated_tasks[Next(status)];
            tasks[status] += updated_tasks[status] - updated_tasks[Next(status)];
        }
        // По условию DONE задачи не нужно вовзвращать в не обновлённых задачах
        tasks[TaskStatus::DONE] += updated_tasks[TaskStatus::DONE];

        // По условию в словарях не должно быть нулей
        RemoveZeros(updated_tasks);
        RemoveZeros(untouched_tasks);
        RemoveZeros(person_tasks_[person]);
        int c = 0;
        return {updated_tasks, untouched_tasks};
    }

private:
    map<string, TasksInfo> person_tasks_;
};

int main() {
    TeamTasks tasks;
    for (int i = 0; i < 5; ++i) {
        tasks.AddNewTask("Alice");
    }
    tasks.PerformPersonTasks("Alice", 5);
    tasks.PerformPersonTasks("Alice", 5);
    tasks.PerformPersonTasks("Alice", 1);
    for (int i = 0; i < 5; ++i) {
        tasks.AddNewTask("Alice");
    }
    tasks.PerformPersonTasks("Alice", 2);
    PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));
    tasks.PerformPersonTasks("Alice", 4);
    PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));


    return 0;
}