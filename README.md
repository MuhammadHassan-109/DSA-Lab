# Library Management & Recommendation System

## Overview

The Library Management & Recommendation System is a console-based application developed in C++. The system allows users to manage a collection of books, search for books using different criteria, maintain viewing history, rate books, and receive recommendations based on popularity and ratings.

The project demonstrates the practical implementation of Data Structures and File Handling concepts, including Linked Lists, Binary Search Trees (BST), Stacks, Priority Queues (Max Heaps), and text file storage.

---

## Features

* Add new books to the library
* Search books by:

  * ID
  * Title
  * Author
  * Genre
* View detailed book information
* Rate books (1–5 stars)
* Track current session viewing history
* Store permanent viewing history in a file
* Display Top 5 Most Viewed Books
* Display Top 5 Highest Rated Books
* Persistent data storage using text files

---

## Data Structures Used

### Linked List

Used to store and manage all book records in memory.

### Binary Search Tree (BST)

Used for efficient searching of books by their unique ID.

### Stack

Used to maintain the current session's viewing history.

### Priority Queue (Max Heap)

Used to generate recommendations:

* Top 5 Most Viewed Books
* Top 5 Highest Rated Books

---

## File Handling

### library.txt

Stores all book records including:

* Book ID
* Title
* Author
* Genre
* View Count
* Total Rating
* Rating Count

### history.txt

Stores permanent viewing history of books accessed by users.

---

## Technologies Used

* C++
* Object-Oriented Programming (OOP)
* File Handling
* Linked Lists
* Binary Search Trees (BST)
* Stack
* Priority Queue (Max Heap)

---

## Project Structure

```text
Library Management & Recommendation System
│
├── main.cpp
├── library.txt
├── history.txt
└── README.md
```

---

## How to Run

1. Open the project in any C++ IDE (Code::Blocks, Dev-C++, Visual Studio, VS Code, etc.).
2. Ensure `library.txt` is present in the same directory as the source file.
3. Compile and run the program.
4. Use the menu options to interact with the system.

---

## Demo Video

https://drive.google.com/file/d/1VzuEw8dNwcBaGWdlM_alzqq5SD-y8UWB/view?usp=sharing
---

## Contributors

* Humayun — Priority Queue (Max Heap) Implementation & Recommendation System
* Hassan 2 — Binary Search Tree (BST)
* Sharjel Shakeel 3 — Stack Implementation

---

## Academic Purpose

This project was developed as part of a Data Structures course to demonstrate the implementation and integration of multiple data structures in a real-world application.
