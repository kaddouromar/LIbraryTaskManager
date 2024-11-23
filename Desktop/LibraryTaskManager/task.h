#ifndef TASK_H
#define TASK_H

#include <string>
#include <iostream>
#include <vector>
#include <ctime>

enum class TaskStatus {
    Pending,
    Completed
};

enum class TaskType {
    BorrowBook,
    ReturnBook,
    Maintenance,
    BookOrder,
    Custom
};

class Task {
private:
    int taskId;
    TaskType type;
    int bookId;      // Optional (0 if not applicable)
    int userId;      // Optional (0 if not applicable)
    std::string description;
    TaskStatus status;
    std::time_t dateCreated;
    std::time_t dateCompleted; // 0 if not yet completed

public:
    // Constructors
    Task(int taskId, TaskType type, const std::string& description, int bookId = 0, int userId = 0);

    // Getters
    int getTaskId() const;
    TaskType getType() const;
    int getBookId() const;
    int getUserId() const;
    std::string getDescription() const;
    TaskStatus getStatus() const;
    std::string getDateCreated() const;
    std::string getDateCompleted() const;

    // Setters
    void setDescription(const std::string& newDescription);
    void completeTask();

    // Display Task Info
    void displayTaskInfo() const;

    // Utility
    static std::string taskTypeToString(TaskType type);
    static std::string taskStatusToString(TaskStatus status);
};

#endif // TASK_H
