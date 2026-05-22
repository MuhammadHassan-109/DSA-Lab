#pragma once
#include "LinkedList.h"
using namespace std;

struct StackNode {
    int        bookID;
    StackNode* next;
};

class Stack {
private:
    StackNode* top;
public:
    Stack();
    ~Stack();
    void push(int id);
    int  pop();
    bool isEmpty() const;
    void display(const LinkedList& lib) const;
};
