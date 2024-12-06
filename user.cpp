#include "user.h"
#include <iostream>
#include <ctime>

// Initialize static variable for max borrowed books
int User::NUM_BORROWED_BOOKS = 0;  // This tracks the current number of borrowed books

// Constructors
User::User() : userId(0), name(""), faculty(""), age(0) {}

User::User(int userId, const std::string& name, const std::string& faculty, int age)
    : userId(userId), name(name), faculty(faculty), age(age) {}

// Getters
int User::getUserId() const {
    return userId;
}

std::string User::getName() const {
    return name;
}

std::string User::getFaculty() const {
    return faculty;
}

int User::getAge() const {
    return age;
}

// Setters
void User::setName(const std::string& newName) {
    name = newName;
}

void User::setFaculty(const std::string& newFaculty) {
    faculty = newFaculty;
}

void User::setAge(int newAge) {
    age = newAge;
}

// Borrow and Return Books
void User::borrowBook(int bookId, const std::string& borrowDate, const std::string& dueDate) {
    if (NUM_BORROWED_BOOKS >= MAX_BOOKS) {
        std::cout << "You have reached the maximum number of borrowed books." << std::endl;
    } else {
        BorrowedBook newBorrow = {bookId, borrowDate, dueDate};
        borrowedBooks.push_back(newBorrow);
        NUM_BORROWED_BOOKS++;
        std::cout << "Book ID " << bookId << " has been borrowed." << std::endl;
    }
}

void User::returnBook(int bookId) {
    for (auto it = borrowedBooks.begin(); it != borrowedBooks.end(); ++it) {
        if (it->bookId == bookId) {
            borrowedBooks.erase(it);
            NUM_BORROWED_BOOKS--;
            std::cout << "Book ID " << bookId << " has been returned." << std::endl;
            return;
        }
    }
    std::cerr << "Book ID " << bookId << " not found in borrowed books.\n";
}

// View User Info
void User::displayUserInfo() const {
    std::cout << "User ID: " << userId << "\n"
              << "Name: " << name << "\n"
              << "Faculty: " << faculty << "\n"
              << "Age: " << age << "\n"
              << "Borrowed Books:\n";

    if (borrowedBooks.empty()) {
        std::cout << "  No books currently borrowed.\n";
    } else {
        for (const auto& book : borrowedBooks) {
            std::cout << "  Book ID: " << book.bookId
                      << ", Borrowed on: " << book.borrowDate
                      << ", Due on: " << book.dueDate << "\n";
        }
    }
}

// Search Helper
bool User::hasBorrowedBook(int bookId) const {
    for (const auto& book : borrowedBooks) {
        if (book.bookId == bookId) {
            return true;
        }
    }
    return false;
}

const std::vector<BorrowedBook>& User::getBorrowedBooks() const {
    return borrowedBooks;
}
