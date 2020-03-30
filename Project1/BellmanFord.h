#pragma once

/* This file provide call to the functions in BellmanFord.c */

typedef struct edge {
	int source;
	int destination;
	int weight;
} E;

typedef struct graph {
	E* edge; //An edge is part of a graph
	int n_vertices; //Number of vertices
	int n_edges; //Number of edges
} G;

//Create the graph
G* createNewGraph(int sizeVertices, int sizeEdges);

//Run the Algoritm on graph
void BellmanFord(G* graph, int source);

//Print resulting distance
void PrintDistanceArr(int* arrDistance, int sizeVertices);
