# Priority Queue Implementation

## Overview

The Priority Queue is one of the core data structures used in this project. It is implemented using a **Max Heap** and is responsible for generating book recommendations based on popularity and ratings.

Unlike a normal queue that follows the FIFO (First In First Out) principle, a Priority Queue serves elements according to their priority value.

---

## Why Priority Queue?

The recommendation system needs to display:

* Top 5 Most Viewed Books
* Top 5 Highest Rated Books

To efficiently retrieve the highest-ranked books, a Priority Queue based on a Max Heap was implemented.

---

## Data Structure Used

### PQNode Structure

```cpp
struct PQNode
{
    int   bookID;
    float priority;
};
```

* `bookID` stores the unique identifier of a book.
* `priority` stores either:

  * Number of views
  * Average rating

---

## Max Heap

The Priority Queue uses a Max Heap.

Example:

```text
        50
       /  \
     30    20
```

The highest priority element is always stored at the root.

This allows efficient retrieval of the most important book.

---

## Functions Implemented

### insert()

Adds a new element into the Priority Queue and maintains heap order using heapifyUp().

**Time Complexity:** O(log n)

---

### extractMax()

Removes and returns the highest-priority element from the heap.

**Time Complexity:** O(log n)

---

### heapifyUp()

Moves an inserted element upward until the Max Heap property is restored.

---

### heapifyDown()

Moves an element downward after deletion to maintain heap order.

---

### isEmpty()

Checks whether the Priority Queue contains any elements.

**Time Complexity:** O(1)

---

### clear()

Removes all elements from the Priority Queue.

**Time Complexity:** O(1)

---

## Use in Recommendation System

### Most Viewed Books

The Priority Queue stores:

```text
Book ID + View Count
```

Books with higher view counts receive higher priority.

The system repeatedly calls extractMax() to display the Top 5 Most Viewed Books.

---

### Top Rated Books

The Priority Queue stores:

```text
Book ID + Average Rating
```

Books with higher ratings receive higher priority.

The system repeatedly calls extractMax() to display the Top 5 Highest Rated Books.

---

## Complexity Analysis

| Operation       | Complexity |
| --------------- | ---------- |
| Insert          | O(log n)   |
| Extract Maximum | O(log n)   |
| Heapify Up      | O(log n)   |
| Heapify Down    | O(log n)   |
| Check Empty     | O(1)       |

---

## Contributor Role

My contribution to this project was the implementation and integration of the Priority Queue (Max Heap) used in the recommendation system. This component enables efficient ranking of books based on popularity and ratings.
