#pragma once
using namespace std;

struct PQNode {
    int   bookID;
    float priority;
};

class PriorityQueue {
private:
    PQNode* heap;
    int     capacity;
    int     size;
    void heapifyUp(int idx);
    void heapifyDown(int idx);
    void swapNodes(int i, int j);
public:
    PriorityQueue(int cap);
    ~PriorityQueue();
    void   insert(int id, float priority);
    PQNode extractMax();
    bool   isEmpty() const;
    void   clear();
};
