#include "List.h"
#include <stddef.h>
#include <stdbool.h> 
#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

G* createGraph(int n)
{
	//Create graph (Pointer to vertex array)
		//Allocate memory for new list
		G* graph = (G*)malloc(sizeof(G));

		//Set n_size equall to n
		if (graph != NULL)
		{
			graph->n_vertices = n;
		}
		
		//Create vertex array
		V* vertex = (V*)calloc(n + 8, sizeof(V));

		//Make sure head of list is NULL before starting any operations
		if (vertex != NULL) {
			vertex->head = NULL;
		}

		//Save pointer to array in Graph source pointer
		if (graph!=NULL)
		{
			graph->source = vertex;
		}

		//Save index value in evey allocated memoryspace in array
		int i = 1;

		for (i = 0; i <= n; i++)
		{
			if(vertex != NULL){
				vertex[i].index = i;
			}
		}
		return graph;
}

//Print array
G* printArray(G* graph) {

	printf("\n\n");

	int n = graph->n_vertices;

	V* vertex = graph->source;


	for (int i = 0; i <= n+1; i++)
	{
		int temp = vertex[i].index;

		printf("%d ", temp);
		printf("%p \n", vertex[i].head);
	}

	return graph;
}

//Return number of vertices in array
int getNumVertices(G* graph) {

	V* vertex = graph->source;

	int i = 1;

	while (vertex[i].index != 0)
	{
		i++;
	}

	int nrOfVertices = i-1;

	printf("Number of vertices %d ", nrOfVertices);
	printf("\n\n");

	return nrOfVertices;
}

void addDirectedEdge(V* vertex1, V* vertex2)
{
	int index2 = vertex2->index;

	///* Print Messages */
	//printf("Printing lists...\n");
	////Prints the first list
	//printf("Vertex list inside function: ");
	//N* listprint = vertex1->head;
	//printlist(listprint);

	bool insertNode = insertEdge(vertex1, createNode(index2));

}

void addUndirectedEdge(V* vertex1, V* vertex2)
{
	int index1 = vertex1->index;
	int index2 = vertex2->index;
	

	///* Print Messages */
	//printf("Printing lists...\n");
	////Prints the first list
	//printf("Vertex list inside function: ");
	//N* listprint = vertex1->head;
	//printlist(listprint);

	bool testinsert = insertEdge(vertex1, createNode(index2));
	testinsert = insertEdge(vertex2, createNode(index1));

}

//Insert to list begining
bool insertEdge(V* vertex, N* newNode) {
	if (vertex->head != NULL) {
		//Define next pointer of new node to head pointer
		newNode->next = vertex->head;
		//List head not NULL means we already have head
		if (vertex->head != NULL) {
			//Overwrite head prev with new node
			vertex->head->prev = newNode;
		}
		//Replace head with new node.
		vertex->head = newNode;
		//Should not point back.
		newNode->prev = NULL;
	}
	else {
		vertex->head = newNode;
	}
	//Check for success
	if (vertex->head == newNode) {
		return true;
	}
	else {
		return false;
	}
}

