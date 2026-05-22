#include "LibrarySystem.h"
#include "FileHandler.h"
#include <iostream>
#include <iomanip>
using namespace std;

LibrarySystem::LibrarySystem()
    : viewPQ(200), ratingPQ(200)
{
}

bool LibrarySystem::loadFromFile()
{
    bookList.clear();
    bst.clear();

    int n = FileHandler::loadBooks(bookList, bst);
    if (n < 0)
    {
        cout << "  WARNING: Could not load \"" << DB_FILE << "\".\n"
            << "  Make sure the file is in the same folder as the program.\n";
        return false;
    }
    cout << "  " << n << " book(s) loaded from " << DB_FILE << ".\n";
    return true;
}

void LibrarySystem::saveToFile() const
{
    if (FileHandler::saveBooks(bookList))
        cout << "  Database saved to " << DB_FILE << ".\n";
}


void LibrarySystem::printBookDetails(const Book& bk) const
{
    float avg = (bk.ratingCount > 0)
        ? bk.totalRating / bk.ratingCount
        : 0.0f;

    cout << "\n  == Book Details ==================================\n";
    cout << "  |  Title    : " << bk.title << "\n";
    cout << "  |  Author   : " << bk.author << "\n";
    cout << "  |  Genre    : " << bk.genre << "\n";
    cout << "  |  Views    : " << bk.viewCount << "\n";
    cout << "  |  Rating   : ";
    if (bk.ratingCount > 0)
        cout << fixed << setprecision(2) << avg
        << "  (" << bk.ratingCount << " rating(s))\n";
    else
        cout << "Not yet rated\n";
    cout << "  |_________________________________________________\n";
}

void LibrarySystem::offerRating(Book* bk)
{
    char ch;
    cout << "\n  Would you like to rate this book? (y/n): ";
    cin >> ch;

    if (ch == 'y' || ch == 'Y')
    {
        int r = 0;
        cout << "  Enter rating (1-5): ";
        cin >> r;
        if (r >= 1 && r <= 5)
        {
            bk->totalRating += r;
            bk->ratingCount++;
            cout << "  Rating saved. Thank you!\n";
            saveToFile();
        }
        else
            cout << "  Invalid rating. Must be 1-5.\n";
    }
}

void LibrarySystem::recordView(Book* bk)
{
    bk->viewCount++;
    sessionHistory.push(bk->id);
    FileHandler::appendHistory(bk->id, bk->title);
    saveToFile();
}


void LibrarySystem::addBook()
{
    Book b;
    b.viewCount = 0;
    b.totalRating = 0.0f;
    b.ratingCount = 0;

    cout << "\n  === Add New Book ===\n";
    cout << "  Enter Book ID   : "; cin >> b.id;

    if (bst.search(b.id))
    {
        cout << "  A book with ID " << b.id << " already exists.\n";
        return;
    }

    cin.ignore();
    cout << "  Enter Title     : "; getline(cin, b.title);
    cout << "  Enter Author    : "; getline(cin, b.author);
    cout << "  Enter Genre     : "; getline(cin, b.genre);

    bookList.addBook(b);
    bst.insert(b.id);
    saveToFile();

    cout << "  \"" << b.title << "\" added and saved to database.\n";
}

void LibrarySystem::searchByID()
{
    int id;
    cout << "\n  Enter Book ID: ";
    cin >> id;

    if (!bst.search(id))
    {
        cout << "  No book found with ID " << id << ".\n";
        return;
    }

    Book* bk = bookList.findByID(id);
    if (!bk) { cout << "  Internal error: book missing from list.\n"; return; }

    recordView(bk);
    printBookDetails(*bk);
    offerRating(bk);
}

void LibrarySystem::searchByTitle()
{
    string title;
    cin.ignore();
    cout << "\n  Enter title: ";
    getline(cin, title);

    ListNode* cur = bookList.getHead();
    bool      found = false;

    while (cur)
    {
        if (cur->data.title == title)
        {
            recordView(&cur->data);
            printBookDetails(cur->data);
            offerRating(&cur->data);
            found = true;
            break;
        }
        cur = cur->next;
    }

    if (!found)
        cout << "  No book found with title \"" << title << "\".\n";
}

void LibrarySystem::searchByAuthor()
{
    string author;
    cin.ignore();
    cout << "\n  Enter author name: ";
    getline(cin, author);

    ListNode* cur = bookList.getHead();
    bool      found = false;

    cout << "\n  Books by \"" << author << "\":\n"
        << "  " << string(44, '-') << "\n";

    while (cur)
    {
        if (cur->data.author == author)
        {
            cout << "  ID: " << cur->data.id
                << "  |  " << cur->data.title << "\n";
            found = true;
        }
        cur = cur->next;
    }

    if (!found) { cout << "  No books found by that author.\n"; return; }

    int id;
    cout << "\n  Enter Book ID to view details (0 to skip): ";
    cin >> id;
    if (id == 0) return;

    Book* bk = bookList.findByID(id);
    if (bk && bk->author == author)
    {
        recordView(bk);
        printBookDetails(*bk);
        offerRating(bk);
    }
    else
        cout << "  Invalid ID or ID does not belong to that author.\n";
}

