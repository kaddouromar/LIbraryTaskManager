#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include <iostream>

struct BorrowedBook {
    int bookId;
    std::string borrowDate;
    std::string dueDate;
};

class User {
private:
    int userId;
    std::string name;
    std::string faculty;
    int age;
    std::vector<BorrowedBook> borrowedBooks;

    static const int MAX_BOOKS = 5; // Set max limit of books
    static int NUM_BORROWED_BOOKS; // Keep track of borrowed books (you can replace this with other tracking methods)

public:
    // Constructors
    User();
    User(int userId, const std::string& name, const std::string& faculty, int age);

    // Getters
    int getUserId() const;
    std::string getName() const;
    std::string getFaculty() const;
    int getAge() const;

    // Setters
    void setName(const std::string& newName);
    void setFaculty(const std::string& newFaculty);
    void setAge(int newAge);

    // Borrow and Return Books
    void borrowBook(int bookId, const std::string& borrowDate, const std::string& dueDate);
    void returnBook(int bookId);

    // View User Info
    void displayUserInfo() const;

    // Helper
    bool hasBorrowedBook(int bookId) const;
    const std::vector<BorrowedBook>& getBorrowedBooks() const;
};

#endif
