The **Library Task Manager** is a command-line-based system designed to efficiently manage books, users, and library-related tasks. This document provides an overview of the project, including features, architecture, and usage guidelines.

***Getting Started***

To download this project: Do either of the following:
A) Download the ready zip file licated in the repository, or
B) Clone the repository:
   **Prerequisites**
     
      i) A C++ compiler (e.g., GCC, Clang, or MSVC).
      
      ii) A terminal or command prompt to run the program.
      
   a) Clone the Repository
   
      git clone <repository-url>
   
   b) Navigate to the project directory:
   
      cd library-task-manager
   
   c) Compile the program:
   
      g++ main.cpp book.cpp user.cpp task.cpp -o LibraryTaskManager
   
   d) Run the Program:
   
      ./LibraryTaskManager
      
***File Structure***

   main.cpp: Contains the main program loop and menu logic.
   
   book.h & **book.cpp**: Define the Book class and its methods.
   
   user.h & **user.cpp**: Define the User class and its methods.
   
   task.h & **task.cpp**: Define the Task class and its methods.

***Error Handling***

   Input Validation: Ensures valid input for IDs, strings, and task types.
   
   Error Messages: Inform users when an ID is not found or input is invalid.
   
   Duplicate Prevention: Avoid duplicate entries for books or users.
