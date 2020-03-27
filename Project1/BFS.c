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
            V* u = (V*)malloc(size * sizeof(V));

            char WHITE = 0;
            char GRAY = 1;
            char BLACK = 2;

			//int* distance = (int*)malloc(size * sizeof(int));

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
			enqueue(queue, v);

            while (queue != NULL) {
                u = dequeue(queue);
                
                
            }

		}
	}
}

//enqueue graph in queue q
void enqueue(Q* q, V* value) {
    if (q->tail == q->length) {
        q->tail = 1;
    }
    else {
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
        return 0;
    }
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
