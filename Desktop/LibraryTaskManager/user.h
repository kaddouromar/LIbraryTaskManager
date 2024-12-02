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
    int NUM_BORROWED_BOOKS=0;
    std::vector<BorrowedBook> borrowedBooks;

    static const int MAX_BOOKS = 5;

public:
    // Constructors
    User();
    User(int userId, const std::string& name, const std::string& faculty, int age);

    // Getters and Setters
    int getUserId() const;
    std::string getName() const;
    std::string getFaculty() const;
    int getAge() const;

    void setName(const std::string& newName);
    void setFaculty(const std::string& newFaculty);
    void setAge(int newAge);

    // Borrow and Return Books
    void borrowBook(int bookId, const std::string& borrowDate, const std::string& dueDate);
    void returnBook(int bookId);

    // View User Info
    void displayUserInfo() const;
    const std::vector<BorrowedBook>& getBorrowedBooks() const;

    // Search Helper
    bool hasBorrowedBook(int bookId) const;
};

#endif // USER_H
