#include "BFS.h"
#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

void runEx3SCC() {
	printf("\n##############RUNNING SCC##############\n");

	//Update n
	int n = 99;

	//Create a new graph
	G* graph_ex3 = createGraph(n);

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
	addEdges1(vertex);

	printArray(graph_ex3);

	forloop(graph_ex3, vertex, n);

	//#####################Free Memory############################
	freeMemory(graph_ex3);
}

void forloop(G* graph_ex3, V* vertex, int n) {
	for (int i = 0; i < n; i++) {

		int temp = vertex[i].index;

		if (vertex[i].head != NULL) {
			//Defining a temp varible
			N* temp2 = vertex[i].head;

			//Itterate until last node
			while (temp2 != NULL) {

				printf("BFS visited from vertex %d:\n", i);
				BFS(graph_ex3, &vertex[i]);

				printf("\n");

				reverseVertex(graph_ex3, &vertex[i]);

				resetBFS(graph_ex3, &vertex[i]);
				
				temp2 = temp2->next;
			}
		}
	}
}

void addEdges1(V* vertex) {
	//Create new edges
	addDirectedEdge(&vertex[33], &vertex[76]); //0
	addDirectedEdge(&vertex[33], &vertex[22]);

	addDirectedEdge(&vertex[42], &vertex[33]); //1
	addDirectedEdge(&vertex[22], &vertex[42]); //2
	addDirectedEdge(&vertex[76], &vertex[35]); //3
	addDirectedEdge(&vertex[35], &vertex[62]); //4
	addDirectedEdge(&vertex[62], &vertex[76]); //5
}

void addEdges2(V* vertex) {
	//Create new edges
	addDirectedEdge(&vertex[76], &vertex[33]); 
	addDirectedEdge(&vertex[76], &vertex[62]);
	addDirectedEdge(&vertex[22], &vertex[33]);
	addDirectedEdge(&vertex[33], &vertex[42]);
	addDirectedEdge(&vertex[35], &vertex[76]);
	addDirectedEdge(&vertex[42], &vertex[22]);
	addDirectedEdge(&vertex[62], &vertex[35]);
}

void reverseVertex(G* graph, V* vertex) {
	
	vertex->visited = 1;

	int temp = vertex->index;

	int* E = getNeighbors(graph, vertex);

	int numOfEdges = getNumEdgesV(vertex);
	printf("Num of edges for vertex %d: %d\n", vertex->index, numOfEdges);

	int* N = {0};

	if (N != NULL) {
		for (int i = 0; i < numOfEdges; i++) {

			V* q = &vertex[i];

			if (q->visited != 1) {

				N[i] = q;

			}
		}
	}
}

//reverse direction of e
//end if
//end for
//
//for each vertex q in N,
//reverseVertex(q)
//end function

int getNumEdgesV(V* vertex) {
	int edgeCounter = 0;

	//Defining a temp varible
	N* temp = vertex->head;
	//Itterate until last node
	while (temp != NULL) {
		//Assign Next pointer of node to temp
		temp = temp->next;
		edgeCounter++;
	}

	return edgeCounter; //Return number of edges found in array connected to graph
}
