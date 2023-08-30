#include <iostream>
#include <chrono>
#include <string>
#include "Task.h"
#include "TaskManager.h"

int main() {
    TaskManager taskManager;

    while (true) {
        std::cout << "\nTask Manager Menu:\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. Mark Task as Complete\n";
        std::cout << "3. List All Tasks\n";
        std::cout << "4. List Incomplete Tasks\n";
        std::cout << "5. Save Tasks to File\n";
        std::cout << "6. Load Tasks from File\n";
        std::cout << "0. Exit\n";
        std::cout << "Select an option: ";

        int choice;
        std::cin >> choice;

        if (choice == 0) {
            std::cout << "Exiting...\n";
            break;
        }

        switch (choice) {
        case 1: {
            std::string title, description;
            std::cout << "Enter task title: ";
            std::cin.ignore(); // Clear the newline from the previous input
            std::getline(std::cin, title);
            std::cout << "Enter task description: ";
            std::getline(std::cin, description);

            // Collect due date
            std::cout << "Enter due date (YYYY MM DD): ";
            int year, month, day;
            std::cin >> year >> month >> day;

            // Create a tm structure and assign its values
            std::tm dueDate_tm{};
            dueDate_tm.tm_year = year - 1900; // Years since 1900
            dueDate_tm.tm_mon = month - 1;    // Months since January (0-based)
            dueDate_tm.tm_mday = day;

            // Convert the tm structure to a time_t timestamp
            std::time_t dueDate_time = std::mktime(&dueDate_tm);

            // Convert the time_t timestamp to a chrono time_point
            std::chrono::system_clock::time_point dueDate = std::chrono::system_clock::from_time_t(dueDate_time);

            // Add the task to the task manager
            taskManager.addTask(Task(title, description, dueDate));
            break;
        }
        case 2: {
            int taskIndex;
            std::cout << "Enter the index of the task to mark as complete: ";
            std::cin >> taskIndex;
            taskManager.markTaskAsComplete(taskIndex - 1); // Adjust for 0-based index
            break;
        }
        case 3: {
            taskManager.listAllTasks();
            break;
        }
        case 4: {
            taskManager.listIncompleteTasks();
            break;
        }
        case 5: {
            std::string filename;
            std::cout << "Enter filename to save tasks: ";
            std::cin >> filename;
            taskManager.saveTasksToFile(filename);
            break;
        }
        case 6: {
            std::string filename;
            std::cout << "Enter filename to load tasks from: ";
            std::cin >> filename;
            taskManager.loadTasksFromFile(filename);
            break;
        }
        default:
            std::cout << "Invalid choice. Please select a valid option.\n";
            break;
        }
    }

    return 0;
}
