#include "BST.h"
using namespace std;

BST::BST() { root = nullptr; }
BST::~BST() { destroyHelper(root); }

void BST::destroyHelper(BSTNode* node) {
    if (!node) return;
    destroyHelper(node->left);
    destroyHelper(node->right);
    delete node;
}

void BST::clear() {
    destroyHelper(root);
    root = nullptr;
}

BSTNode* BST::insertHelper(BSTNode* node, int id) {
    if (!node) {
        BSTNode* n = new BSTNode();
        n->bookID = id;
        n->left = nullptr;
        n->right = nullptr;
        return n;
    }
    if (id < node->bookID) node->left = insertHelper(node->left, id);
    else if (id > node->bookID) node->right = insertHelper(node->right, id);
    return node;
}

BSTNode* BST::searchHelper(BSTNode* node, int id) const {
    if (!node || node->bookID == id) return node;
    if (id < node->bookID) return searchHelper(node->left, id);
    return searchHelper(node->right, id);
}

void BST::insert(int id) { root = insertHelper(root, id); }
bool BST::search(int id) const { return searchHelper(root, id) != nullptr; }
