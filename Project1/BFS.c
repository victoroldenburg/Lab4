#include "BFS.h"
#include "graph.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void BFS(G* G, V* source, V* des) {

	if (G != NULL) {
		if (source != NULL) {
			//Init BFS
			int size = G->n_vertices;
			N* v = source->head;
			V* s = source;
			V* u = malloc(80 * sizeof(V));

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

			Q* queue = createQueue();
			enqueue(queue, s->index);

			while (queue != NULL) {
				//u = dequeue(queue);


			}
		}
	}
}

//enqueue graph in queue q
void enqueue(Q* q, int value) {
	if (q->tail != SIZE - 1) {
		if (q->head == -1) {
			q->head = 0;
		}
		q->tail++;
		q->length[q->tail] = value;
	}
}

int dequeue(Q* q) {
	int x;
	if (isEmptyQ(q)) {
		x = -1;
	}
	else {
		x = q->length[q->head];
		q->head++;
		if (q->head > q->tail) {
			q->head = q->tail = -1;
		}
	}
	return x;
}

Q* createQueue() {
	Q* queue = malloc(sizeof(Q));
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
