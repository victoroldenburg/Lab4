#pragma once
#include "graph.h"
#define SIZE 40

typedef struct queue {
    int length[SIZE];
    int head;
    int tail;
} Q;

//Form the queue
Q* createQueue();

//Add to queue
void enqueue(Q*, int );

//Remove from queue
int dequeue(Q*);

//Is queue empty?
int isEmptyQ(Q*);

//void display(Q* queue);
//void printQueue(Q* queue);

void BFS(G*,V*,V*);

bool TEST();
