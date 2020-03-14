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
		graph->n_vertices = n;

		//Create vertex array
		V* vertex = (V*)malloc(n + 26, sizeof(V));




		//Make sure head of list is NULL before starting any operations
		if (graph != NULL) {
			graph->source = NULL;
		}
		//Save pointer to array in Graph head pointer
		graph->source = vertex;




	//Save index value in evey allocated memoryspace in array
		int i = 0;

		for (i = 1; i <= n; i++)
		{
			if(i != 0){
				printf("%d ", i);
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

	int temp = vertex[2].index;

	printf("%d", temp);




	//for (int i = 1; i < n; i++)
	//{

	//	

	//	printf("%p ", graph);
	//}

	printf("\n\n");

	return graph;
}
