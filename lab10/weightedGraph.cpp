#include "weightedGraph.h"

   WeightedGraph::WeightedGraph(int x) :
     N(x) , graph(new int*[N])
   {
      for(int i=0; i<N; i++)
        graph[i] = new int[N];
      for(int i = 0; i < N; i++)
         for(int j = 0; j < N; j++)
            graph[i][j] = NO_ARC;
   }

  WeightedGraph::~WeightedGraph() 
  {
     for(int i=0; i<N; i++)
        delete [] graph[i];
     delete [] graph;
  }
   
   void WeightedGraph::addEdge(int u, int v, int w) 
   {
        // implement  
   }

   
   
   ostream & operator<< ( ostream & out, const  WeightedGraph & thisGraph ) 
   {
      for(int i = 0; i < thisGraph.N; i++) {
         out << i <<  ": ";
         for(int j = 0; j < thisGraph.N; j++) {
            if( thisGraph.graph[i][j] != thisGraph.NO_ARC)
               out <<  "(" << j << "," << thisGraph.graph[i][j] << ") ";
         }
         out << endl;
      }              
      return out;
   }
   


