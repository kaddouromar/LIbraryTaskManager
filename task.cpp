#include "task.h"

// Utility function to format time
std::string formatTime(std::time_t time) {
    if (time == 0) return "N/A";
    char buffer[80];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", std::localtime(&time));
    return std::string(buffer);
}

// Constructors
Task::Task(int taskId, TaskType type, const std::string& description, int bookId, int userId)
    : taskId(taskId), type(type), bookId(bookId), userId(userId), description(description), 
      status(TaskStatus::Pending), dateCreated(std::time(nullptr)), dateCompleted(0) {}

// Getters
int Task::getTaskId() const { return taskId; }

TaskType Task::getType() const { return type; }

int Task::getBookId() const { return bookId; }

int Task::getUserId() const { return userId; }

std::string Task::getDescription() const { return description; }

TaskStatus Task::getStatus() const { return status; }

std::string Task::getDateCreated() const { return formatTime(dateCreated); }

std::string Task::getDateCompleted() const { return formatTime(dateCompleted); }

// Setters
void Task::setDescription(const std::string& newDescription) {
    description = newDescription;
}

void Task::completeTask() {
    if (status == TaskStatus::Completed) {
        std::cerr << "Task is already completed.\n";
        return;
    }
    status = TaskStatus::Completed;
    dateCompleted = std::time(nullptr);
}

// Display Task Info
void Task::displayTaskInfo() const {
    std::cout << "Task ID: " << taskId << "\n"
              << "Type: " << taskTypeToString(type) << "\n"
              << "Description: " << description << "\n"
              << "Book ID: " << (bookId != 0 ? std::to_string(bookId) : "N/A") << "\n"
              << "User ID: " << (userId != 0 ? std::to_string(userId) : "N/A") << "\n"
              << "Status: " << taskStatusToString(status) << "\n"
              << "Date Created: " << getDateCreated() << "\n"
              << "Date Completed: " << getDateCompleted() << "\n";
}

// Utility
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
    switch (status) {
        case TaskStatus::Pending: return "Pending";
        case TaskStatus::Completed: return "Completed";
        default: return "Unknown";
    }
}
