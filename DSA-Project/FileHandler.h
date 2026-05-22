#pragma once
#include "LinkedList.h"
#include "BST.h"
#include <string>
using namespace std;

extern const string DB_FILE;
extern const string HISTORY_FILE;
extern const char   DELIM;

class FileHandler {
private:
    static bool parseLine(const string& line, Book& out);
public:
    static int  loadBooks(LinkedList& list, BST& bst);
    static bool saveBooks(const LinkedList& list);
    static bool appendHistory(int bookID, const string& title);
    static void showHistoryFile();
};
