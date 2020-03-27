#include "BFS.h"
#include "graph.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void BFS(G* graph, V* start_node, V* end_node) {

	if (graph != NULL) {
			int size = graph->n_vertices;
			V* vertex = graph->source;

			int* distance = (int*)malloc(size * sizeof(int));

			if (distance != NULL) {
				for (int i = 0; i < size; i++) {
					vertex[i].distance = INT_MAX;
					vertex[i].parent = NULL;
				}
			}
			Enqueue(graph, vertex, vertex->index);

			int temp = Dequeue(graph, vertex);

		}
	}


//enqueue graph
void Enqueue(G* graph, V* vertex, int source){
	int counter = 0;

	//int head = vertex->head->data; //head node data

	while (vertex[counter].distance != INT_MAX){
		if (counter == graph->n_vertices){
			printf("Enqueue error!\n");
			return;
		}
		counter++;
	}
	vertex[counter].distance = source;
}


//Dequeue graph
int Dequeue(G* graph, V* vertex){
	int output = INT_MAX;

	if (vertex[0].distance == INT_MAX){
		printf("Dequeue error!\n");
		return INT_MAX;
	}
	else{
		
		output = vertex[0].distance;

		int i = 0;
		while (vertex[i].distance != INT_MAX){
			vertex[i].distance = vertex[i + 1].distance;
			i++;
		}

		
		return output;
	}
}
