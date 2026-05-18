#include "WeightedGraph.h"
#include <iostream>
using namespace std;


int main() {
    WeightedGraph g(4);

    
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 4);
    g.addEdge(2, 3, 1);

    cout << "Adjacency Matrix (with weights):\n";
    g.display();

  
    cout << "\nChecking adjacency:\n";
    cout << "0->1: " << (g.isAdjacent(0, 1) ? "Yes" : "No")
        << ", weight = " << g.getWeight(0, 1) << endl;
    cout << "1->0: " << (g.isAdjacent(1, 0) ? "Yes" : "No") << endl;
    cout << "2->3: " << (g.isAdjacent(2, 3) ? "Yes" : "No")
        << ", weight = " << g.getWeight(2, 3) << endl;

   
    g.removeEdge(1, 2);
    cout << "\nAfter removing edge 1->2:\n";
    g.display();

    return 0;
}
