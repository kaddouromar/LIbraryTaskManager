#include <iostream>
#include <vector>
#include "book.h"
#include "user.h"
#include "task.h"
#include <algorithm> // For std::remove_if

// Global Containers
std::vector<Book> books;
std::vector<User> users;
std::vector<Task> tasks;

// Global Task ID Generator
int nextTaskId = 1;

// Utility Functions
void displayMenu()
{
    std::cout << "\n===== Library Task Manager =====\n"
              << "1. Book Management\n"
              << "2. User Management\n"
              << "3. Task Management\n"
              << "4. View Task History\n"
              << "5. Exit\n"
              << "-----------------------------------\n"
              << "Choose an option: ";
}

void bookManagementMenu()
{
    std::cout << "\n--- Book Management ---\n"
              << "1. Add Book\n"
              << "2. Edit Book\n"
              << "3. Delete Book\n"
              << "4. Search for Book\n"
              << "5. Display All Books\n"
              << "6. Back to Main Menu\n"
              << "-----------------------------------\n"
              << "Choose an option: ";
}

void userManagementMenu()
{
    std::cout << "\n--- User Management ---\n"
              << "1. Add User\n"
              << "2. Edit User\n"
              << "3. Delete User\n"
              << "4. Search for User\n"
              << "5. Display All Users\n"
              << "6. Back to Main Menu\n"
              << "-----------------------------------\n"
              << "Choose an option: ";
}

void taskManagementMenu()
{
    std::cout << "\n--- Task Management ---\n"
              << "1. Create Task\n"
              << "2. Edit Task\n"
              << "3. Delete Completed Task\n"
              << "4. View All Tasks\n"
              << "5. Back to Main Menu\n"
              << "-----------------------------------\n"
              << "Choose an option: ";
}

// Book Management Functions
void addBook()
{
    int bookId;
    std::string title, author, genre;
    int yearPublished;

    std::cout << "\nEnter Book Details\n"
              << "-------------------\n";
    std::cout << "Enter Book ID: ";
    std::cin >> bookId;
    std::cin.ignore(); // Ignore newline
    std::cout << "Enter Title: ";
    std::getline(std::cin, title);
    std::cout << "Enter Author: ";
    std::getline(std::cin, author);
    std::cout << "Enter Year Published: ";
    std::cin >> yearPublished;
    std::cin.ignore(); // Ignore newline
    std::cout << "Enter Genre: ";
    std::getline(std::cin, genre);

    books.emplace_back(bookId, title, author, yearPublished, genre);
    std::cout << "\nBook added successfully.\n\n";
}

void editBook()
{
    int bookId;
    std::cout << "Enter Book ID to edit: ";
    std::cin >> bookId;

    for (auto &book : books)
    {
        if (book.getId() == bookId)
        {
            std::string title, author, genre;
            int yearPublished;

            std::cin.ignore(); // Ignore newline
            std::cout << "Enter New Title (leave blank to keep current): ";
            std::getline(std::cin, title);
            if (!title.empty())
                book.setTitle(title);

            std::cout << "Enter New Author (leave blank to keep current): ";
            std::getline(std::cin, author);
            if (!author.empty())
                book.setAuthor(author);

            std::cout << "Enter New Year Published (0 to keep current): ";
            std::cin >> yearPublished;
            if (yearPublished != 0)
                book.setYearPublished(yearPublished);
            std::cin.ignore(); // Ignore newline

            std::cout << "Enter New Genre (leave blank to keep current): ";
            std::getline(std::cin, genre);
            if (!genre.empty())
                book.setGenre(genre);

            std::cout << "\nBook details updated successfully.\n\n";
            return;
        }
    }

    std::cout << "\nBook ID not found.\n\n";
}

void deleteBook()
{
    int bookId;
    std::cout << "Enter Book ID to delete: ";
    std::cin >> bookId;

    auto it = std::remove_if(books.begin(), books.end(),
                             [bookId](const Book &book)
                             { return book.getId() == bookId; });
    if (it != books.end())
    {
        books.erase(it, books.end());
        std::cout << "\nBook deleted successfully.\n\n";
    }
    else
    {
        std::cout << "\nBook ID not found.\n\n";
    }
}

