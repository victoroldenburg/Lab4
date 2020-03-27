#include "List.h"
#include "graph.h"
#include "BFS.h"
#include "loadgraphfile.h"
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
	int index1 = 0;

	int index2 = 4;

	int index3 = 45;

	int index4 = 54;

	int index5 = 23;

	V* vertex = graph->source;

	V* vertex1 = &vertex[index1];

	V* vertex2 = &vertex[index2];

	V* vertex3 = &vertex[index3];

	V* vertex4 = &vertex[index4];

	V* vertex5 = &vertex[index5];

	//#########################Insert edge to vertex with following index###################################
	//Create new edges
	addDirectedEdge(&vertex[0], &vertex[12]);
	addDirectedEdge(&vertex[0], &vertex[13]);
	addDirectedEdge(&vertex[0], &vertex[14]);
	addDirectedEdge(&vertex[0], &vertex[0]);
	addDirectedEdge(&vertex[0], &vertex[16]);
	addDirectedEdge(&vertex[0], &vertex[17]);

	addDirectedEdge(&vertex[1], &vertex[0]);
	addDirectedEdge(&vertex[1], &vertex[2]);
	addDirectedEdge(&vertex[1], &vertex[4]);
	addDirectedEdge(&vertex[1], &vertex[6]);
	addDirectedEdge(&vertex[1], &vertex[8]);
	addDirectedEdge(&vertex[1], &vertex[10]);

	addDirectedEdge(&vertex[4], &vertex[23]);
	addDirectedEdge(&vertex[4], &vertex[24]);
	addDirectedEdge(&vertex[4], &vertex[25]);
	addDirectedEdge(&vertex[4], &vertex[0]);
	addDirectedEdge(&vertex[4], &vertex[27]);
	addDirectedEdge(&vertex[4], &vertex[28]);

	addDirectedEdge(&vertex[45], &vertex[1]);
	addDirectedEdge(&vertex[45], &vertex[2]);
	addDirectedEdge(&vertex[45], &vertex[3]);
	addDirectedEdge(&vertex[45], &vertex[0]);
	addDirectedEdge(&vertex[45], &vertex[5]);
	addDirectedEdge(&vertex[45], &vertex[6]);

	//#######################Insert undirected edges to vertex#########################
	addUndirectedEdge(&vertex[54], &vertex[59]);
	addUndirectedEdge(&vertex[54], &vertex[58]);
	addUndirectedEdge(&vertex[54], &vertex[57]);
	addUndirectedEdge(&vertex[54], &vertex[1]);
	addUndirectedEdge(&vertex[54], &vertex[55]);

	addUndirectedEdge(&vertex[23], &vertex[56]);
	addUndirectedEdge(&vertex[23], &vertex[55]);

	//#####################HAS EDGE??############################
	printf("Checking that specified vertex has edges.....\n");
	bool hasEdgetest1 = hasEdge(vertex3, vertex2);
	bool hasEdgetest2 = hasEdge(vertex2, vertex3);	
	bool hasEdgetest3 = hasEdge(vertex5, vertex4);	

	//#####################GET NUMBER OF EDGES###################
	int numberOfEdges = getNumEdges(graph);
	printf("\n\n"); //New lines
	printf("Total number of edges: %d: ", numberOfEdges);

	//#####################NEIGHBORS#############################
	//Out Nighbors
	int* outNeighborsArray = getOutNeighbors(graph, vertex1);
	printf("\n\n"); //New lines
	printf("Print array of integers, OutNighbors for vertex index %d: ", vertex1->index);
	printIntArray(outNeighborsArray);

	//In Neighbors
	int* inNeighborsArray = getInNeighbors(graph, vertex1);
	printf("\n\n"); //New lines
	printf("Print array of integers, InNighbors for vertex index %d: ", vertex1->index);
	printIntArray(inNeighborsArray);

	//Get Neighbors
	int* nrOfNeighborsArray = getNeighbors(graph, vertex1);
	printf("\n\n"); //New lines
	printf("Print array of integers, GetNighbors for vertex index %d: ", vertex1->index);
	printIntArray(nrOfNeighborsArray);
	
	//Prints struct vertices array
	printf("\n\n"); //New lines

	//printf("Prints all index, adresses and edges in the struct array\n");
	printArray(graph);

	//#####################BFS#############################
	char filename[] = { "graph_data/graph0to99.txt" };

	G* graph_ex2 = LoadGraph(filename);
	printArray(graph_ex2);
	nrOfVertices = getNumVertices(graph_ex2);

	BFS(graph_ex2, &vertex[0], &vertex[5]);

	//bool createqueue = TEST();


	//Free memory
	freeMemory(graph);
	freeMemory(graph_ex2);
	free(outNeighborsArray);
	free(inNeighborsArray);
	free(nrOfNeighborsArray);

	return 0;
}
