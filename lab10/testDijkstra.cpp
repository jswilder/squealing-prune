#include "weightedGraph.h"
#include "dijkstraGraph.h"
#include <iostream>
using namespace std;

int main( ) 
{
      cout << "Build WeightedGraph" << endl;
      WeightedGraph d(8);
      d.addEdge(1, 2, 2);
      d.addEdge(1, 4, 1);
      d.addEdge(2, 4, 3);
      d.addEdge(2, 5, 10);
      d.addEdge(2, 5, 10);
      d.addEdge(3, 1, 4);
      d.addEdge(3, 6, 5);
      d.addEdge(4, 3, 5);
      d.addEdge(4, 5, 2);
      d.addEdge(4, 6, 13);
      d.addEdge(4, 7, 8);
      d.addEdge(6, 7, 8);
      d.addEdge(5, 7, 6);
      d.addEdge(7, 6, 1);
      cout << d << endl;

      cout << "Build DijkstraGraph" << endl;
      DijkstraGraph w(8);
      w.addEdge(0, 2, 4);
      w.addEdge(1, 4, 5);
      w.addEdge(1, 3, 1);
      w.addEdge(1, 7, 1);
      w.addEdge(2, 3, 2);
      w.addEdge(2, 7, 3);
      w.addEdge(3, 5, 8);
      w.addEdge(3, 6, 7);
      w.addEdge(3, 7, 5);
      w.addEdge(4, 0, 1);
      w.addEdge(6, 5, 2);
      w.addEdge(7, 6, 1);
      cout << w << endl;
      cout << "find short path from 0 to 6: ";
      cout << w.shortestPath(0, 6) << endl;
      cout << "find short path from 4 to 2: ";
      cout << w.shortestPath(4, 2) << endl;
      cout << "find short path from 7 to 1: ";
      cout << w.shortestPath(7, 1) << endl;

}


