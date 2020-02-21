#pragma once
#include <stdbool.h>

typedef struct Node {
	int data; //int to key
	struct Node* next; //Pointer to next node, next = 0 -> tail
	struct Node* prev; //Pointer to prev node , prev = 0 -> head
} N;

typedef struct List {
	struct Node* head; //List head
} L;

L* createList();

N* createNode(int key);

bool isEmpty(L* head);

bool insert(L* list, N* newNode);

void printlist(N* print);

int search(L* list, int key);

N* deleteNode(L* list, N* node);

int maximum(L* list);

int minimum(L* list);

int successor(L* list, int key);

int predecessor(L* list, int key);

int printPSK(int key, int succ, int pred);

//###############################################STACK&QUEUE####################################################################
void pushStack(L* stacklist, int dataValue);

void popStack(L* stacklist);

void pushQueue(L* queueList, int dataValue);

void popQueue(L* queueList);

bool insertLast(L* list, int dataValue);