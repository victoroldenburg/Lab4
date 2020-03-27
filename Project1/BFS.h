#pragma once
#include "graph.h"
#define SIZE 40

typedef struct Q {
    int length[SIZE];
    struct V* head;
    struct V* tail;
} Q;

Q* createQueue();
void enqueue(Q* queue, V*);
V* dequeue(Q* queue);
//void display(Q* queue);
int isEmptyQ(Q* queue);
//void printQueue(Q* queue);

void BFS(G* graph, V* source, V* sheep);
