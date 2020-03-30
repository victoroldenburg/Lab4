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
void enqueue(Q*, int);

//Remove from queue
int dequeue(Q*);

//Is queue empty?
int isEmptyBFS(Q*);

void display(Q*);

void printQueue(Q*);

//Run BFS - mark vertext as visited
void BFS(G*,V*);

//Reset BFS - mark as NOT visited
void resetBFS(G*,V*);

void BFS_shortestpath(G*, V*, V*);

bool TEST();
