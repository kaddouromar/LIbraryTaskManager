#include "user.h"
#include <gtest/gtest.h>

// Test Constructor
TEST(UserTest, ConstructorDefault) {
    User defaultUser;
    EXPECT_EQ(defaultUser.getUserId(), 0);
    EXPECT_EQ(defaultUser.getName(), "");
    EXPECT_EQ(defaultUser.getFaculty(), "");
    EXPECT_EQ(defaultUser.getAge(), 0);
}

TEST(UserTest, ConstructorParameterized) {
    User customUser(1, "Alice", "Engineering", 25);
    EXPECT_EQ(customUser.getUserId(), 1);
    EXPECT_EQ(customUser.getName(), "Alice");
    EXPECT_EQ(customUser.getFaculty(), "Engineering");
    EXPECT_EQ(customUser.getAge(), 25);
}

// Test Setters and Getters
TEST(UserTest, SettersAndGetters) {
    User user(2, "Bob", "Science", 30);
    user.setName("Charlie");
    user.setFaculty("Arts");
    user.setAge(35);

    EXPECT_EQ(user.getName(), "Charlie");
    EXPECT_EQ(user.getFaculty(), "Arts");
    EXPECT_EQ(user.getAge(), 35);
}

// Test Borrow and Return Books
TEST(UserTest, BorrowAndReturnBooks) {
    User user(3, "Diana", "Math", 28);

    // Borrow a book
    user.borrowBook(101, "2024-12-01", "2025-01-01");
    EXPECT_TRUE(user.hasBorrowedBook(101));
    EXPECT_EQ(user.getBorrowedBooks().size(), 1);  // Check the size of borrowedBooks vector

    // Borrow another book
    user.borrowBook(102, "2024-12-05", "2025-01-05");
    EXPECT_TRUE(user.hasBorrowedBook(102));
    EXPECT_EQ(user.getBorrowedBooks().size(), 2);  // Check the size of borrowedBooks vector

    // Return a book
    user.returnBook(101);
    EXPECT_FALSE(user.hasBorrowedBook(101));
    EXPECT_EQ(user.getBorrowedBooks().size(), 1);  // Check the size of borrowedBooks vector

    // Return another book
    user.returnBook(102);
    EXPECT_FALSE(user.hasBorrowedBook(102));
    EXPECT_EQ(user.getBorrowedBooks().size(), 0);  // Check the size of borrowedBooks vector
}

// Test Display Info (Output Verification with Manual Check)
TEST(UserTest, DisplayUserInfo) {
    User user(4, "Eve", "Computer Science", 22);
    user.borrowBook(201, "2024-12-01", "2025-01-01");
    user.borrowBook(202, "2024-12-05", "2025-01-05");

    // This test is more for observation than automated checks
    user.displayUserInfo();
    // Check console output manually or adapt displayUserInfo to return a string for better testing
}

// Main function for Google Test
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