void searchBook()
{
    std::string keyword;
    std::cin.ignore(); // Ignore newline
    std::cout << "Enter search keyword: ";
    std::getline(std::cin, keyword);

    bool found = false;
    for (const auto &book : books)
    {
        if (book.getTitle().find(keyword) != std::string::npos ||
            book.getAuthor().find(keyword) != std::string::npos ||
            book.getGenre().find(keyword) != std::string::npos)
        {
            book.displayBookInfo();
            found = true;
        }
    }
    if (!found)
    {
        std::cout << "\nNo books found with the keyword: " << keyword << "\n\n";
    }
}

// User Management Functions
void addUser()
{
    int userId, age;
    std::string name, faculty;

    std::cout << "\nEnter User Details\n"
              << "-------------------\n";
    std::cout << "Enter User ID: ";
    std::cin >> userId;
    std::cin.ignore(); // Ignore newline
    std::cout << "Enter Name: ";
    std::getline(std::cin, name);
    std::cout << "Enter Faculty: ";
    std::getline(std::cin, faculty);
    std::cout << "Enter Age: ";
    std::cin >> age;

    users.emplace_back(userId, name, faculty, age);
    std::cout << "\nUser added successfully.\n\n";
}

// Task Management Functions
void createTask()
{
    int typeChoice, bookId = 0, userId = 0;
    std::string description;

    std::cout << "\nTask Types:\n"
              << "-------------------\n"
              << "1. Borrow Book\n"
              << "2. Return Book\n"
              << "3. Maintenance\n"
              << "4. Book Order\n"
              << "5. Custom\n"
              << "Choose task type: ";
    std::cin >> typeChoice;
    std::cin.ignore(); // Ignore newline

    TaskType type = static_cast<TaskType>(typeChoice - 1);

    if (type == TaskType::BorrowBook || type == TaskType::ReturnBook)
    {
        std::cout << "Enter Book ID: ";
        std::cin >> bookId;
        std::cout << "Enter User ID: ";
        std::cin >> userId;
    }

    std::cin.ignore(); // Ignore newline
    std::cout << "Enter Task Description: ";
    std::getline(std::cin, description);

    tasks.emplace_back(nextTaskId++, type, description, bookId, userId);
    std::cout << "\nTask created successfully.\n\n";
}

void viewTaskHistory()
{
    if (tasks.empty())
    {
        std::cout << "\nNo tasks in history.\n\n";
    }
    else
    {
        for (const auto &task : tasks)
        {
            task.displayTaskInfo();
            std::cout << "-------------------\n";
        }
    }
}

// Main Function
int main()
{
    int choice;

    while (true)
    {
        displayMenu();
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            bookManagementMenu();
            std::cin >> choice;
            switch (choice)
            {
            case 1:
                addBook();
                break;
            case 2:
                editBook();
                break;
            case 3:
                deleteBook();
                break;
            case 4:
                searchBook();
                break;
            case 5:
                for (const auto &book : books)
                    book.displayBookInfo();
                break;
            case 6:
                break;
            default:
                std::cout << "\nInvalid option. Please try again.\n\n";
            }
            break;

        case 2:
            userManagementMenu();
            std::cin >> choice;
            switch (choice)
            {
            case 1:
                addUser();
                break;
            case 6:
                break;
            default:
                std::cout << "\nInvalid option. Please try again.\n\n";
            }
            break;

        case 3:
            taskManagementMenu();
            std::cin >> choice;
            switch (choice)
            {
            case 1:
                createTask();
                break;
            case 4:
                viewTaskHistory();
                break;
            case 5:
                break;
            default:
                std::cout << "\nInvalid option. Please try again.\n\n";
            }
            break;

        case 4:
            viewTaskHistory();
            break;

        case 5:
            std::cout << "\nExiting program. Goodbye!\n";
            return 0;

        default:
            std::cout << "\nInvalid option. Please try again.\n\n";
        }
    }
}
