#ifndef TASK_H
#define TASK_H

#include <string>
#include <ctime>
#include <vector>    // For using std::vector
#include "user.h"    // Include User header to access User class
#include "book.h"    // Include Book header if necessary for book details

enum class TaskType {
    BorrowBook,
    ReturnBook,
    Maintenance,
    BookOrder,
    Custom
};

enum class TaskStatus {
    Pending,
    Completed
};

class Task {
private:
    int taskId;
    TaskType type;
    std::string description;
    int bookId;
    int userId;
    TaskStatus status;
    std::time_t dateCreated;
    std::time_t dateCompleted;

    std::string formatDate(std::time_t time) const;  // Make this method const since it doesn't modify the object

public:
    Task(int taskId, TaskType type, const std::string& description, int bookId, int userId);

    int getTaskId() const;
    TaskType getType() const;
    int getBookId() const;
    int getUserId() const;
    std::string getDescription() const;
    TaskStatus getStatus() const;
    std::string getDateCreated() const;
    std::string getDateCompleted() const;

    void setDescription(const std::string& newDescription);
    void completeTask();
    void displayTaskInfo() const;

    static std::string taskTypeToString(TaskType type);
    static std::string taskStatusToString(TaskStatus status);

    // Updated method signature to include borrowDate and dueDate
    void processBorrowBook(std::vector<User>& users, const std::string& borrowDate, const std::string& dueDate);
};

#endif
