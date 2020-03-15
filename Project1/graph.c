#include "Queue.h"
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

		if (graph != 0)
		{
			graph->n_vertices = n;
		}
		

		//Create vertex array
		V* vertex = (V*)calloc(n + 8, sizeof(V));


		//Make sure head of list is NULL before starting any operations
		if (graph != NULL) {
			graph->source = NULL;
		}
		//Save pointer to array in Graph source pointer
		if (graph!=0)
		{
			graph->source = vertex;
		}
		

		//Save index value in evey allocated memoryspace in array
		int i = 0;

		for (i = 0; i <= n; i++)
		{
			if(vertex != NULL){
				vertex[i].index = i;
				
				//Create a edgeList for every vertex
					//Allocate memory for new list
					E* edgeList = (E*)malloc(sizeof(E));


					//Make sure head of list is NULL before starting any operations
					if (vertex != NULL) {
						vertex[i].head = NULL;
					}
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

	while (vertex[i].head != NULL)
	{
		i++;
	}


	int nrOfVertices = i-1;

	printf("\n\n number of vertices %d ", nrOfVertices);

	return nrOfVertices;
}

void addDirectedEdge(V* vertex1, V* vertex2)
{
	//Create empty edgeNode
	E* x = (E*)malloc(sizeof(E));

	//Make sure all values for a new node is set
	if (x != NULL) {
		x->index = vertex2->index;
		x->next= NULL;
		x->prev = NULL;
	}

	//Insert new node in array
	bool insertedNode = insertEdgeNode(vertex1, x);

}

bool insertEdgeNode(V* vertex, E* newNode) {

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

