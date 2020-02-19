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

int isEmpty(L* head);

bool insert(L* list, N* newNode);

N* search(L* list, int key);

void printlist(N* print);

N* deleteNode(L* list, N* node);

N* maximum(L* list);

N* minimum(L* list);

N* succ(L* list, N* node);

N* pred(N* node);
