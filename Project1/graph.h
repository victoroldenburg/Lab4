#pragma once

typedef struct Edge {
	int index; //int to key
	struct Edge* next; //Pointer to next node, next = 0 -> tail
	struct Edge* prev; //Pointer to prev node , prev = 0 -> head
} E;

typedef struct graph {
	struct Vertex* head; //List head
	struct Vertex* tail; //Queue tail
	
} G;

typedef struct Vertex {
	struct Edge* head; //List head
	struct Edge* tail; //Queue tail
	int index; //Vertex index
} V;

void createGraph(int n);