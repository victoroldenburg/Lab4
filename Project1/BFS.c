#include "BFS.h"
#include "graph.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void BFS(G* graph, V* source, V* des) {
	if (graph != NULL) {
		if (source != NULL) {
			//Init BFS
			Q* queue = createQueue();
			int size = graph->n_vertices;
			N* v = source->head;
			V* s = source;
			//V* u = (V*)malloc(80 * sizeof(V));
			V* u = graph->source;
			
			char WHITE = 0;
			char GRAY = 1;
			char BLACK = 2;

			//for each vertex u in G.V -- {s}
			if (u != NULL) {
				for (int i = 0; i < size; i++) {

					u[i].color = WHITE;
					u[i].distance = INT_MAX - 1;
					u[i].parent = NULL;
				}
			}

			s->color = GRAY;
			s->distance = 0;
			s->parent = NULL;

			enqueue(queue, s->index);

			//while (queue != NULL) {
			//	//u = dequeue(queue);


			//}
		}
	}
}

//enqueue graph in queue q
void enqueue(Q* queue, int value) {
	if (queue->tail != SIZE - 1) {
		if (queue->head == -1) {
			queue->head = 0;
		}
		queue->tail++;
		queue->length[queue->tail] = value;
	}
}

int dequeue(Q* queue) {
	int x;
	if (isEmptyQ(queue)) {
		x = -1;
	}
	else {
		x = queue->length[queue->head];
		queue->head++;
		if (queue->head > queue->tail) {
			queue->head = queue->tail = -1;
		}
	}
	return x;
}

Q* createQueue() {
	//Q* queue = malloc(sizeof(Q));
	Q* queue = (Q*)malloc(sizeof(Q));

	if (queue != NULL) {
		queue->head = -1;
		queue->tail = -1;
	}
	return queue;
}

int isEmptyQ(Q* queue) {
	if (queue->tail == -1)
		return 1;
	else
		return 0;
}

bool TEST()
{
	Q* queue = createQueue();

	return true;
}