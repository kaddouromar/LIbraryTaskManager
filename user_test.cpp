#include "user.h"
#include <gtest/gtest.h>

// Test user creation
TEST(UserTest, CreateUser) {
    User user(1, "Alice Johnson", "Engineering", 21);
    EXPECT_EQ(user.getUserId(), 1); // Fixed method name to getUserId()
    EXPECT_EQ(user.getName(), "Alice Johnson");
    EXPECT_EQ(user.getFaculty(), "Engineering");
    EXPECT_EQ(user.getAge(), 21);
}

// Test modifying user details
TEST(UserTest, EditUser) {
    User user(2, "Bob Smith", "Science", 22);
    user.setName("Robert Smith");
    user.setFaculty("Mathematics");
    user.setAge(23);

    EXPECT_EQ(user.getName(), "Robert Smith");
    EXPECT_EQ(user.getFaculty(), "Mathematics");
    EXPECT_EQ(user.getAge(), 23);
}

// Test borrowing books
TEST(UserTest, BorrowBook) {
    User user(3, "Charlie Brown", "Literature", 20);

    // Borrow books
    user.borrowBook(101, "2023-11-01", "2023-11-15");
    user.borrowBook(102, "2023-11-02", "2023-11-16");

    const auto& books = user.getBorrowedBooks();
    ASSERT_EQ(books.size(), 2); // Check the number of borrowed books

    EXPECT_EQ(books[0].bookId, 101); // Validate bookId of the first borrowed book
    EXPECT_EQ(books[0].borrowDate, "2023-11-01"); // Validate borrowDate
    EXPECT_EQ(books[0].dueDate, "2023-11-15"); // Validate dueDate

    EXPECT_EQ(books[1].bookId, 102); // Validate bookId of the second borrowed book
    EXPECT_EQ(books[1].borrowDate, "2023-11-02");
    EXPECT_EQ(books[1].dueDate, "2023-11-16");
}

// Test returning books
TEST(UserTest, ReturnBook) {
    User user(4, "Daisy Miller", "History", 19);

    // Borrow and return books
    user.borrowBook(201, "2023-11-05", "2023-11-20");
    user.borrowBook(202, "2023-11-06", "2023-11-21");

    user.returnBook(201); // Return one book

    const auto& books = user.getBorrowedBooks();
    ASSERT_EQ(books.size(), 1); // Ensure only one book remains
    EXPECT_EQ(books[0].bookId, 202); // The remaining book should have bookId 202
}

// Test checking if a book is borrowed
TEST(UserTest, HasBorrowedBook) {
    User user(5, "Ethan Wright", "Physics", 23);

    user.borrowBook(301, "2023-11-10", "2023-11-25");

    EXPECT_TRUE(user.hasBorrowedBook(301)); // Check that the book is borrowed
    EXPECT_FALSE(user.hasBorrowedBook(302)); // Check that a non-existent book is not borrowed
}
