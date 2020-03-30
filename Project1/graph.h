#pragma once
#include <stdbool.h>

/* This file provide call to the functions in graph.c */

//###########STRUCTS##########

typedef struct Node {
	int data; //Number saved in a Node
	struct Node* next; //Pointer to next node, next = 0 -> tail
	struct Node* prev; //Pointer to prev node , prev = 0 -> head
} N;

typedef struct List {
	struct Node* head; //List head
	struct Node* tail; //Queue tail
	int data; //Number saved in a list
} L;

typedef struct graph {
	struct Vertex* source; //Array head
	int n_vertices; //Number of vertices
} G;

typedef struct Vertex {
	int index; //Vertex index
	struct Node* head; //List head
	int visited; //Number if visited: 0 No, 1 Yes
	int path; //Shortest path in BFS
} V;

//###########MAIN FUNCTIONS##########

//Create and return a graph containing n vertices (each vertex is an integerbetween 1 and n).
G* createGraph(int n);

//Returns the number of vertices in graph G
int getNumVertices(G* graph);

//Returns the total number of edges of graph G
int getNumEdges(G* graph);

//Returns all vertices connected to node v with any edge
int* getNeighbors(G* graph, V* vertex);

//Returns a list of all vertices v0 connected to node v with an edge (v0; v)
int* getInNeighbors(G* graph, V* vertex);

//Returns a list of all vertices v0 connected to node v with an edge(v; v0)
int* getOutNeighbors(G* graph, V* vertex);

//Create a directed edge between two vertices.
void addDirectedEdge(V* vertex1, V* vertex2);

//Create an undirected edge between two vertices.
void addUndirectedEdge(V* vertex1, V* vertex2);

//Returns true (1) if there is an edge between v1 and v2 and false (0) otherwise.
bool hasEdge(V* vertex1, V* vertex2);


//###########SUPPORT FUNCTIONS##########
//Create each new Node, copied from earlier assignment
N* createNode(int key);

//Prints the struct array with vertex index, adress and edge list
void printArray(G* graph);

//Prints the array of ints returned from neighbors functions
void printIntArray(int* array);

//Inserts edge in vertex array
bool insertEdge(V* vertex, N* newNode); //Insert new node

//Searching for specific edge beloning to specific vertex
N* searchEdge(V* vertex, int key);

//Delete edge-node from graph
bool deleteNodeGraph(V* vertex, N* node);

//Free allocated memory for graph and vertex
bool freeMemory(G* graph);
