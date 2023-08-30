#pragma once
#include <string>
#include <chrono>

class Task {
public:
    Task(const std::string& title, const std::string& description, const std::chrono::system_clock::time_point& dueDate);

    // Getters
    std::string getTitle() const;
    std::string getDescription() const;
    std::chrono::system_clock::time_point getDueDate() const;
    bool isCompleted() const;

    // Setters
    void markAsCompleted();

private:
    std::string title;
    std::string description;
    std::chrono::system_clock::time_point dueDate;
    bool completed = false;
};

