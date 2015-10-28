#ifndef WEIGHTED_GRAPH_H
#define WEIGHTED_GRAPH_H

#include <iostream>
using namespace std;

class WeightedGraph {
   protected:
      const int N;   
      int** graph; // 2d-array
      static const int NO_ARC = 0;
     
   public:
     WeightedGraph(int x);
     virtual ~WeightedGraph();
     void addEdge(int u, int v, int w);
   
   friend ostream & operator<< (ostream &,const WeightedGraph &);
   
};

#endif

