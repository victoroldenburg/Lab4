#pragma once

typedef struct Node {
	int data; //int to key
	struct N* next; //Pointer to next node, next = 0 -> tail
	struct N* prev; //Pointer to prev node , prev = 0 -> head
	struct N* head;

} N;

typedef struct List {
	struct L* ListA; //The first List
	struct L* ListB; //The second List
} L;

int isEmpty(L* head);

int insert(N* list, N* node_to_insert);

int search(L* x, int k);

//Test