void LibrarySystem::searchByGenre()
{
    cout << "\n  Genres: Mystery | Fantasy | Adventure | Comedy\n"
        << "          Romance | Historical | Drama | Classic\n"
        << "\n  Enter genre: ";

    string genre;
    cin.ignore();
    getline(cin, genre);

    ListNode* cur = bookList.getHead();
    bool      found = false;

    cout << "\n  Books in genre \"" << genre << "\":\n"
        << "  " << string(50, '-') << "\n";

    while (cur)
    {
        if (cur->data.genre == genre)
        {
            cout << "  ID: " << cur->data.id
                << "  |  " << cur->data.title
                << "  |  " << cur->data.author << "\n";
            found = true;
        }
        cur = cur->next;
    }

    if (!found) { cout << "  No books found in genre \"" << genre << "\".\n"; return; }

    int id;
    cout << "\n  Enter Book ID to view details (0 to skip): ";
    cin >> id;
    if (id == 0) return;

    Book* bk = bookList.findByID(id);
    if (bk && bk->genre == genre)
    {
        recordView(bk);
        printBookDetails(*bk);
        offerRating(bk);
    }
    else
        cout << "  Invalid ID or ID does not belong to that genre.\n";
}

void LibrarySystem::showSessionHistory() const
{
    cout << "\n  === This Session's View History ===\n";
    sessionHistory.display(bookList);
}

void LibrarySystem::showAllTimeHistory() const
{
    cout << "\n  === All-Time View History (from file) ===\n";
    FileHandler::showHistoryFile();
}

void LibrarySystem::showMostViewed()
{
    cout << "\n  === Top 5 Most Viewed Books ===\n";

    viewPQ.clear();
    const ListNode* cur = bookList.getHead();
    while (cur)
    {
        if (cur->data.viewCount > 0)
            viewPQ.insert(cur->data.id, (float)cur->data.viewCount);
        cur = cur->next;
    }

    if (viewPQ.isEmpty()) { cout << "  No books viewed yet.\n"; return; }

    int rank = 1;
    while (!viewPQ.isEmpty() && rank <= 5)
    {
        PQNode      pn = viewPQ.extractMax();
        const Book* bk = bookList.findByID(pn.bookID);
        if (bk)
            cout << "  " << rank++ << ". [ID " << bk->id << "]  "
            << left << setw(38) << bk->title
            << "  " << (int)pn.priority << " view(s)\n";
    }
}

void LibrarySystem::showTopRated()
{
    cout << "\n  === Top 5 Highest Rated Books ===\n";

    ratingPQ.clear();
    const ListNode* cur = bookList.getHead();
    while (cur)
    {
        if (cur->data.ratingCount > 0)
        {
            float avg = cur->data.totalRating / cur->data.ratingCount;
            ratingPQ.insert(cur->data.id, avg);
        }
        cur = cur->next;
    }

    if (ratingPQ.isEmpty()) { cout << "  No books rated yet.\n"; return; }

    int rank = 1;
    while (!ratingPQ.isEmpty() && rank <= 5)
    {
        PQNode      pn = ratingPQ.extractMax();
        const Book* bk = bookList.findByID(pn.bookID);
        if (bk)
            cout << "  " << rank++ << ". [ID " << bk->id << "]  "
            << left << setw(38) << bk->title
            << "  Avg: " << fixed << setprecision(2) << pn.priority
            << "  (" << bk->ratingCount << " ratings)\n";
    }
}

void LibrarySystem::showAllBooks() const
{
    cout << "\n  === All Books in Library ===";
    bookList.displayAll();
}


void LibrarySystem::run()

{
    cout << "\n   =================================================\n";
    cout << "  ||  Library Management & Recommendation System   ||\n";
    cout << "  ||  Bahria University — Dept. of Software Eng.   ||\n";
    cout << "   =================================================\n\n";

    if (!loadFromFile())
    {
        cout << "  Exiting — cannot proceed without database.\n";
        return;
    }

    int choice = -1;
    while (choice != 0)
    {
        cout << "\n  =============== MAIN MENU ===============\n";
        cout << "   1.  Add a new book\n";
        cout << "   2.  Search by ID\n";
        cout << "   3.  Search by Title\n";
        cout << "   4.  Search by Author\n";
        cout << "   5.  Search by Genre\n";
        cout << "   6.  This session's history\n";
        cout << "   7.  All-time history (from file)\n";
        cout << "   8.  Most viewed books  (Top 5)\n";
        cout << "   9.  Top rated books    (Top 5)\n";
        cout << "  10.  Show all books\n";
        cout << "   0.  Exit\n";
        cout << "   =========================================\n";
        cout << "  Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case  1: addBook();             break;
        case  2: searchByID();          break;
        case  3: searchByTitle();       break;
        case  4: searchByAuthor();      break;
        case  5: searchByGenre();       break;
        case  6: showSessionHistory();  break;
        case  7: showAllTimeHistory();  break;
        case  8: showMostViewed();      break;
        case  9: showTopRated();        break;
        case 10: showAllBooks();        break;
        case  0: cout << "\n  Goodbye!\n\n"; break;
        default: cout << "  Invalid choice. Try again.\n";
        }
    }
}