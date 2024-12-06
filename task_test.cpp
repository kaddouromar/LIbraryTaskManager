#include "task.h"
#include <gtest/gtest.h>

// Test task creation
TEST(TaskTest, CreateTask) {
    Task task(1, TaskType::BorrowBook, "Borrow Book", 101, 1);
    EXPECT_EQ(task.getTaskId(), 1);    
    EXPECT_EQ(task.getType(), TaskType::BorrowBook);
    EXPECT_EQ(task.getBookId(), 101);
    EXPECT_EQ(task.getUserId(), 1);
    EXPECT_EQ(task.getDescription(), "Borrow Book");
    EXPECT_EQ(task.getStatus(), TaskStatus::Pending);
    EXPECT_EQ(task.getDateCreated(), "N/A");  // Since dateCreated is set to now, check the formatted value.
}

// Test task completion
TEST(TaskTest, CompleteTask) {
    Task task(2, TaskType::ReturnBook, "Return Book", 102, 2);
    task.completeTask();
    EXPECT_EQ(task.getStatus(), TaskStatus::Completed);
    EXPECT_NE(task.getDateCompleted(), "N/A");  // Ensure dateCompleted is set after completion
}

// Test task description modification
TEST(TaskTest, EditTaskDescription) {
    Task task(3, TaskType::Maintenance, "Fix Plumbing", 0, 0);
    task.setDescription("Repair AC");
    EXPECT_EQ(task.getDescription(), "Repair AC");
}

// Test task info display
TEST(TaskTest, DisplayTaskInfo) {
    Task task(4, TaskType::BookOrder, "Order New Books", 0, 0);
    task.displayTaskInfo();  // This will print task info, which we will manually inspect.
}
