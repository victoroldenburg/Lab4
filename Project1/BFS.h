#pragma once
#include "graph.h"

typedef struct queue {
    int length;
    int head;
    int tail;
} Q;

Q* createQueue();
void enqueue(Q*,V*);
V* dequeue(Q*);
int isEmptyQ(Q*);

//void display(Q* queue);
//void printQueue(Q* queue);

void BFS(G*,V*,V*);
