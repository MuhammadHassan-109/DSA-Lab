#pragma once

#include "ListNode.h"
#include <iostream>
#include <iomanip>
using namespace std;

class LinkedList {
private:
    ListNode* head;
public:
    LinkedList();
    ~LinkedList();

    void        addBook(const Book& b);
    ListNode* getHead() const;
    Book* findByID(int id);
    const Book* findByID(int id) const;
    void        displayAll() const;
    void        clear();
};
