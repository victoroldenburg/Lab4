#include "BFS.h"
#include "graph.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void BFS(G* graph, V* source) {

	int size = graph->n_vertices;

	int* queue = (int*)malloc(size * sizeof(int));

	if (queue != NULL) {
		for (int i = 0; i < size; i++) {
			queue[i] = INT_MAX-1;
		}
	}
}