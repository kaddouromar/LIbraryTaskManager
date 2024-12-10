#include "task.h"
#include "user.h" // Include user header for the processBorrowBook test
#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <ctime>

// Helper function to create a dummy time string
std::string getCurrentTimeAsString() {
    std::time_t now = std::time(nullptr);
    char buffer[20];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", std::localtime(&now));
    return std::string(buffer);
}

// Test Task Constructor
TEST(TaskTest, ConstructorTest) {
    Task task(1, TaskType::BorrowBook, "Borrow a book", 1001, 2001);

    EXPECT_EQ(task.getTaskId(), 1);
    EXPECT_EQ(task.getType(), TaskType::BorrowBook);
    EXPECT_EQ(task.getBookId(), 1001);
    EXPECT_EQ(task.getUserId(), 2001);
    EXPECT_EQ(task.getDescription(), "Borrow a book");
    EXPECT_EQ(task.getStatus(), TaskStatus::Pending);
    EXPECT_EQ(task.getDateCompleted(), "Completed");
}

// Test Task Type and Status Conversions
TEST(TaskTest, TypeAndStatusToString) {
    EXPECT_EQ(Task::taskTypeToString(TaskType::BorrowBook), "Borrow Book");
    EXPECT_EQ(Task::taskTypeToString(TaskType::ReturnBook), "Return Book");
    EXPECT_EQ(Task::taskStatusToString(TaskStatus::Pending), "Pending");
    EXPECT_EQ(Task::taskStatusToString(TaskStatus::Completed), "Completed");
}

// Test Completing a Task
TEST(TaskTest, CompleteTask) {
    Task task(2, TaskType::ReturnBook, "Return a book", 1002, 2002);

    task.completeTask();
    EXPECT_EQ(task.getStatus(), TaskStatus::Completed);
    EXPECT_NE(task.getDateCompleted(), "Completed"); // Should not be the default string anymore
}

// Test Processing Borrow Book
TEST(TaskTest, ProcessBorrowBook) {
    std::vector<User> users = {
        User(2001, "Alice", "Engineering", 21),
        User(2002, "Bob", "Science", 22)
    };

    Task task(3, TaskType::BorrowBook, "Borrow a book", 1003, 2001);

    std::string borrowDate = "2024-12-01";
    std::string dueDate = "2024-12-15";

    // Process the borrow book task
    task.processBorrowBook(users, borrowDate, dueDate);

    // Check if the book was correctly added to the user's borrowed books
    EXPECT_TRUE(users[0].hasBorrowedBook(1003));
    EXPECT_FALSE(users[1].hasBorrowedBook(1003)); // User 2002 should not have borrowed the book
}

// Test Displaying Task Info
TEST(TaskTest, DisplayTaskInfo) {
    Task task(4, TaskType::Custom, "Custom task example", 0, 0);

    testing::internal::CaptureStdout();
    task.displayTaskInfo();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Task ID: 4"), std::string::npos);
    EXPECT_NE(output.find("Type: Custom"), std::string::npos);
    EXPECT_NE(output.find("Description: Custom task example"), std::string::npos);
}
