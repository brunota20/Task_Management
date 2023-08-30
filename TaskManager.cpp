// TaskManager.cpp
#include "TaskManager.h"
#include <iostream>
#include <fstream>

void TaskManager::addTask(const Task& task) {
    tasks.push_back(task); //add a task copy into the end of the tanks vector
}

void TaskManager::markTaskAsComplete(int taskIndex) {
    if (taskIndex >= 0 && taskIndex < tasks.size()) {
        tasks[taskIndex].markAsCompleted();
    }
}

void TaskManager::listAllTasks() const {
    std::cout << "All Tasks:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        const Task& task = tasks[i];
        std::cout << i + 1 << ". " << task.getTitle() << " (" << (task.isCompleted() ? "Completed" : "Incomplete") << ")\n";
    }
}

void TaskManager::listIncompleteTasks() const {
    std::cout << "Incomplete Tasks:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        const Task& task = tasks[i];
        if (!task.isCompleted()) {
            std::cout << i + 1 << ". " << task.getTitle() << "\n";
        }
    }
}

void TaskManager::saveTasksToFile(const std::string& filename) const {
    std::ofstream outputFile(filename);
    if (!outputFile) {
        std::cerr << "Error opening file for writing: " << filename << "\n";
        return;
    }

    for (const Task& task : tasks) {
        outputFile << task.getTitle() << "\n";
        outputFile << task.getDescription() << "\n";
        outputFile << task.getDueDate().time_since_epoch().count() << "\n";
        outputFile << (task.isCompleted() ? "1" : "0") << "\n";
    }

    outputFile.close();
}

void TaskManager::loadTasksFromFile(const std::string& filename) {
    std::ifstream inputFile(filename);
    if (!inputFile) {
        std::cerr << "Error opening file for reading: " << filename << "\n";
        return;
    }

    tasks.clear();
    std::string title, description, completedStr, dueDateStr;
    while (std::getline(inputFile, title)) {
        std::getline(inputFile, description);
        std::getline(inputFile, dueDateStr);
        std::getline(inputFile, completedStr);

        std::chrono::system_clock::time_point dueDate(std::chrono::seconds(std::stoll(dueDateStr)));
        bool completed = (completedStr == "1");

        tasks.emplace_back(title, description, dueDate); // construct and insert the elements directly into the vector tanks
        if (completed) {
            tasks.back().markAsCompleted(); //retrieves the value of the last element in the vector (the last one is the completedStr)
        }
    }

    inputFile.close();
}
