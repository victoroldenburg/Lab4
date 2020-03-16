#include "List.h"
#include "graph.h"
#include <stddef.h>
#include <stdbool.h> 
#include <stdio.h>
#include <stdlib.h>

void runTestGraph() {

	//Test input
	int n = 60; //number of vertices to create

	//start of test
	G* graph = createGraph(n); //create graph w/o any edges

	int nrOfVertices = getNumVertices(graph); //Check how many Vertices there is in the array 

	//##########Create edges##########
	//Input numbers, which vertex to add edges to
	int index1 = 10;

	int index2 = 13;

	int index3 = 18;

	int index4 = 21;

	int index5 = 23;


	V* vertex = graph->source;

	V* vertex1 = &vertex[index1];

	V* vertex2 = &vertex[index2];

	V* vertex3 = &vertex[index3];

	V* vertex4 = &vertex[index4];

	V* vertex5 = &vertex[index5];

	//#########################Insert edge to vertex with index###################################
		//Create new edges
	addDirectedEdge(vertex1, vertex4);
	addDirectedEdge(vertex1, vertex3);
	addDirectedEdge(vertex1, vertex2);
	addDirectedEdge(vertex1, vertex5);

	//Insert edge to vertex
	addDirectedEdge(vertex3, vertex1);
	addDirectedEdge(vertex3, vertex2);
	addDirectedEdge(vertex3, vertex3);
	addDirectedEdge(vertex3, vertex4);

	addDirectedEdge(vertex2, vertex1);
	addDirectedEdge(vertex5, vertex1);

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
	printf("Print vertex5 after function addDirectedEdge:  ");
	listprint = vertex5->head;
	printlist(listprint);




	//#######################Insert undirected edges to vertex#########################
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


	//#####################HAS EDGE??############################
	printf("\n\n"); //New lines
	bool hasEdgetest1 = hasEdge(vertex3, vertex2); //true
	bool hasEdgetest2 = hasEdge(vertex2, vertex3);	//false
	bool hasEdgetest3 = hasEdge(vertex5, vertex4);	//true


	//#####################GET NUMBER OF EDGES###################
	int numberOfEdges = getNumEdges(graph);


	//#####################NEIGHBORS#############################

	//Out Nighbors
	int* outNeighborsArray = getOutNeighbors(graph, vertex1);
	printf("\n\n"); //New lines
	printf("Print array of integers for OutNighbors: ");
	printIntArray(outNeighborsArray);

	//In Neighbors
	int* inNeighborsArray = getInNeighbors(graph, vertex1);
	printf("\n\n"); //New lines
	printf("Print array of integers for InNighbors: ");
	printIntArray(inNeighborsArray);


	
	//Prints struct vertices array
	printf("\n\n"); //New lines
	//G* graphr = printArray(graph);



	//Free memory
	freeMemory(graph);

	//STOP

}
