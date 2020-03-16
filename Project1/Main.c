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
	int index1 = 10;

	int index2 = 13;

	int index3 = 18;

	int index4 = 21;

	int index5 = 23;

	//Create new edges
	V* vertex = graph->source;

	V* vertex1 = &vertex[index1];

	V* vertex2 = &vertex[index2];

	V* vertex3 = &vertex[index3];

	V* vertex4 = &vertex[index4];

	V* vertex5 = &vertex[index5];

	//Insert edge to vertex with index
	addDirectedEdge(vertex1, vertex4);
	addDirectedEdge(vertex1, vertex3);
	addDirectedEdge(vertex1, vertex2);
	addDirectedEdge(vertex1, vertex1);

	//Insert edge to vertex with index1
	addDirectedEdge(vertex3, vertex1);
	addDirectedEdge(vertex3, vertex2);
	addDirectedEdge(vertex3, vertex3);
	addDirectedEdge(vertex3, vertex4);

	//Prints list
	printf("Print vertex1 after function addDirectedEdge:  ");
	N* listprint = vertex1->head;
	printlist(listprint);

	//Prints list
	printf("Print vertex2 after function addDirectedEdge:  ");
	listprint = vertex2->head;
	printlist(listprint);

	//Prints list
	printf("Print vertex3 after function addDirectedEdge:  ");
	listprint = vertex3->head;
	printlist(listprint);

	//Prints list
	printf("Print vertex4 after function addDirectedEdge:  ");
	listprint = vertex4->head;
	printlist(listprint);

	//Prints list
	printf("Print vertex5 after function addUnDirectedEdge:  ");
	listprint = vertex5->head;
	printlist(listprint);

	
	
	
	//Insert undirected edges to vertex
	addUndirectedEdge(vertex4, vertex5);
	
	
	//Prints list
	printf("\n\n"); //New lines

	printf("Print vertex1 after function addUnDirectedEdge:  ");
	listprint = vertex1->head;
	printlist(listprint);

	//Prints list
	printf("Print vertex2 after function addUnDirectedEdge:  ");
	listprint = vertex2->head;
	printlist(listprint);

	//Prints list
	printf("Print vertex3 after function addUnDirectedEdge:  ");
	listprint = vertex3->head;
	printlist(listprint);

	//Prints list
	printf("Print vertex4 after function addUnDirectedEdge:  ");
	listprint = vertex4->head;
	printlist(listprint);

	//Prints list
	printf("Print vertex5 after function addUnDirectedEdge:  ");
	listprint = vertex5->head;
	printlist(listprint);


	//Prints struct vertex array
	G* graphr = printArray(graph);


	//Free memory
	free(graph);
	return 0;
}
