# LibraryTaskManager
A C++ Task manager designed to handle tasks for a library. Things include ordering new books, tracking borrowed and returned books, users, and various other tasks.

***Requirement Specification:***

1) **Book Managment**

   a) Add a new book
   
   b) Edit details of book (Author, Title, Year Published, Genre)

   c) Delete book**
   
   d) Search for book (By Title, Genre, Author)
   
   e) display book info and history of who borrowed it
   
2) **User Managment**

   a) Add a new user (User ID)
   
   b) Edit details of user
   
   c) Delete user
   
   d) Search for user using different criteria
   
   e) view user information and borrowed books
   
3) **Task Managment**

   a) Create tasks for borrowing/returning books
   
   b) Edit tasks
   
   c) Delete tasks when completed
   
   d) history of tasks (task log)
   
   e) if we need any other tasks (maintenence of library, placing orders for books, etc)

***User Stories***

**As a librarian,** I want to be able to add a new book to the system, so that they are available for borrowing.

**As a librarian,** I want to be able to add, manage, and remove users, so that they are able to borrow books.

**As a librarian,** I want to initiate & keep track of borrowing & returning of books

***Non-Functional Requirements:***

   1) ***Performance:***

      Should handle x amount of users and x amount of books without errors
      Efficent searching times (is a time required?)

   2) ***Scalability:***

      Should be able to easily implement new functions 

***The system uses several core components to handle different aspects of library management:***

**Book Management**: A class to manage books, including adding, updating, and searching for books.

**User Management**: A class for managing users (e.g., adding users, updating details).

**Task Management**: A class to manage tasks related to borrowing, returning, and maintaining books.
      


   
