#include "PriorityQueue.h"
#include <iostream>
using namespace std;

PriorityQueue::PriorityQueue(int cap) {
    capacity = cap;
    size = 0;
    heap = new PQNode[cap];
}
PriorityQueue::~PriorityQueue() { delete[] heap; }
void PriorityQueue::swapNodes(int i, int j) {
    PQNode tmp = heap[i];
    heap[i] = heap[j];
    heap[j] = tmp;
}
void PriorityQueue::heapifyUp(int idx) {
    while (idx > 0) {
        int parent = (idx - 1) / 2;
        if (heap[idx].priority > heap[parent].priority) {
            swapNodes(idx, parent);
            idx = parent;
        }
        else break;
    }
}
void PriorityQueue::heapifyDown(int idx) {
    while (true) {
        int largest = idx;
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;
        if (left  < size && heap[left].priority  > heap[largest].priority) largest = left;
        if (right < size && heap[right].priority > heap[largest].priority) largest = right;
        if (largest != idx) { swapNodes(idx, largest); idx = largest; }
        else break;
    }
}
void PriorityQueue::insert(int id, float priority) {
    if (size >= capacity) { cout << "  Priority queue is full.\n"; return; }
    heap[size] = { id, priority };
    heapifyUp(size);
    size++;
}
PQNode PriorityQueue::extractMax() {
    PQNode maxNode = heap[0];
    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0);
    return maxNode;
}
bool PriorityQueue::isEmpty() const { return size == 0; }
void PriorityQueue::clear() { size = 0; }
