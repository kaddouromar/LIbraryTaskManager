#include <iostream>
#include <vector>
#include "book.h"
#include "user.h"
#include "task.h"
#include <algorithm> // For std::remove_if
#include <limits>    // For std::numeric_limits

// Global Containers
std::vector<Book> books;
std::vector<User> users;
std::vector<Task> tasks;

// Global Task ID Generator
int nextTaskId = 1;

// Utility Functions
void displayMenu() {
    std::cout << "\n===== Library Task Manager =====\n"
              << "1. Book Management\n"
              << "2. User Management\n"
              << "3. Task Management\n"
              << "4. View Task History\n"
              << "5. Exit\n"
              << "Choose an option: ";
}

void bookManagementMenu() {
    std::cout << "\n--- Book Management ---\n"
              << "1. Add Book\n"
              << "2. Edit Book\n"
              << "3. Delete Book\n"
              << "4. Search for Book\n"
              << "5. Display All Books\n"
              << "6. Back to Main Menu\n"
              << "Choose an option: ";
}

void userManagementMenu() {
    std::cout << "\n--- User Management ---\n"
              << "1. Add User\n"
              << "2. Edit User\n"
              << "3. Delete User\n"
              << "4. Search for User\n"
              << "5. Display All Users\n"
              << "6. Back to Main Menu\n"
              << "Choose an option: ";
}

void taskManagementMenu() {
    std::cout << "\n--- Task Management ---\n"
              << "1. Create Task\n"
              << "2. Edit Task\n"
              << "3. Delete Completed Task\n"
              << "4. View All Tasks\n"
              << "5. Back to Main Menu\n"
              << "Choose an option: ";
}

// Function to validate integer input
int getValidInput() {
    int value;
    while (true) {
        std::cin >> value;
        if (std::cin.fail()) {
            std::cin.clear();  // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Discard invalid input
            std::cout << "Invalid input. Please enter a number: ";
        } else {
            return value;
        }
    }
}

// Book Management Functions
void addBook() {
    int bookId;
    std::string title, author, genre;
    int yearPublished;

    std::cout << "Enter Book ID: ";
    bookId = getValidInput();
    std::cin.ignore();
    std::cout << "Enter Title: ";
    std::getline(std::cin, title);
    std::cout << "Enter Author: ";
    std::getline(std::cin, author);
    std::cout << "Enter Year Published: ";
    yearPublished = getValidInput();
    std::cin.ignore();
    std::cout << "Enter Genre: ";
    std::getline(std::cin, genre);

    books.emplace_back(bookId, title, author, yearPublished, genre);
    std::cout << "Book added successfully.\n";
}

void editBook() {
    int bookId;
    std::cout << "Enter Book ID to edit: ";
    bookId = getValidInput();

    for (auto& book : books) {
        if (book.getId() == bookId) {
            std::string title, author, genre;
            int yearPublished;

            std::cin.ignore();
            std::cout << "Enter New Title (leave blank to keep current): ";
            std::getline(std::cin, title);
            if (!title.empty()) book.setTitle(title);

            std::cout << "Enter New Author (leave blank to keep current): ";
            std::getline(std::cin, author);
            if (!author.empty()) book.setAuthor(author);

            std::cout << "Enter New Year Published (0 to keep current): ";
            yearPublished = getValidInput();
            if (yearPublished != 0) book.setYearPublished(yearPublished);

            std::cin.ignore();
            std::cout << "Enter New Genre (leave blank to keep current): ";
            std::getline(std::cin, genre);
            if (!genre.empty()) book.setGenre(genre);

            std::cout << "Book details updated successfully.\n";
            return;
        }
    }

    std::cout << "Book ID not found.\n";
}

void deleteBook() {
    int bookId;
    std::cout << "Enter Book ID to delete: ";
    bookId = getValidInput();

    auto it = std::remove_if(books.begin(), books.end(),
                             [bookId](const Book& book) { return book.getId() == bookId; });
    if (it != books.end()) {
        books.erase(it, books.end());
        std::cout << "Book deleted successfully.\n";
    } else {
        std::cout << "Book ID not found.\n";
    }
}

