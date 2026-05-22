#include "FileHandler.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
using namespace std;

const string DB_FILE = "library.txt";
const string HISTORY_FILE = "history.txt";
const char   DELIM = '|';

bool FileHandler::parseLine(const string& line, Book& out) {
    istringstream ss(line);
    string token;
    if (!getline(ss, token, DELIM)) return false;
    try { out.id = stoi(token); }
    catch (...) { return false; }
    if (!getline(ss, out.title, DELIM)) return false;
    if (!getline(ss, out.author, DELIM)) return false;
    if (!getline(ss, out.genre, DELIM)) return false;
    if (!getline(ss, token, DELIM)) return false;
    try { out.viewCount = stoi(token); }
    catch (...) { return false; }
    if (!getline(ss, token, DELIM)) return false;
    try { out.totalRating = stof(token); }
    catch (...) { return false; }
    if (!getline(ss, token, DELIM)) return false;
    try { out.ratingCount = stoi(token); }
    catch (...) { return false; }
    return true;
}

int FileHandler::loadBooks(LinkedList& list, BST& bst) {
    ifstream fin(DB_FILE);
    if (!fin.is_open()) {
        cerr << "  [File] Cannot open \"" << DB_FILE << "\" for reading.\n";
        return -1;
    }
    int count = 0;
    string line;
    while (getline(fin, line)) {
        if (line.empty() || line[0] == '#') continue;
        if (!line.empty() && line.back() == '\r') line.pop_back();
        Book b;
        if (parseLine(line, b)) {
            list.addBook(b);
            bst.insert(b.id);
            count++;
        }
        else {
            cerr << "  [File] Skipping malformed line: " << line << "\n";
        }
    }
    fin.close();
    return count;
}

bool FileHandler::saveBooks(const LinkedList& list) {
    ofstream fout(DB_FILE);
    if (!fout.is_open()) {
        cerr << "  [File] Cannot open \"" << DB_FILE << "\" for writing.\n";
        return false;
    }
    fout << "# Library Management System - Database File\n";
    const ListNode* cur = list.getHead();
    while (cur) {
        const Book& bk = cur->data;
        fout << bk.id << DELIM
            << bk.title << DELIM
            << bk.author << DELIM
            << bk.genre << DELIM
            << bk.viewCount << DELIM
            << fixed << setprecision(1) << bk.totalRating << DELIM
            << bk.ratingCount << "\n";
        cur = cur->next;
    }
    fout.close();
    return true;
}

bool FileHandler::appendHistory(int bookID, const string& title) {
    ofstream fout(HISTORY_FILE, ios::app);
    if (!fout.is_open()) {
        cerr << "  [File] Cannot open \"" << HISTORY_FILE << "\" for writing.\n";
        return false;
    }
    fout << "VIEWED|" << bookID << "|" << title << "\n";
    fout.close();
    return true;
}

void FileHandler::showHistoryFile() {
    ifstream fin(HISTORY_FILE);
    if (!fin.is_open()) {
        cout << "  No persistent history file found yet.\n";
        return;
    }
    cout << "  All-time view history (from " << HISTORY_FILE << "):\n"
        << "  " << string(52, '-') << "\n";
    string line;
    int    rank = 1;
    bool   any = false;
    while (getline(fin, line)) {
        if (line.empty() || line[0] == '#') continue;
        if (!line.empty() && line.back() == '\r') line.pop_back();
        istringstream ss(line);
        string tag, idStr, title;
        if (!getline(ss, tag, '|')) continue;
        if (!getline(ss, idStr, '|')) continue;
        if (!getline(ss, title, '|')) continue;
        cout << "  " << rank++ << ". [ID " << idStr << "]  " << title << "\n";
        any = true;
    }
    if (!any) cout << "  History file is empty.\n";
    fin.close();
}
