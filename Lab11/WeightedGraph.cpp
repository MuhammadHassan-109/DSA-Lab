#include "WeightedGraph.h"
#include <iostream>
#include <iomanip>

using namespace std;

edge::edge() : adj(false), weight(0) {}

WeightedGraph::WeightedGraph(int n) : n(n), matrix(n, vector<edge>(n)) {}

void WeightedGraph::addEdge(int from, int to, int weight) {
    if (from >= 0 && from < n && to >= 0 && to < n) {
        matrix[from][to].adj = true;
        matrix[from][to].weight = weight;
    }
}

void WeightedGraph::removeEdge(int from, int to) {
    if (from >= 0 && from < n && to >= 0 && to < n) {
        matrix[from][to].adj = false;
        matrix[from][to].weight = 0;
    }
}

bool WeightedGraph::isAdjacent(int from, int to) const {
    if (from >= 0 && from < n && to >= 0 && to < n) {
        return matrix[from][to].adj;
    }
    return false;
}

int WeightedGraph::getWeight(int from, int to) const {
    if (from >= 0 && from < n && to >= 0 && to < n && matrix[from][to].adj) {
        return matrix[from][to].weight;
    }
    return 0;
}

void WeightedGraph::display() const {
    cout << "Adjacency Matrix (weights shown, 0 = no edge):\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j].adj)
                cout << setw(4) << matrix[i][j].weight;
            else
                cout << setw(4) << 0;
        }
        cout << '\n';
    }
}
