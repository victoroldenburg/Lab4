#include "List.h"
#include <stddef.h> //Give NULL
#include <stdbool.h> //Give return values true/false

//Create list
L* createList() {
	L* x = (L*)malloc(sizeof(L));

	if (x != 0){
		x->list = NULL;
		x->next = NULL;
		x->prev = NULL;
		return x;
	}
	exit("Failed: list zero");
}

//Create Node
N* createNode(int key) {
	N* x = (N*)malloc(sizeof(N));

	if (x != 0) {
		x->key = key;
		x->next = NULL;
		x->prev = NULL;
		return x;
	}
	exit("Key is zero.");
}

//Check if empty
int isEmpty(L* head){
	if (head == 0);
		return true; 
	return false;
}

//Insert to list
int insert(N* list, N* node_to_insert) {
	node_to_insert->next = list;

	if (list != NULL) {
		list->prev = node_to_insert;
	}
	list = node_to_insert;
	node_to_insert->prev = NULL;
	return true;
}

//Search List
int search(L* x, int k) {			
	L* listHead = x;
	N*key = k;							

	while (x != NULL && x != k) {
		N*next = x;
	}
	return x;
}
