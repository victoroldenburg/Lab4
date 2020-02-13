#pragma once

typedef struct Node {
	int key; //int to key
	struct N*next; //Pointer to next node, next = 0 -> tail
	struct N*prev; //Pointer to prev node , prev = 0 -> head

} N;

typedef struct List {
	struct L* list; //Pointer to the first entity in list
	struct L* next; //Nex data in list
	struct L* prev; //Prev data in list
} L;

int isEmpty(L* head);

int insert(N* list, N* node_to_insert);

int search(L* x, int k);

//Test