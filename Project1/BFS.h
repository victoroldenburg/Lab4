#pragma once
#include "graph.h"
#define SIZE 101

/* This file provide call to the functions in BFS.c */

//###########STRUCT##########

typedef struct queue {
    int length[SIZE];
    int head;
    int tail;
} Q;

//###########MAIN FUNCTIONS##########

//Form the queue
Q* createQueue();

//Add to queue
void enqueue(Q*, int);

//Remove from queue
int dequeue(Q*);

//Run BFS - mark vertext as visited
void BFS(G*, V*);

//Run Single Pair Shortest Path
void BFS_shortestpath(G*, V*, V*);

//###########SUPPORT FUNCTIONS##########

//Is queue empty?
int isEmptyBFS(Q*);

//Print Queue
void printQueue(Q*);

//Reset BFS - mark as NOT visited
void resetBFS(G*, V*);



//For loop BFS
void forloop(G*, V*, int);

//Add edges seperatly
void addEdges1(V*);
void addEdges2(V*);
