# Complexity Analysis

This document provides the time complexity analysis of the data structures and operations used in the Library Management & Recommendation System.

---

# Linked List

| Operation                | Complexity |
| ------------------------ | ---------- |
| Add Book                 | O(n)       |
| Search by ID (List Only) | O(n)       |
| Search by Title          | O(n)       |
| Search by Author         | O(n)       |
| Search by Genre          | O(n)       |
| Display All Books        | O(n)       |

Reason: Linked Lists require traversal from the head node.

---

# Binary Search Tree (BST)

| Operation | Complexity |
| --------- | ---------- |
| Insert    | O(log n)*  |
| Search    | O(log n)*  |

* In a balanced BST.

Reason: BST reduces searching time compared to linear searching.

---

# Stack

| Operation       | Complexity |
| --------------- | ---------- |
| Push            | O(1)       |
| Pop             | O(1)       |
| Display History | O(n)       |

Reason: Elements are added and removed from the top.

---

# Priority Queue (Max Heap)

| Operation       | Complexity |
| --------------- | ---------- |
| Insert          | O(log n)   |
| Extract Maximum | O(log n)   |
| Heapify Up      | O(log n)   |
| Heapify Down    | O(log n)   |
| Check Empty     | O(1)       |

Reason: Heap restructuring may require moving through the height of the heap.

---

# File Handling

| Operation      | Complexity |
| -------------- | ---------- |
| Load Books     | O(n)       |
| Save Books     | O(n)       |
| Append History | O(1)       |

Reason: The program processes records sequentially.

---

# Overall System Performance

The combination of Linked Lists, BST, Stack, and Priority Queue enables efficient storage, searching, history tracking, and recommendation generation.

The most optimized operation in the project is searching by Book ID using the Binary Search Tree, while recommendations are efficiently generated using a Priority Queue implemented as a Max Heap.
