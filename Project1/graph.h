#pragma once
#include "List.h"
#include <stdbool.h>

//typedef struct Edge { 
//	int index; //int to key
//	struct Edge* next; //Pointer to next node, next = 0 -> tail
//	struct Edge* prev; //Pointer to prev node , prev = 0 -> head
//} E;		//Not using this struct for new nodes. Using struct node in list.h insted

typedef struct graph {
	struct Vertex* source; //Array head
	struct Vertex* vertex; //Sample vertex
	int n_vertices; //Number of vertices
} G;

typedef struct Vertex {
	int index; //Vertex index
	struct Node* head; //List head
	int distance; //distance from source
	struct Node* parent; //π parent node
	char color; //White=not discovered, black=discovered
} V;

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
void addUndirectedEdge(V* vertex1, V*vertex2);

//Returns true (1) if there is an edge between v1 and v2 and false (0) otherwise.
bool hasEdge(V* vertex1, V* vertex2);


//###########SUPPORT FUNCTIONS##########
//Prints the struct array with vertex index, adress and edge list
G* printArray(G* graph);

//Prints the array of ints returned from neighbors functions
void printIntArray(int* array);

//Inserts edge in vertex array
bool insertEdge(V* vertex, N* newNode); //Insert new node

//Searching for specific edge beloning to specific vertex
N* searchEdge(V* vertex, int key);

//Free allocated memory for graph and vertex
bool freeMemory(G* graph);


