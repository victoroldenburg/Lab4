#include "BFS.h"
#include "graph.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void BFS_shortestpath(G* graph, V* source, V* des) {
	if (graph != NULL) {
		if (source != NULL) {
			
			//Init BFS
			Q* queue = createQueue();
			int size = graph->n_vertices;
			V* s = source;
			V* u = graph->source;
			int destination = des->index;
			int start_source = source->index;

			if (u != NULL) {
				
				//Standard BFS:
				graph->source->visited = 1; //Mark source node as visited
				enqueue(queue, s->index); 

				while (!isEmptyBFS(queue)) {
					printQueue(queue);
					int currentVertex = dequeue(queue);

					N* temp = graph->source[currentVertex].head;
					
					while (temp) {
						int adjVertex = temp->data;
						
						if (graph->source[adjVertex].visited == 0) {
							graph->source[adjVertex].visited = 1;
							graph->source[adjVertex].path = currentVertex; //Saving the parent node in all adjNodes when encountered the first time
														
							enqueue(queue, adjVertex);
						}
					
						if (temp->data == des->index) //Stop when reaching destination node
						{
							printf("\nCongrats! You have reach your destination.\n");

							//Printing shortest path, starting from destination node and traversal the saved path
							int* arrPath = calloc(size, sizeof(int));

							for (int i = 1; i < size; i++)
							{
								arrPath[0] = -1;
								arrPath[i] = INT_MAX;
							}

							int step = graph->source[destination].index;
							
							arrPath[0] = step;

							int i = 1;
							int numSteps = 0;

							while (graph->source[step].path != start_source)
							{
								    arrPath[i] = graph->source[step].path;
									i++;
									step = graph->source[step].path;
									numSteps++;
							}

							printf("From vertex %d, the shortest path is: ", start_source);

							for (int i = numSteps; i >= 0 ; i--)
							{
							printf("%d ", arrPath[i]);
							}
																					
							return;
							
						}
					 temp = temp->next;
					
					}
				}
			}
		}
	}
}

void BFS(G* graph, V* source) {
	
	int size = graph->n_vertices;
	
	V* u = graph->source;

	for (int i = 0; i < size; i++)
	{
		if (graph->source[i].head != NULL && graph->source[i].visited == 0)
		{
			V* s = &graph->source[i];

			if (graph != NULL) {
				if (source != NULL) {

					//Init BFS
					Q* queue = createQueue();
					
					int* arrSCC = calloc(size, sizeof(int));

					for (int i = 1; i < size; i++)
					{
						arrSCC[0] = -1;
					}


					if (u != NULL) {
						s->visited = 1; //Mark source node as visited
						enqueue(queue, s->index);
						int counter = 1;
						arrSCC[0] = s->index;

						while (!isEmptyBFS(queue)) {
							int currentVertex = dequeue(queue);
							N* temp = graph->source[currentVertex].head;

							while (temp) {
								int adjVertex = temp->data;

								if (graph->source[adjVertex].visited == 0) {
									graph->source[adjVertex].visited = 1;
									
									arrSCC[counter++] = graph->source[adjVertex].index;
								
									enqueue(queue, adjVertex);
								}
								temp = temp->next;
							}
						}

						printf("\n\nSCC exists for vertices: ");
						for (int i = 0; i < counter; i++)
						{
							
							printf("%d ",arrSCC[i]);
						}

					}
				}
			}
		}
	}
}

void BFS_orginal(G* graph, V* source) {

	if (graph != NULL) {
		if (source != NULL) {

			//Init BFS
			Q* queue = createQueue();
			int size = graph->n_vertices;
			V* s = source;
			V* u = graph->source;

			if (u != NULL) {
				graph->source->visited = 1; //Mark source node as visited
				enqueue(queue, s->index);

				while (!isEmptyBFS(queue)) {
					int currentVertex = dequeue(queue);
					N* temp = graph->source[currentVertex].head;

					while (temp) {
						int adjVertex = temp->data;

						if (graph->source[adjVertex].visited == 0) {
							graph->source[adjVertex].visited = 1;
							printf("%d ", graph->source[adjVertex].index);
							enqueue(queue, adjVertex);
						}
						temp = temp->next;
					}
				}
			}
		}
	}
}


void resetBFS(G* graph, V* source) {
	if (graph != NULL) {
		if (source != NULL) {
			//Init BFS
			Q* queue = createQueue();
			int size = graph->n_vertices;
			V* s = source;
			V* u = graph->source;

			if (u != NULL) {
				graph->source->visited = 0; //Mark source node as NOT visited
				enqueue(queue, s->index);

				while (!isEmptyBFS(queue)) {
					int currentVertex = dequeue(queue);
					N* temp = graph->source[currentVertex].head;

					while (temp) {
						int adjVertex = temp->data;

						if (graph->source[adjVertex].visited == 1) {
							graph->source[adjVertex].visited = 0;
							enqueue(queue, adjVertex);
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
		//printf("\nQueue contains \n");
		for (i = queue->head; i < queue->tail + 1; i++) {
			//printf("%d ", queue->length[i]);
		}
	}
}

bool TEST()
{
	Q* queue = createQueue();

	return true;
}