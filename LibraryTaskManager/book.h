#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <vector>
#include <iostream>

struct BorrowHistory {
    std::string borrowerName;
    std::string borrowDate;
    std::string returnDate;
};

class Book {
private:
    int id;                       // Book ID
    std::string title;            // Book Title
    std::string author;           // Book Author
    int yearPublished;            // Year Published
    std::string genre;            // Book Genre
    bool isAvailable;             // Availability of the book
    std::vector<BorrowHistory> history; // Borrow history

public:
    // Constructors
    Book();
    Book(int id, const std::string& title, const std::string& author, int yearPublished, const std::string& genre);

    // Getters and Setters
    int getId() const;            // Correct getter for ID
    std::string getTitle() const;
    std::string getAuthor() const;
    int getYearPublished() const;
    std::string getGenre() const;
    bool getAvailability() const;

    void setTitle(const std::string& newTitle);
    void setAuthor(const std::string& newAuthor);
    void setYearPublished(int newYear);
    void setGenre(const std::string& newGenre);
    void setAvailability(bool availability);

    // Borrow and return functions
    void borrowBook(const std::string& borrowerName, const std::string& borrowDate);
    void returnBook(const std::string& returnDate);

    // History management
    const std::vector<BorrowHistory>& getHistory() const;

    // Display book info
    void displayBookInfo() const;
};

#endif // BOOK_H
