#pragma once
#include "graph.h"
#define SIZE 40

typedef struct queue {
    int length[SIZE];
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
