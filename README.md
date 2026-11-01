# cpp-student-record-management-system

A console-based Student Record Management System built with C++ that allows users to add, view, search, update, and delete student records, calculate class averages, and store data using file handling.



\# Student Record Management System



A console-based Student Record Management System developed using \*\*C++\*\*. The application provides a simple and efficient way to manage student information, perform record operations, and calculate academic statistics.



\## Overview



The Student Record Management System is designed to simplify the management of student records through a menu-driven interface. It allows users to perform essential record management operations while demonstrating fundamental and intermediate C++ programming concepts.



Student information is stored in a text file, ensuring that records remain available even after the application is closed.



\## Features



\* \*\*Add Students:\*\* Register new students with their ID, name, course, and marks.

\* \*\*View Records:\*\* Display all registered students.

\* \*\*Search Records:\*\* Find individual students using their unique student ID.

\* \*\*Update Records:\*\* Modify existing student information.

\* \*\*Delete Records:\*\* Remove student records from the system.

\* \*\*Class Average:\*\* Calculate the average marks of all registered students.

\* \*\*Data Persistence:\*\* Automatically save and retrieve student records using file handling.

\* \*\*Duplicate ID Prevention:\*\* Prevent registration of students using an existing ID.



\## Technologies Used



\* \*\*Programming Language:\*\* C++

\* \*\*IDE:\*\* Code::Blocks

\* \*\*Compiler:\*\* GCC

\* \*\*Concepts:\*\* Object-Oriented Programming, Vectors, Functions, File Handling, Searching, and Data Manipulation.



\## Project Structure



```text

cpp-student-record-management-system/

│

├── main.cpp

├── students.txt

├── README.md

└── .gitignore

```



\## Getting Started



\### Prerequisites



To run this project, you need:



\* Code::Blocks IDE or another C++ development environment.

\* GCC compiler.

\* Basic knowledge of compiling and executing C++ programs.



\### Installation



1\. Clone the repository:



```bash

git clone https://github.com/Vance199-source/cpp-student-record-management-system.git

```



2\. Navigate to the project directory:



```bash

cd cpp-student-record-management-system

```



3\. Open `main.cpp` in Code::Blocks.



4\. Build and run the application.



Alternatively, compile using GCC:



```bash

g++ main.cpp -o student\_management

```



Run the executable:



```bash

./student\_management

```



On Windows:



```bash

student\_management.exe

```



\## How It Works



When the application starts, it automatically loads previously saved student records.



Users interact with the system through a menu offering different management operations.



Each operation updates the student records where necessary, and changes are automatically saved to `students.txt`.



\## Learning Objectives



This project demonstrates practical implementation of:



\* Classes and Objects.

\* Object-Oriented Programming principles.

\* Vectors and Iterators.

\* File Input and Output Operations.

\* Functions and Modular Programming.

\* Searching and Record Manipulation.

\* Input Validation and Error Handling.



\## Future Improvements



Potential enhancements include:



\* Graphical User Interface (GUI).

\* Database integration using MySQL or SQLite.

\* Automatic grade classification.

\* Student performance reports.

\* Sorting records by name, marks, or student ID.

\* Exporting student records to CSV.



\## Author



\*\*Evans Ngari\*\*



Information Technology Student | C++ Programming Enthusiast



GitHub: \[Vance199-source](https://github.com/Vance199-source)



\---



\*This project was developed as part of my practical learning journey in C++ programming and software development.\*



