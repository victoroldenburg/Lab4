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
			//N* v = source->head;
			V* s = source;
			V* u = graph->source;

			char WHITE = 0;
			char GRAY = 1;
			char BLACK = 2;

			if (u != NULL) {
				////for each vertex u in G.V -- {s}
				//for (int i = 0; i < size; i++) {

				//	u[i].color = WHITE;
				//	u[i].distance = INT_MAX - 1;
				//	u[i].parent = NULL;
				//}
				////s->color = GRAY;
				//s->distance = 0;
				//s->parent = NULL;

				graph->source->visited = 1; //Mark source node as visited
				enqueue(queue, s->index);

				int* arrPath = calloc(size, sizeof(int));

				int counter = 0;

				while (!isEmptyBFS(queue)) {

					printQueue(queue);
					int currentVertex = dequeue(queue);
					printf("Visited %d\n", currentVertex);
					

					//printf("CurrentVertex %d ", currentVertex);
					N* temp = graph->source[currentVertex].head;

					

					while (temp) {
						//printf("\nCounter%d \n", counter++);
						int adjVertex = temp->data;

						

						if (graph->source[adjVertex].visited == 0) {
							graph->source[adjVertex].visited = 1;
							arrPath[++counter] = graph->source[adjVertex].index;
							
							enqueue(queue, adjVertex);
						}
					
						if (temp->data == des->index)
						{
							printf("Congrats! You have reach your destination.");


							printf("\n");
							printf("A path, not the shortest!!!! ");
							for (int i = 0; i < counter; i++)
							{
								
								printf("%d ", arrPath[i]);
								
							}

							return;
							printf("\n");



						}
					temp = temp->next;
					
					}
				}
			}
		}
	}
}

int isEmptyBFS(Q* queue)
{
	if (queue->tail == -1)
		return 1;
	else
		return 0;
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
	if (isEmptyBFS(queue)) {
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

void printQueue(Q* queue) {
	int i = queue->head;

	if (isEmptyBFS(queue)) {
		printf("Queue is empty");
	}
	else {
		printf("\nQueue contains \n");
		for (i = queue->head; i < queue->tail + 1; i++) {
			printf("%d ", queue->length[i]);
		}
	}
}

bool TEST()
{
	Q* queue = createQueue();

	return true;
}