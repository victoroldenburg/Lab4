#include "Queue.h"
#include "List.h"
#include <stddef.h>
#include <stdbool.h> 
#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

void createGraph(int n)
{
	//Create graph (Pointer to vertex array)
		//Allocate memory for new list
		G* graph = (G*)malloc(sizeof(G));

		//Make sure head of list is NULL before starting any operations
		if (graph != NULL) {
			graph->head = NULL;
		}

	//Create vertex array
		V* vertex = (V*)malloc(n, sizeof(V));

	//Save pointer to array in Graph head pointer
		graph->head = vertex;

	//Save index value in evey allocated memoryspace in array
		int i = 0;

		for (i = 1; i <= n; i++)
		{
			if(i != 0){
				printf("%d ", i);
			}
			
		}


}
