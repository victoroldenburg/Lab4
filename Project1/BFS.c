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
					vertex[i].distance = INT_MAX - 1;
					vertex[i].parent = NULL;
				}
			}
			Enqueue(graph, vertex, vertex->index);
		}
	}


//enqueue graph
void Enqueue(G* graph, V* vertex, int source){
	int counter = 0;

	//int head = vertex->head->data; //head node data

	while (vertex[counter].index != INT_MAX){
		if (counter == graph->n_vertices){
			printf("Enqueue error!\n");
			return;
		}
		counter++;
	}
	vertex[counter].index = source;
}


//Dequeue graph
int Dequeue(G* graph, int* head){
	int output = INT_MAX;
	int counter = 0;

	if (head[0] == INT_MAX){
		printf("Dequeue error!\n");
		return INT_MAX;
	}
	else{
		output = head[counter];

		int i = 0;
		while (head[i] != INT_MAX){
			head[i] = head[i + 1];
			i++;
		}

		return output;
	}
}
