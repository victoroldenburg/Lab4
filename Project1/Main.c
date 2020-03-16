#include "List.h"
#include "Stack.h"
#include "Queue.h"
#include "graph.h"
#include <stddef.h>
#include <stdbool.h> 
#include <stdio.h>
#include <stdlib.h>

int main() {

	//Test input
	int n = 60;
	
	//start of test
	G* graph = createGraph(n);

	int nrOfVertices = getNumVertices(graph);

	//##########Create edges##########
		
	//Input numbers
	int index1 = 5;

	int index2 = 56;

	int index3 = 18;

	int index4 = 57;

	//Create new edges
	V* vertex = graph->source;

	V* vertex1 = &vertex[index1];

	V* vertex2 = &vertex[index2];

	V* vertex3 = &vertex[index3];

	V* vertex4 = &vertex[index4];

	//Insert edge to vertex with index
	addDirectedEdge(vertex1, vertex2);
	addDirectedEdge(vertex1, vertex3);
	addDirectedEdge(vertex1, vertex3);
	addDirectedEdge(vertex1, vertex3);

	//Prints list
	printf("Print vertex3 before func addDirectedEdge: ");
	N* listprint = vertex3->head;
	printlist(listprint);

	//Insert edge to vertex with index1
	addDirectedEdge(vertex3, vertex1);
	addDirectedEdge(vertex3, vertex2);
	addDirectedEdge(vertex3, vertex3);
	addDirectedEdge(vertex3, vertex4);


	//Prints list
	printf("Print vertex1 after function addDirectedEdge");
	listprint = vertex1->head;
	printlist(listprint);


	//Prints list
	printf("Print vertex3 after function addDirectedEdge: ");
	listprint = vertex3->head;
	printlist(listprint);

	//Prints struct vertex array
	G* graphr = printArray(graph);


	//Free memory
	free(graph);
	return 0;
}
