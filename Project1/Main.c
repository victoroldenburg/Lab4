#include "List.h"
#include "Stack.h"
#include "Queue.h"
#include "graph.h"
#include <stddef.h>
#include <stdbool.h> 
#include <stdio.h>
#include <stdlib.h>

int main() {
	//Input numbers
	int n = 60;

	int index1 = 5;

	int index2 = 56;

	int index3 = 6;

	int index4 = 57;


	//start of test
	G* graph = createGraph(n);

	G* graphr = printArray(graph);

	int nrOfVertices = getNumVertices(graph);

	//Create new edges
	V* vertex = graph->source;

	V vertex1 = vertex[index1];

	V vertex2 = vertex[index2];

	V* vertex1add = &vertex1;

	V* vertex2add = &vertex2;

	addDirectedEdge(vertex1add, vertex2add);

	//addDirectedEdge(vertex1, vertex3);


	//V* test = vertex[index1].head->prev;


	//Free memory
	//free(graph);
	return 0;
}
