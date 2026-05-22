#pragma once
using namespace std;

struct BSTNode {
    int      bookID;
    BSTNode* left;
    BSTNode* right;
};

class BST {
private:
    BSTNode* root;
    BSTNode* insertHelper(BSTNode* node, int id);
    BSTNode* searchHelper(BSTNode* node, int id) const;
    void     destroyHelper(BSTNode* node);
public:
    BST();
    ~BST();
    void insert(int id);
    bool search(int id) const;
    void clear();
};
