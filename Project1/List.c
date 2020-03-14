#include "List.h"
#include <stddef.h>
#include <stdbool.h> 
#include <stdio.h>
#include <stdlib.h>

//Create list
L* createList(){
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
N* createNode(int key){
	//Allocate memory for newNode
	N* x = (N*)malloc(sizeof(N));

	//Make sure all values for a new node is set
	if (x != NULL){
		x->data = key;
		x->next = NULL;
		x->prev = NULL;
		return x;
	}
	return x;
}

//Check if empty
bool isEmpty(L* list){
	if (list != NULL) {
		//If the head is empty the list is empty.
		if (list->head == NULL) {

			printf("List is empty...\n");
			return true;
		}
		return false;
	}
	else {
		printf("List is NULL.\n");
		return true;
	}
}

//Insert to list begining
bool insert(L* list, N* newNode){
	if (list->head != NULL) {
		//Define next pointer of new node to head pointer
		newNode->next = list->head;
		//List head not NULL means we already have head
		if (list->head != NULL) {
			//Overwrite head prev with new node
			list->head->prev = newNode;
		}
		//Replace head with new node.
		list->head = newNode;
		//Should not point back.
		newNode->prev = NULL;
	}
	else {
		list->head = newNode;
	}
	//Check for success
	if (list->head == newNode){
		return true;
	}else{
		return false;
	}
}

//Search List
N* search(L* list, int key) {
	//Defining a temp varible
	N* temp = list->head;
	printf("Searching for key: %d\n", key);
	//Itterate when key is not empty and temp is not the key
	while (temp != NULL && temp->data != key) {
		//Assign Next pointer of node to temp
		temp = temp->next;
	}
	//Return what you found
	if (temp != NULL) {
		if (temp->data == key) {
			printf("Found the key %d\n", temp->data);
			return temp;
		}
	}
	return NULL;
}

//Prints the whole list
void printlist(N* print){
	if (print != NULL) {
		N* temp = print;
		if (temp->next != NULL) {
			while (temp != NULL) {
				printf("%d ", temp->data);
				temp = temp->next;
			}
		}
		printf("\n");
	}
}

//Function to delete nodes in list
N* deleteNode(L* list, N* node){
	if (node != NULL) {
		if (node->prev != NULL) {
			node->prev->next = node->next;
		}else{
			list->head = node->next;
		}

		if (node->next != NULL) {
			node->next->prev = node->prev;
		}
		return node;
	}
	return NULL;
}

N* maximum(L* list){
	//Defining a temp varible
	N* temp = list->head;
	N* prtMaxValue = NULL;

	if (temp->data != 0) {
		//Sets maxvalue to the first nodes data
		int currentmaxvalue = list->head->data;

		do {
			//Checks if new temp data value is lager then previous
			if (currentmaxvalue < temp->data) {
				currentmaxvalue = temp->data;
				prtMaxValue = temp;
			}

			//Assign Next pointer of node to temp
			temp = temp->next;
		} while (temp != NULL);
		return prtMaxValue;
	}
	return NULL;
}

N* minimum(L* list){
	//Defining a temp varible
	N* temp = list->head;
	N* prtMinValue = NULL;

	if (list != NULL) {
		//Sets maxvalue to the first nodes data
		int currentminvalue = list->head->data;

		do {
			//Checks if new temp data value is lager then previous
			if (currentminvalue > temp->data) {
				currentminvalue = temp->data;
				prtMinValue = temp;
			}

			//Assign Next pointer of node to temp
			temp = temp->next;
		} while (temp != NULL);
		return prtMinValue;
	}
	return NULL;
}

N* successor(L* list, N* node) {
	N* temp = list->head;
	N* succNode = maximum(list);

	if (node == NULL || node == succNode || succNode == NULL) {
		return NULL;
	}

	while (temp != NULL) {
		if (temp->data < succNode->data && temp->data > node->data) {
			succNode = temp;
		}
		temp = temp->next;
	}
	return succNode;
}

N* predecessor(L* list, N* node) {
	N* temp = list->head;
	N* predNode = minimum(list);

	if (node == NULL) {
		printf("That key 0 does not have a predecessor in that list.\n");
		return NULL;
	}

	if (predNode == NULL) {
		printf("That key %d does not have a predecessor in that list.\n", node->data);
		return NULL;
	}

	while (temp != NULL) {
		if (temp->data > predNode->data && temp->data < node->data) {
			predNode = temp;
		}
		temp = temp->next;
	}
	return predNode;
}

void* printPSK(N* node, N* succ, N* pred) {
	if (node != NULL) {
		if (succ != NULL && pred != NULL) {
			printf("The key %d has the predecessor %d and successor %d.", node->data, pred->data, succ->data);
		}
		else if (succ != NULL) {
			printf("The key %d has no predecessor and successor %d.", node->data, succ->data);
		}
		else {
			printf("The key %d has the predecessor %d, but no successor.", node->data, pred->data);
		}
		printf("\n");
	}
	return 0;
}
