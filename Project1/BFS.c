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
            N* v = vertex->head;
            V* u = vertex;

            char WHITE = 0;
            char BLACK = 1;

			//int* distance = (int*)malloc(size * sizeof(int));

			if (u != NULL) {
				for (int i = 0; i < size; i++) {
					
                    u[i].color = WHITE;
					u[i].distance = INT_MAX - 1;
                    u[i].parent = NULL;
				}
			}
            Q* queue = createQueue();
			enqueue(queue, vertex);

            while (queue != NULL) {
                u = dequeue(queue);
                
                
            }

		}
	}
}

//enqueue graph
void enqueue(Q* queue, V* value) {
    V* queue[queue->tail] = value;

    if (queue->tail == queue->length) {
        queue->tail = 1;
    }
    else {
        queue->tail = queue->tail + 1;
    }
}

V* dequeue(Q* queue) {
    V* x = queue[queue->head];

    if (queue->head == queue->length) {
        queue->head = 1;
    } 
    else {
        queue->head = queue->head + 1;
    }
    return x;
}

Q* createQueue() {
    Q* queue = malloc(sizeof(Q));
    if (queue != NULL) {
        queue->head = -1;
        queue->tail = -1;
        queue->length = -1;
    }
    return queue;
}

int isEmptyQ(Q* queue) {
    if (queue->tail == -1)
        return 1;
    else
        return 0;
}