void searchBook() {
    std::string keyword;
    std::cin.ignore();
    std::cout << "Enter search keyword (Name of author, Title or Genre): ";
    std::getline(std::cin, keyword);

    for (const auto& book : books) {
        if (book.getTitle().find(keyword) != std::string::npos ||
            book.getAuthor().find(keyword) != std::string::npos ||
            book.getGenre().find(keyword) != std::string::npos) {
            book.displayBookInfo();
        }
    }
}

// User Management Functions
void addUser() {
    int userId, age;
    std::string name, faculty;

    std::cout << "Enter User ID: ";
    userId = getValidInput();
    std::cin.ignore();
    std::cout << "Enter Name: ";
    std::getline(std::cin, name);
    std::cout << "Enter Faculty: ";
    std::getline(std::cin, faculty);
    std::cout << "Enter Age: ";
    age = getValidInput();

    users.emplace_back(userId, name, faculty, age);
    std::cout << "User added successfully.\n";
}

void editUser() {
    int userId;
    std::cout << "Enter User ID to edit: ";
    userId = getValidInput();

    for (auto& user : users) {
        if (user.getUserId() == userId) {
            std::string name, faculty;
            int age;

            std::cin.ignore();
            std::cout << "Enter New Name (leave blank to keep current): ";
            std::getline(std::cin, name);
            if (!name.empty()) user.setName(name);

            std::cout << "Enter New Faculty (leave blank to keep current): ";
            std::getline(std::cin, faculty);
            if (!faculty.empty()) user.setFaculty(faculty);

            std::cout << "Enter New Age (0 to keep current): ";
            age = getValidInput();
            if (age != 0) user.setAge(age);

            std::cout << "User details updated successfully.\n";
            return;
        }
    }
    std::cout << "User ID not found.\n";
}

void deleteUser() {
    int userId;
    std::cout << "Enter User ID to delete: ";
    userId = getValidInput();

    auto it = std::remove_if(users.begin(), users.end(),
                             [userId](const User& user) { return user.getUserId() == userId; });
    if (it != users.end()) {
        users.erase(it, users.end());
        std::cout << "User deleted successfully.\n";
    } else {
        std::cout << "User ID not found.\n";
    }
}

void searchUser() {
    int userId;
    std::cout << "Enter User ID to search: ";
    userId = getValidInput();

    for (const auto& user : users) {
        if (user.getUserId() == userId) {
            user.displayUserInfo();
            return;
        }
    }
    std::cout << "User ID not found.\n";
}

void displayAllUsers() {
    if (users.empty()) {
        std::cout << "No users found.\n";
    } else {
        for (const auto& user : users) {
            user.displayUserInfo();
            std::cout << "-------------------\n";
        }
    }
}

// Task Management Functions
void createTask() {
    int typeChoice, bookId = 0, userId = 0;
    std::string description;

    std::cout << "Task Types:\n"
              << "1. Borrow Book\n"
              << "2. Return Book\n"
              << "3. Maintenance\n"
              << "4. Book Order\n"
              << "5. Custom\n"
              << "Choose task type: ";
    typeChoice = getValidInput();
    std::cin.ignore();

    TaskType type = static_cast<TaskType>(typeChoice - 1);

    if (type == TaskType::BorrowBook || type == TaskType::ReturnBook) {
        std::cout << "Enter Book ID: ";
        bookId = getValidInput();
        bool validBook = std::any_of(books.begin(), books.end(), [bookId](const Book& book) { return book.getId() == bookId; });
        if (!validBook) {
            std::cout << "Invalid Book ID.\n";
            return;
        }

        std::cout << "Enter User ID: ";
        userId = getValidInput();
        bool validUser = std::any_of(users.begin(), users.end(), [userId](const User& user) { return user.getUserId() == userId; });
        if (!validUser) {
            std::cout << "Invalid User ID.\n";
            return;
        }

        // Borrow or Return Book Task Logic
        if (type == TaskType::BorrowBook) {
            std::string borrowDate, dueDate;
            std::cout << "Enter Borrow Date (YYYY-MM-DD): ";
            std::getline(std::cin, borrowDate);
            std::cout << "Enter Due Date (YYYY-MM-DD): ";
            std::getline(std::cin, dueDate);

            // Find the user and borrow the book
            for (auto& user : users) {
                if (user.getUserId() == userId) {
                    user.borrowBook(bookId, borrowDate, dueDate);
                    break;
                }
            }
            std::cout << "Book borrowed successfully.\n";
        }

        else if (type == TaskType::ReturnBook) {
            // Find the user and return the book
            for (auto& user : users) {
                if (user.getUserId() == userId) {
                    user.returnBook(bookId);
                    std::cout << "Book returned successfully.\n";
                    break;
                }
            }
        }
    }

    std::cout << "Enter Task Description: ";
    std::getline(std::cin, description);

    Task newTask(nextTaskId++, type, description, bookId, userId);
    tasks.push_back(newTask);

    std::cout << "Task created successfully.\n";
}

