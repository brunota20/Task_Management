#include "Task.h"

Task::Task(const std::string& title, const std::string& description, const std::chrono::system_clock::time_point& dueDate)
    : title(title), description(description), dueDate(dueDate) {}

std::string Task::getTitle() const {
    return title;
}

std::string Task::getDescription() const {
    return description;
}

std::chrono::system_clock::time_point Task::getDueDate() const {
    return dueDate;
}

bool Task::isCompleted() const {
    return completed;
}

void Task::markAsCompleted() {
    completed = true;
}