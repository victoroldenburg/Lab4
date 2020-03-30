#pragma once
#include "graph.h"
//#include "List.h"
#define SIZE 101

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

void display(Q*);

void printQueue(Q*);

void BFS(G*,V*);

void BFS_shortestpath(G*, V*, V*);

int isEmptyBFS(Q* q);

bool TEST();