void editTask() {
    int taskId;
    std::cout << "Enter Task ID to edit: ";
    taskId = getValidInput();

    for (auto& task : tasks) {
        if (task.getTaskId() == taskId) {
            std::string description;
            std::cout << "Enter new task description: ";
            std::cin.ignore();
            std::getline(std::cin, description);
            task.setDescription(description);
            std::cout << "Task description updated successfully.\n";
            return;
        }
    }
    std::cout << "Task ID not found.\n";
}

void deleteCompletedTask() {
    int taskId;
    std::cout << "Enter Task ID to delete: ";
    taskId = getValidInput();

    auto it = std::remove_if(tasks.begin(), tasks.end(),
                             [taskId](const Task& task) { return task.getTaskId() == taskId && task.getStatus() == TaskStatus::Completed; });
    if (it != tasks.end()) {
        tasks.erase(it, tasks.end());
        std::cout << "Task deleted successfully.\n";
    } else {
        std::cout << "No completed task found with the given ID.\n";
    }
}

void viewAllTasks() {
    if (tasks.empty()) {
        std::cout << "No tasks available.\n";
    } else {
        for (const auto& task : tasks) {
            task.displayTaskInfo();
        }
    }
}

int main() {
    bool running = true;
    while (running) {
        displayMenu();
        int choice = getValidInput();

        switch (choice) {
        case 1: {
            bookManagementMenu();
            int bookChoice = getValidInput();  // Declare the variable here, within the case block
            switch (bookChoice) {
            case 1: addBook(); break;
            case 2: editBook(); break;
            case 3: deleteBook(); break;
            case 4: searchBook(); break;
            case 5:
                for (const auto& book : books) {
                    book.displayBookInfo();
                    std::cout << "-------------------\n";
                }
                break;
            case 6: break;
            default:
                std::cout << "Invalid option.\n";
            }
            break;
        }
        case 2: {
            userManagementMenu();
            int userChoice = getValidInput();  // Declare the variable here, within the case block
            switch (userChoice) {
            case 1: addUser(); break;
            case 2: editUser(); break;
            case 3: deleteUser(); break;
            case 4: searchUser(); break;
            case 5: displayAllUsers(); break;
            case 6: break;
            default:
                std::cout << "Invalid option.\n";
            }
            break;
        }
        case 3: {
            taskManagementMenu();
            int taskChoice = getValidInput();  // Declare the variable here, within the case block
            switch (taskChoice) {
            case 1: createTask(); break;
            case 2: editTask(); break;
            case 3: deleteCompletedTask(); break;
            case 4: viewAllTasks(); break;
            case 5: break;
            default:
                std::cout << "Invalid option.\n";
            }
            break;
        }
        case 4: {
            viewAllTasks();  // This doesn't require a sub-menu so we directly call the function
            break;
        }
        case 5:
            running = false;
            std::cout << "Exiting the program.\n";
            break;
        default:
            std::cout << "Invalid option.\n";
        }
    }
    return 0;
}
