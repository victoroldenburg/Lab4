#pragma once

typedef struct edge {
	int source;
	int destination;
	int weight;
} E;

typedef struct graph {
	E* edge;
	int n_vertices; //Number of vertices
	int n_edges; //Number of edges
} G;


G* createNewGraph(int sizeVertices, int sizeEdges);

void BellmanFord(G* graph, int source);

void PrintDistanceArr(int* arrDistance, int sizeVertices);