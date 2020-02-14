#include "List.h"
#include <stddef.h> //Give NULL
#include <stdbool.h> //Give return values true/false
#include <stdio.h>
#include <stdlib.h>

//Create list
L* createList() {
	//Allocate memory for new list
	L* list = (L*)malloc(sizeof(L));

	//Make sure head of list is NULL before starting any operations
	if (list != NULL){
		list->head = NULL;
		return list;
	}
	return list;
}

//Create Node
N* createNode(int key) {
	//Allocate memory for newNode
	N* x = (N*)malloc(sizeof(N));

	//Make sure all values for a new node is set
	if (x != NULL) {
		x->data = key;
		x->next = NULL;
		x->prev = NULL;
		return x;
	}
	return x;
}

//Check if empty
int isEmpty(L* head){
	//If the head is empty the list is empty.
	if (head->head == NULL); 
		return true; 
	return false;
}

//Insert to list begining
bool insert(L* list, N* newNode){
	//Define next pointer of new node to head pointer
	newNode->next = list->head;
	//List head not NULL means we already have head
		if (list->head != NULL){
			//Overwrite head prev with new node
			list->head->prev = newNode;
		}
	//Replace head with new node.
	list->head = newNode;
	//Should not point back.
	newNode->prev = NULL; 

	//Check for success
	if (list->head == newNode) {
		return true;
	}else{
		return false;
	}
}

//Search List
N* search(L* list, int key) {	
	//Defining a temp varible
	N* temp = list->head;
	//Itterate when key is not empty and temp is not the key
	while (temp != NULL && temp->data != key) {
		//Assign Next pointer of node to temp
		temp = temp->next;
	}
	//Return what you found
	return temp;
}
