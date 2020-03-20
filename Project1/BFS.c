#include "BFS.h"
#include "graph.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void BFS(G* graph, V* v_source) {

	int size = graph->n_vertices;

	V* vertex = graph->vertex;

	int* distance = (int*)malloc(size * sizeof(int));

	if (distance != NULL) {
		for (int i = 0; i < size; i++) {
			vertex = vertex[i];
			vertex->distance = INT_MAX-1;
		}
	}
}