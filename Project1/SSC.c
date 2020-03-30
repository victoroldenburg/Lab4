#include "BFS.h"
#include "graph.h"
#include <stdio.h>

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
	addDirectedEdge(&vertex[33], &vertex[76]); //0
	addDirectedEdge(&vertex[33], &vertex[22]);

	addDirectedEdge(&vertex[42], &vertex[33]); //1
	addDirectedEdge(&vertex[22], &vertex[42]); //2
	addDirectedEdge(&vertex[76], &vertex[35]); //3
	addDirectedEdge(&vertex[35], &vertex[62]); //4
	addDirectedEdge(&vertex[62], &vertex[76]); //5

	int num = getNumVertices(graph_ex3);

	printArray(graph_ex3);

	for (int i = 1; i <= num; i++){

		printf("%d", vertex2->head->data);
		int temp = vertex[i].index;

		//Defining a temp varible
		N* temp2 = vertex[i].head;
		//Itterate until last node
		while (temp2) {

			BFS(graph_ex3, &vertex[i]);

		}
	}

	////##########TEST 1###################################

	//printf("First vertex can reach all nodes:\n");
	//BFS(graph_ex3_forward, vertex1);
	//printf("\n");
	//BFS(graph_ex3_backward, vertex1_back);
	//printf("\n");

	////##########TEST 2###################################
	//BFS(graph_ex3_forward, vertex2);
	//printf("\n");
	//BFS(graph_ex3_backward, vertex2_back);
	//printf("\n");

	////##########TEST 3###################################
	//BFS(graph_ex3_forward, vertex3);
	//printf("\n");
	//BFS(graph_ex3_backward, vertex3_back);
	//printf("\n");

	////##########TEST 4###################################
	//BFS(graph_ex3_forward, vertex4);
	//printf("\n");
	//BFS(graph_ex3_backward, vertex4_back);
	//printf("\n");

	////##########TEST 5###################################
	//BFS(graph_ex3_forward, vertex5);
	//printf("\n");
	//BFS(graph_ex3_backward, vertex5_back);
	//printf("\n");

	////##########TEST 6###################################
	//BFS(graph_ex3_forward, vertex6);
	//printf("\n");
	//BFS(graph_ex3_backward, vertex6_back);
	//printf("\n");

	//#####################Free Memory############################
	freeMemory(graph_ex3);
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