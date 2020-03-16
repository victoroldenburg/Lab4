#pragma once

//typedef struct Edge { 
//	int index; //int to key
//	struct Edge* next; //Pointer to next node, next = 0 -> tail
//	struct Edge* prev; //Pointer to prev node , prev = 0 -> head
//} E;		//Not using this struct for new nodes. Using struct node in list.h insted

typedef struct graph {
	struct Vertex* source; //Array head
	int n_vertices;
} G;

typedef struct Vertex {
	int index; //Vertex index
	struct Node* head; //List head
} V;

G* createGraph(int n);

G* printArray(G* graph);

int getNumVertices(G* graph);

int getNumEdges(G* graph);

int* getNeighbors(G* graph, V* vertex); //Return a pointer to an array with Nighbors

int* getInNeighbors(G* graph, V* vertex);

int* getOutNeighbors(G* graph, V* vertex);

void addDirectedEdge(V* vertex1, V* vertex2);

void addUndirectedEdge(V* vertex1, V*vertex2);

bool hasEdge(V* vertex1, V* vertex2);


//###########SUPPORT FUNCTIONS##########

//Insert new node
bool insertEdge(V* vertex, N* newNode);

N* searchEdge(V* vertex, int key);

bool freeMemory(G* graph);


