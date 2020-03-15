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
		//Save pointer to array in Graph head pointer
		if (graph!=0)
		{
			graph->source = vertex;
		}
		

		//Save index value in evey allocated memoryspace in array
		int i = 0;

		for (i = 0; i <= n; i++)
		{
			if(vertex != NULL){
				vertex[i].index = i + 1;
				
				//Create a edgeList for every vertex
					//Allocate memory for new list
					E* edgeList = (E*)malloc(sizeof(E));

					//Make sure head of list is NULL before starting any operations
					if (edgeList != NULL) {
						vertex[i].head = edgeList;
						
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


	for (int i = 0; i <= n; i++)
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

	int i = 0;

	while (vertex != NULL && vertex[i].head != NULL) {

		i++;
		//Assign Next pointer of node to temp
		//temp = temp->next;
	}


	int nrOfVertices = i;

	printf("\n\n number of vertices %d ", nrOfVertices);

	return nrOfVertices;
}