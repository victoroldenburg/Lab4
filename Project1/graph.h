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
	struct Edge* head; //List head
	int index; //Vertex index
} V;

G* createGraph(int n);

G* printArray(G* graph);