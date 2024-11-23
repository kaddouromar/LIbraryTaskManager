#include "book.h"
#include <gtest/gtest.h>

// Test book creation
TEST(BookTest, CreateBook) {
    Book book(1, "The Great Gatsby", "F. Scott Fitzgerald", 1925, "Fiction");
    EXPECT_EQ(book.getId(), 1);
    EXPECT_EQ(book.getTitle(), "The Great Gatsby");
    EXPECT_EQ(book.getAuthor(), "F. Scott Fitzgerald");
    EXPECT_EQ(book.getYearPublished(), 1925);
    EXPECT_EQ(book.getGenre(), "Fiction");
    EXPECT_TRUE(book.getAvailability());
}

// Test borrowing a book
TEST(BookTest, BorrowBook) {
    Book book(2, "1984", "George Orwell", 1949, "Dystopian");
    book.borrowBook("Alice Johnson", "2024-11-19");
    EXPECT_FALSE(book.getAvailability());

    const auto& history = book.getHistory();
    ASSERT_EQ(history.size(), 1);
    EXPECT_EQ(history[0].borrowerName, "Alice Johnson");
    EXPECT_EQ(history[0].borrowDate, "2024-11-19");
    EXPECT_EQ(history[0].returnDate, "");
}

// Test returning a book
TEST(BookTest, ReturnBook) {
    Book book(3, "To Kill a Mockingbird", "Harper Lee", 1960, "Fiction");
    book.borrowBook("John Doe", "2024-11-19");
    book.returnBook("2024-11-25");
    EXPECT_TRUE(book.getAvailability());

    const auto& history = book.getHistory();
    ASSERT_EQ(history.size(), 1);
    EXPECT_EQ(history[0].returnDate, "2024-11-25");
}
