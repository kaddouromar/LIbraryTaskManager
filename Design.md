***Design Document: Library Task Manager***

 Overview
The **Library Task Manager** is a command-line-based system designed to manage books, users, and library tasks efficiently. It allows administrators to perform actions such as adding, editing, and removing books and users, as well as creating and tracking tasks. This document outlines the key design choices and architecture of the project.

---

 Table of Contents
1. **Features**
2. **Architecture**
3. **Data Models**
4. **Menus and User Interaction**
5. **Sorting and Searching**
6. **Task Management**
7. **Error Handling and Validation**
8. **Future Improvements**

---

 1. Features
- **Book Management:**
  - Add, edit, delete, search, and display books.
  - Sorting books by ID for easy management.
  
- **User Management:**
  - Add, edit, delete, search, and display users.

- **Task Management:**
  - Create tasks for borrowing, returning, or maintaining books.
  - View task history.

- **Sorting and Searching:**
  - Efficient insertion sort for books.
  - Search functionality for books and users using keywords.

---

 2. Architecture\n
The project follows a modular structure with distinct components for:
1. **Global Containers:** Store books, users, and tasks as vectors.
2. **Menus and Interaction:** Functions to navigate and interact with the system.
3. **Data Models:** Encapsulated classes for `Book`, `User`, and `Task`.
4. **Task Management:** Functions for creating and displaying tasks.

 File Structure
- `main.cpp`: Contains the main program loop and menu logic.
- `book.h` and `book.cpp`: Define the `Book` class and related methods.
- `user.h` and `user.cpp`: Define the `User` class and related methods.
- `task.h` and `task.cpp`: Define the `Task` class and related methods.

---

 3. Data Models
 Book
Attributes:
- `int id`
- `std::string title`
- `std::string author`
- `int yearPublished`
- `std::string genre`

Key Methods:
- `getId()`, `setTitle()`, `displayBookInfo()`

### User
Attributes:
- `int id`
- `std::string name`
- `std::string faculty`
- `int age`

Key Methods:
- `getId()`, `setName()`, `displayUserInfo()`

### Task
Attributes:
- `int taskId`
- `TaskType type` (enum)
- `std::string description`
- `int bookId`
- `int userId`

Key Methods:
- `getTaskId()`, `displayTaskInfo()`

---

 4. Menus and User Interaction
- **Main Menu:** Provides access to books, users, and tasks.
- **Submenus:** Contextual menus for specific management tasks.
- **User Input:** Command-line input is used for all interactions.

 Design Principles:
- **Clear Prompts:** Each menu displays instructions for the user.
- **Error Handling:** Users are prompted to retry if invalid input is detected.

---

 5. Sorting and Searching
- **Sorting:** Books are sorted by `id` using insertion sort for efficient management.
- **Searching:** Keyword-based search is implemented for books and users.

 Example:
For books:
- Searches title, author, and genre fields for a keyword.

---

 6. Task Management
- **Types of Tasks:**
  - Borrow Book
  - Return Book
  - Maintenance
  - Book Order
  - Custom

- **Task History:** All created tasks are stored and can be viewed using the `viewTaskHistory` function.

---

 7. Error Handling and Validation
- **Input Validation:** Ensures valid input for IDs, strings, and task types.
- **Error Messages:** Inform users when an ID is not found or input is invalid.
- **Prevent Duplicates:** Duplicate entries for books or users are avoided through validation.

---

 8. Future Improvements
1. **Enhanced Search:**
   - Add filters for more precise searching (e.g., by year or genre).
2. **Improved Sorting:**
   - Allow sorting by attributes other than ID, such as title or author.
3. **Task Management:**
   - Include task status (e.g., pending, completed).
   - Allow task editing.
4. **Data Persistence:**
   - Save and load data from files to retain changes across sessions.
5. **Graphical Interface:**
   - Develop a GUI for more intuitive user interaction.

---
