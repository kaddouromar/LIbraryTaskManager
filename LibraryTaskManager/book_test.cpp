#include "book.h"
#include <gtest/gtest.h>

// Test Default Constructor
TEST(BookTest, DefaultConstructor) {
    Book book;

    EXPECT_EQ(book.getId(), 0);
    EXPECT_EQ(book.getTitle(), "");
    EXPECT_EQ(book.getAuthor(), "");
    EXPECT_EQ(book.getYearPublished(), 0);
    EXPECT_EQ(book.getGenre(), "");
    EXPECT_TRUE(book.getAvailability());
}

// Test Parameterized Constructor
TEST(BookTest, ParameterizedConstructor) {
    Book book(1, "The Great Gatsby", "F. Scott Fitzgerald", 1925, "Fiction");

    EXPECT_EQ(book.getId(), 1);
    EXPECT_EQ(book.getTitle(), "The Great Gatsby");
    EXPECT_EQ(book.getAuthor(), "F. Scott Fitzgerald");
    EXPECT_EQ(book.getYearPublished(), 1925);
    EXPECT_EQ(book.getGenre(), "Fiction");
    EXPECT_TRUE(book.getAvailability());
}

// Test Setters and Getters
TEST(BookTest, SettersAndGetters) {
    Book book;

    book.setTitle("1984");
    book.setAuthor("George Orwell");
    book.setYearPublished(1949);
    book.setGenre("Dystopian");
    book.setAvailability(false);

    EXPECT_EQ(book.getTitle(), "1984");
    EXPECT_EQ(book.getAuthor(), "George Orwell");
    EXPECT_EQ(book.getYearPublished(), 1949);
    EXPECT_EQ(book.getGenre(), "Dystopian");
    EXPECT_FALSE(book.getAvailability());
}

// Test Borrow and Return Book
TEST(BookTest, BorrowAndReturnBook) {
    Book book(2, "To Kill a Mockingbird", "Harper Lee", 1960, "Fiction");

    // Borrow book
    book.borrowBook("John Doe", "2024-12-01");
    EXPECT_FALSE(book.getAvailability());

    // Return book
    book.returnBook("2024-12-10");
    EXPECT_TRUE(book.getAvailability());
}

// Test Borrow Book Failure
TEST(BookTest, BorrowBookFailure) {
    Book book(3, "Pride and Prejudice", "Jane Austen", 1813, "Romance");

    // Borrow book
    book.borrowBook("Jane Doe", "2024-12-01");
    EXPECT_FALSE(book.getAvailability());

    // Attempt to borrow again
    testing::internal::CaptureStderr();
    book.borrowBook("John Smith", "2024-12-05");
    std::string errorOutput = testing::internal::GetCapturedStderr();

    EXPECT_FALSE(book.getAvailability());
    EXPECT_EQ(errorOutput, "\nBook is already borrowed.\n");
}

// Test Return Book Failure
TEST(BookTest, ReturnBookFailure) {
    Book book(4, "The Catcher in the Rye", "J.D. Salinger", 1951, "Fiction");

    // Attempt to return without borrowing
    testing::internal::CaptureStderr();
    book.returnBook("2024-12-10");
    std::string errorOutput = testing::internal::GetCapturedStderr();

    EXPECT_TRUE(book.getAvailability());
    EXPECT_EQ(errorOutput, "\nBook is already available.\n");
}

// Test Borrow History
TEST(BookTest, BorrowHistory) {
    Book book(5, "Moby-Dick", "Herman Melville", 1851, "Adventure");

    book.borrowBook("Alice", "2024-12-01");
    book.returnBook("2024-12-10");
    book.borrowBook("Bob", "2024-12-15");

    const auto& history = book.getHistory();
    ASSERT_EQ(history.size(), 2);

    EXPECT_EQ(history[0].borrowerName, "Alice");
    EXPECT_EQ(history[0].borrowDate, "2024-12-01");
    EXPECT_EQ(history[0].returnDate, "2024-12-10");

    EXPECT_EQ(history[1].borrowerName, "Bob");
    EXPECT_EQ(history[1].borrowDate, "2024-12-15");
    EXPECT_EQ(history[1].returnDate, "");
}
