#include "BFS.h"
#include "graph.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void BFS(G* graph, V* v_source, V* sheep) {

	if (graph != NULL) {
		if (v_source != NULL) {
			int size = graph->n_vertices;
			V* vertex = v_source;

			int* distance = (int*)malloc(size * sizeof(int));

			if (distance != NULL) {
				for (int i = 0; i < size; i++) {
					
					vertex[i].distance = INT_MAX - 1;
					vertex[i].parent = NULL;
				}
			}
            Q* queue = createQueue();
			enqueue(queue, vertex->index);

		}
	}
}

//enqueue graph
void enqueue(Q* queue, int value) {
    if (queue->rear == SIZE - 1)
        printf("\nQueue is Full!!");
    else {
        if (queue->front == -1)
            queue->front = 0;
        queue->rear++;
        queue->items[queue->rear] = value;
    }
}

int dequeue(Q* queue) {
    int item;
    if (isEmptyQ(queue)) {
        printf("Queue is empty");
        item = -1;
    }
    else {
        item = queue->items[queue->front];
        queue->front++;
        if (queue->front > queue->rear) {
            printf("Resetting queue");
            queue->front = queue->rear = -1;
        }
    }
    return item;
}

Q* createQueue() {
    Q* queue = malloc(sizeof(Q));
    if (queue != NULL) {
        queue->front = -1;
        queue->rear = -1;
    }
    return queue;
}

int isEmptyQ(Q* queue) {
    if (queue->rear == -1)
        return 1;
    else
        return 0;
}
