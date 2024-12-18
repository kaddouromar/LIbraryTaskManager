#include "book.h"

// Default Constructor
Book::Book() : id(0), title(""), author(""), yearPublished(0), genre(""), isAvailable(true) {}

// Parameterized Constructor
Book::Book(int id, const std::string& title, const std::string& author, int yearPublished, const std::string& genre)
    : id(id), title(title), author(author), yearPublished(yearPublished), genre(genre), isAvailable(true) {}

// Getters and Setters
int Book::getId() const {
    return id;  // Return the book ID
}

std::string Book::getTitle() const {
    return title;
}

std::string Book::getAuthor() const {
    return author;
}

int Book::getYearPublished() const {
    return yearPublished;
}

std::string Book::getGenre() const {
    return genre;
}

bool Book::getAvailability() const {
    return isAvailable;
}

void Book::setTitle(const std::string& newTitle) {
    title = newTitle;
}

void Book::setAuthor(const std::string& newAuthor) {
    author = newAuthor;
}

void Book::setYearPublished(int newYear) {
    yearPublished = newYear;
}

void Book::setGenre(const std::string& newGenre) {
    genre = newGenre;
}

void Book::setAvailability(bool availability) {
    isAvailable = availability;
}

// Borrow and return
void Book::borrowBook(const std::string& borrowerName, const std::string& borrowDate) {
    if (!isAvailable) {
        std::cerr << "\nBook is already borrowed.\n";
        return;
    }
    BorrowHistory record = {borrowerName, borrowDate, ""};
    history.push_back(record);
    isAvailable = false;
}

void Book::returnBook(const std::string& returnDate) {
    if (isAvailable) {
        std::cerr << "\nBook is already available.\n";
        return;
    }

    // Update the borrow history with the return date
    if (!history.empty()) {
        history.back().returnDate = returnDate;  // Set the return date for the last borrow record
    }

    // Mark the book as available
    isAvailable = true;
    std::cout << "Book has been returned successfully.\n";
}


// History
const std::vector<BorrowHistory>& Book::getHistory() const {
    return history;
}

// Display book info
void Book::displayBookInfo() const {
    std::cout << "ID: " << id << "\n"
              << "Title: " << title << "\n"
              << "Author: " << author << "\n"
              << "Year Published: " << yearPublished << "\n"
              << "Genre: " << genre << "\n"
              << "Availability: " << (isAvailable ? "Available" : "Borrowed") << "\n";

    if (history.empty()) {
        std::cout << "Borrow History:\n";
        for (const auto& record : history) {
            std::cout << "  Borrower: " << record.borrowerName
                      << ", Borrowed on: " << record.borrowDate
                      << ", Returned on: " << (record.returnDate.empty() ? "Not yet returned" : record.returnDate) << "\n";
        }
    } else {
        std::cout << "\nNo borrow history available.\n";
    }
}


