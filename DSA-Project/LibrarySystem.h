#pragma once
#include "LinkedList.h"
#include "BST.h"
#include "Stack.h"
#include "PriorityQueue.h"
using namespace std;

class LibrarySystem {
private:
    LinkedList    bookList;
    BST           bst;
    Stack         sessionHistory;
    PriorityQueue viewPQ;
    PriorityQueue ratingPQ;

    void printBookDetails(const Book& bk) const;
    void offerRating(Book* bk);
    void recordView(Book* bk);

public:
    LibrarySystem();
    bool loadFromFile();
    void saveToFile() const;
    void addBook();
    void searchByID();
    void searchByTitle();
    void searchByAuthor();
    void searchByGenre();
    void showSessionHistory() const;
    void showAllTimeHistory() const;
    void showMostViewed();
    void showTopRated();
    void showAllBooks() const;
    void run();
};
