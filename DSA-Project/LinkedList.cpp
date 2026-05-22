#include "LinkedList.h"
using namespace std;

LinkedList::LinkedList() { head = nullptr; }
LinkedList::~LinkedList() { clear(); }

void LinkedList::clear() {
    ListNode* cur = head;
    while (cur) {
        ListNode* tmp = cur;
        cur = cur->next;
        delete tmp;
    }
    head = nullptr;
}

void LinkedList::addBook(const Book& b) {
    ListNode* node = new ListNode();
    node->data = b;
    node->next = nullptr;
    if (!head) { head = node; return; }
    ListNode* cur = head;
    while (cur->next) cur = cur->next;
    cur->next = node;
}

ListNode* LinkedList::getHead() const { return head; }

Book* LinkedList::findByID(int id) {
    ListNode* cur = head;
    while (cur) {
        if (cur->data.id == id) return &cur->data;
        cur = cur->next;
    }
    return nullptr;
}

const Book* LinkedList::findByID(int id) const {
    const ListNode* cur = head;
    while (cur) {
        if (cur->data.id == id) return &cur->data;
        cur = cur->next;
    }
    return nullptr;
}

void LinkedList::displayAll() const {
    if (!head) { cout << "  No books in the library.\n"; return; }
    cout << "\n"
        << left
        << setw(6) << "ID"
        << setw(40) << "Title"
        << setw(24) << "Author"
        << setw(12) << "Genre"
        << setw(7) << "Views"
        << "Avg Rating\n"
        << string(96, '=') << "\n";
    const ListNode* cur = head;
    while (cur) {
        const Book& bk = cur->data;
        float avg = (bk.ratingCount > 0) ? bk.totalRating / bk.ratingCount : 0.0f;
        cout << left
            << setw(6) << bk.id
            << setw(40) << bk.title.substr(0, 38)
            << setw(24) << bk.author.substr(0, 22)
            << setw(12) << bk.genre
            << setw(7) << bk.viewCount;
        if (bk.ratingCount > 0)
            cout << fixed << setprecision(2) << avg
            << "  (" << bk.ratingCount << " ratings)";
        else
            cout << "Not rated";
        cout << "\n";
        cur = cur->next;
    }
    cout << "\n";
}
