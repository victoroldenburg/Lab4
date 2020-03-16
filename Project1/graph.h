#pragma once

typedef struct Edge {
	int index; //int to key
	struct Edge* next; //Pointer to next node, next = 0 -> tail
	struct Edge* prev; //Pointer to prev node , prev = 0 -> head
} E;

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

int getNumEdges(G*);

int* getNeighbors(G*);

int* getInNeighbors(G*);

int* getOutNeighbors(G*);

void addDirectedEdge(V* vertex1, V* vertex2);

void addUndirectedEdge(V* vertex1, V*vertex2);

bool hasEdge(int node_a, int node_b);


//###########Support fucntions##########

//Insert new node
bool insertEdge(V* vertex, N* newNode);


