#pragma once

#include <vector>
using namespace std;

struct edge {
    bool adj;
    int weight;
    edge();
};

class WeightedGraph {
private:
    int n;
    vector<vector<edge>> matrix; 
public:
    WeightedGraph(int n);
    void addEdge(int from, int to, int weight);
    void removeEdge(int from, int to);
    bool isAdjacent(int from, int to) const;
    int getWeight(int from, int to) const;
    void display() const;
};
