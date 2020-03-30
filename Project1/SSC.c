#include "BFS.h"
#include "graph.h"
#include <stdio.h>

int runEx3SCC() {
	printf("\n##############RUNNING SCC##############\n");

	//Update n
	int n = 99;

	//Create a new graph
	G* graph_ex3 = createGraph(n);

	//Number of verts.
	int nrOfVertices = getNumVertices(graph_ex3);

	//Input numbers, which vertex to add edges to
	int index1 = 33;
	int index2 = 42;
	int index3 = 22;
	int index4 = 76;
	int index5 = 35;
	int index6 = 62;

	V* vertex = graph_ex3->source;

	V* vertex1 = &vertex[index1];
	V* vertex2 = &vertex[index2];
	V* vertex3 = &vertex[index3];
	V* vertex4 = &vertex[index4];
	V* vertex5 = &vertex[index5];
	V* vertex6 = &vertex[index6];

	//Create new edges
	addDirectedEdge(&vertex[33], &vertex[76]); //0
	addDirectedEdge(&vertex[33], &vertex[22]);

	addDirectedEdge(&vertex[42], &vertex[33]); //1

	addDirectedEdge(&vertex[22], &vertex[42]); //2

	addDirectedEdge(&vertex[76], &vertex[35]); //3

	addDirectedEdge(&vertex[35], &vertex[62]); //4

	addDirectedEdge(&vertex[62], &vertex[76]); //5

	printArray(graph_ex3);

	BFS(graph_ex3, vertex1);
	resetBFS(graph_ex3, vertex1);

	BFS(graph_ex3, vertex2);
	resetBFS(graph_ex3, vertex2);

	BFS(graph_ex3, vertex3);
	resetBFS(graph_ex3, vertex3);

	BFS(graph_ex3, vertex4);
	resetBFS(graph_ex3, vertex4);

	BFS(graph_ex3, vertex5);
	resetBFS(graph_ex3, vertex5);
	
	BFS(graph_ex3, vertex6);
	resetBFS(graph_ex3, vertex6);

	//#####################Free Memory############################
	freeMemory(graph_ex3);
}