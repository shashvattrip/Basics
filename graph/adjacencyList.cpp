//http://www.sanfoundry.com/cpp-program-implement-adjacency-matrix/

#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

struct AdjListNode {
  int dest;
  struct AdjListNode *next;
};

struct AdjList {
  struct AdjListNode *head;
};

struct Graph {
  int V;
  struct AdjList *array;
};

//funct to create a new Adjacency list Node
struct AdjListNode* newAdjListNode(int dest);

//function to create a graph of V vertices
struct Graph* createGraph(int V);

//funct to add an edge to an undirected graph
void addEdge(struct Graph *graph, int src, int dest);

//funct to print the adjacency list representation of the graph
void printGraph(struct Graph *graph);

int main() {
  int V = 5;
  struct Graph *graph = createGraph(V);
  addEdge(graph, 0, 1);
  addEdge(graph, 0, 4);
  addEdge(graph, 1, 2);
  addEdge(graph, 1, 3);
  addEdge(graph, 1, 4);
  addEdge(graph, 2, 3);
  addEdge(graph, 3, 4);

  printGraph(graph);
  return 0;
}


struct Graph* createGraph(int V) {
  struct Graph *graph;
  graph = new (struct Graph);
  graph->V = V;

  //create an array of Adjacency Lists of size V ie in the array there will be V elements
  graph->array = new (AdjList)[V];
  //initialize all the elements in the array as NULL
  for(int i = 0; i < V ; i++) {
    graph->array[i].head = NULL;
  }
  return graph;
}

struct AdjListNode* newAdjListNode(int dest) {
  struct AdjListNode *newNode = new (struct AdjListNode);
  newNode->dest = dest;
  newNode->next = NULL;
  return newNode;
}

void addEdge(struct Graph *graph, int src, int dest) {
  //add edge from src to dest
  //add a node in the AdjList of the source
  //The new node is added in the begining
  struct AdjListNode *newNode = newAdjListNode(dest);
  newNode->next = graph->array[src].head;
  graph->array[src].head = newNode;

  //add a node in the AdjList of the dest as it is undirected Graph
  newNode = newAdjListNode(src);
  newNode->next = graph->array[dest].head;
  graph->array[dest].head = newNode;
}

void printGraph(struct Graph *graph) {
  for(int v = 0 ; v < graph->V ; v++) {
    struct AdjListNode *iter = graph->array[v].head;
    cout<<"\nAdjacency List of vertex : "<<v<<endl;
    while(iter) {
      cout<<"->"<<iter->dest;
      iter = iter->next;
    }
    cout<<endl;
  }
}


