#pragma once
#include "graph.h"
#define SIZE 40

typedef struct Q {
    int items[SIZE];
    int front;
    int rear;
} Q;

Q* createQueue();
void enqueue(Q* queue, int);
int dequeue(Q* queue);
//void display(Q* queue);
int isEmptyQ(Q* queue);
//void printQueue(Q* queue);

void BFS(G* graph, V* source, V* sheep);
