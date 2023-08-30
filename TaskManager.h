#pragma once
#include <vector>
#include "Task.h"

class TaskManager {
public:
    void addTask(const Task& task);
    void markTaskAsComplete(int taskIndex);
    void listAllTasks() const;
    void listIncompleteTasks() const;
    void saveTasksToFile(const std::string& filename) const;
    void loadTasksFromFile(const std::string& filename);

private:
    std::vector<Task> tasks;
};


