#pragma once
#include <stdbool.h>

/* This file provide call to the functions for List.c */

typedef struct Node {
	int data; //int to key
	struct Node* next; //Pointer to next node, next = 0 -> tail
	struct Node* prev; //Pointer to prev node , prev = 0 -> head
} N;

typedef struct List {
	struct Node* head; //List head
	struct Node* tail; //Queue tail
	int data;
} L;

L* createList();

N* createNode(int key);

bool isEmpty(L* head);

bool insert(L* list, N* newNode);

N* search(L* list, int key);

N* deleteNode(L* list, N* node);

N* maximum(L* list);

N* minimum(L* list);

N* successor(L* list, N* node);

N* predecessor(L* list, N* node);

void printlist(N* print);

void* printPSK(N* node, N* succ, N* pred);
