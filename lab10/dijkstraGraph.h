#ifndef DIJKSTRA_GRAPH_H
#define DIJKSTRA_GRAPH_H

#include <string>
using namespace std;
#include "weightedGraph.h"

class DijkstraGraph : public WeightedGraph {
   
   public:
   DijkstraGraph(int size);
   string shortestPath(int u, int v);

};

#endif
