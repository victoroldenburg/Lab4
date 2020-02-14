#include "List.h"
#include <stddef.h> //Give NULL
#include <stdbool.h> //Give return values true/false
#include <stdio.h>
#include <stdlib.h>

//Create list
L* createList() {
	L* list = (L*)malloc(sizeof(L));

	if (list != NULL){
		list->head = NULL;
		return list;
	}
	return list;
}

//Create Node
N* createNode(int key) {
	N* x = (N*)malloc(sizeof(N));

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
bool insert(L* list, N* newNode) {
	if (list == NULL || newNode == NULL) {
		if (isEmpty) {
			list->head = newNode;
			newNode->prev = NULL;
			newNode->next = NULL;
			return true;
		}
	else 
		newNode->next = list->head;
		list->head->prev = newNode;
		list->head = newNode;
		newNode->prev = NULL;
		return true;
	}
	return false;
}

//Search List
N* search(L* list, int key) {	
	//Defining a temp varible
	N* temp = list->head;
	//Itterate when key is not empty and temp is not the key
	while (temp->data != key && temp != NULL) {
		//Assign Next pointer of node to temp
		temp = temp->next;
	}
	//Return what you found
	return temp;
}
