#include "Stack.h"
using namespace std;

Stack::Stack() { top = nullptr; }
Stack::~Stack() {
    StackNode* cur = top;
    while (cur) {
        StackNode* tmp = cur;
        cur = cur->next;
        delete tmp;
    }
}
void Stack::push(int id) {
    StackNode* node = new StackNode();
    node->bookID = id;
    node->next = top;
    top = node;
}
int Stack::pop() {
    if (isEmpty()) return -1;
    int id = top->bookID;
    StackNode* tmp = top;
    top = top->next;
    delete tmp;
    return id;
}
bool Stack::isEmpty() const { return top == nullptr; }
void Stack::display(const LinkedList& lib) const {
    if (isEmpty()) { cout << "  No history for this session.\n"; return; }
    cout << "  Session history (most recent first):\n"
        << "  " << string(50, '-') << "\n";
    const StackNode* cur = top;
    int rank = 1;
    while (cur) {
        const Book* bk = lib.findByID(cur->bookID);
        cout << "  " << rank++ << ". [ID " << cur->bookID << "]  ";
        if (bk) cout << bk->title << "  —  " << bk->author;
        else    cout << "(book not found)";
        cout << "\n";
        cur = cur->next;
    }
}
