#include "List.h"
#include <stddef.h> //Give NULL
#include <stdbool.h> //Give return values true/false

//Create list
L* createList() {
	L* list = (L*)malloc(sizeof(L));

	if (list != 0){
		list->ListA = NULL;
		list->ListB = NULL;
		return list;
	}
	exit("Failed: no list selected");
}

//Create Node
N* createNode(int key) {
	N* x = (N*)malloc(sizeof(N));

	if (x != 0) {
		x->data = key;
		x->next = NULL;
		x->prev = NULL;
		return x;
	}
	exit("Key is zero.");
}

//Check if empty
int isEmpty(L* head){
	//If the head is empty the list is empty.
	if (head == NULL); 
		return true; 
	return false;
}

//Insert to list begining
int insert(N* node_head, N* node_to_insert) {

	//We create our node with default structs
	createNode(node_to_insert); 

	//Run as long we have input values
	if (node_to_insert != NULL && node_head != NULL) { 
		//x.next<-L.head Our node to insert's next pointer, points to the first object in the list.
		node_to_insert->next = node_head; 

		//As long as the node head is not empty we continue
		if (node_head != NULL) { 
			//Our new node is pointed to the head's prevoius 
			node_head->prev = node_to_insert; 
		}
		//Our new node become our new head
		node_head = node_to_insert;
		//Set our new head previus to NULL
		node_to_insert->prev = NULL;
		//Our code was successfull
		return true;
	}
	return ("No input values");
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
