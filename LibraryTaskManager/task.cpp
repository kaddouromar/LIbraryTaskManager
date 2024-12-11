#include "task.h"
#include <iostream>
#include <algorithm>  // Include this header to use std::find_if
#include <vector> // For handling the vector of users

Task::Task(int taskId, TaskType type, const std::string& description, int bookId, int userId)
    : taskId(taskId), type(type), description(description), bookId(bookId), userId(userId),
      status(TaskStatus::Pending), dateCreated(std::time(nullptr)), dateCompleted(0) {}

int Task::getTaskId() const { return taskId; }

TaskType Task::getType() const { return type; }

int Task::getBookId() const { return bookId; }

int Task::getUserId() const { return userId; }

std::string Task::getDescription() const { return description; }

TaskStatus Task::getStatus() const { return status; }

std::string Task::getDateCreated() const { return formatDate(dateCreated); }

std::string Task::getDateCompleted() const { 
    return dateCompleted != 0 ? formatDate(dateCompleted) : "Not Completed"; 
}

void Task::setDescription(const std::string& newDescription) { description = newDescription; }

void Task::completeTask() {
    status = TaskStatus::Completed;
    dateCompleted = std::time(nullptr); // Set the current time as completion time
}

void Task::displayTaskInfo() const {
    std::cout << "Task ID: " << taskId << "\n"
              << "Type: " << taskTypeToString(type) << "\n"
              << "Description: " << description << "\n"
              << "Book ID: " << bookId << "\n"
              << "User ID: " << userId << "\n"
              << "Created: " << getDateCreated() << "\n"
              << "Completed: " << getDateCompleted() << "\n";
}

std::string Task::taskTypeToString(TaskType type) {
    switch (type) {
        case TaskType::BorrowBook: return "Borrow Book";
        case TaskType::ReturnBook: return "Return Book";
        case TaskType::Maintenance: return "Maintenance";
        case TaskType::BookOrder: return "Book Order";
        case TaskType::Custom: return "Custom";
        default: return "Unknown";
    }
}

std::string Task::taskStatusToString(TaskStatus status) {
    return status == TaskStatus::Pending ? "Pending" : "Completed";
}

std::string Task::formatDate(std::time_t time) const {  // Make this const
    char buffer[20];
    std::tm* tm_info = std::localtime(&time);
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", tm_info);
    return std::string(buffer);
}

// Method to process the borrow book task
void Task::processBorrowBook(std::vector<User>& users, const std::string& borrowDate, const std::string& dueDate) {
    // Find the user by userId and update their borrowed books list
    for (auto& user : users) {
        if (user.getUserId() == userId) {  // Corrected to getUserId()
            user.borrowBook(bookId, borrowDate, dueDate);  // Update the user's borrowed books list with the correct parameters
            std::cout << "User " << user.getName() << " has borrowed book ID " << bookId << "." << std::endl;
            break;
        }
    }
}

// Method to delete a task by its task ID
void Task::deleteTaskById(std::vector<Task>& tasks, int taskId) {
    // Find and remove the task with the given ID
    auto it = std::remove_if(tasks.begin(), tasks.end(), [taskId](const Task& task) {
        return task.getTaskId() == taskId;  // Match task by ID
    });

    if (it != tasks.end()) {
        tasks.erase(it, tasks.end());  // Erases the matched task
        std::cout << "Task with ID " << taskId << " has been deleted.\n";  // Confirmation message
    } else {
        std::cout << "Task with ID " << taskId << " not found.\n";  // If task not found
    }
}
