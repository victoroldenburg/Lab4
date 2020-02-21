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
	//If the head is empty the list is empty.
	if (list->head == NULL);
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
	if (list->head == newNode){
		return true;
	}else{
		return false;
	}
}

//Search List
int search(L* list, int key) {
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
			return temp->data;
		}
	}
	return 0;
}

//Prints the whole list
void printlist(N* print){
	N* temp = print;
	while (temp != NULL){
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

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
		free(node);
	}
	return NULL;
}

int maximum(L* list){
	//Defining a temp varible
	N* temp = list->head;
	int prtMaxValue = 0;

	if (list != NULL) {
		//Sets maxvalue to the first nodes data
		int currentmaxvalue = list->head->data;

		do {
			//Checks if new temp data value is lager then previous
			if (currentmaxvalue < temp->data) {
				currentmaxvalue = temp->data;
				prtMaxValue = temp->data;
			}

			//Assign Next pointer of node to temp
			temp = temp->next;
		} while (temp != NULL);
		return prtMaxValue;
	}
	return 0;
}

int minimum(L* list){
	//Defining a temp varible
	N* temp = list->head;
	int prtMinValue = 0;

	if (list != NULL) {
		//Sets maxvalue to the first nodes data
		int currentminvalue = list->head->data;

		do {
			//Checks if new temp data value is lager then previous
			if (currentminvalue > temp->data) {
				currentminvalue = temp->data;
				prtMinValue = temp->data;
			}

			//Assign Next pointer of node to temp
			temp = temp->next;
		} while (temp != NULL);
		return prtMinValue;
	}
	return 0;
}

int successor(L* list, int key) {
	N* temp = list->head;
	int succKey = maximum(list);

	if (key == 0 || key == succKey || succKey == 0) {
		return 0;
	}

	while (temp != NULL) {
		if (temp->data < succKey && temp->data > key) {
			succKey = temp->data;
		}
		temp = temp->next;
	}
	return succKey;
}

int predecessor(L* list, int key) {
	N* temp = list->head;
	int predKey = minimum(list);

	if (key == 0 || key == predKey || predKey == 0) {
		return 0;
	}

	while (temp != NULL) {
		if (temp->data > predKey && temp->data < key) {
			predKey = temp->data;
		}
		temp = temp->next;
	}
	return predKey;
}

int printPSK(int key, int succ, int pred) {
	if (key != 0) {
		if (succ != 0 && pred != 0) {
			printf("The key %d has the predecessor %d and successor %d.", key, pred, succ);
		}
		else if (succ != 0) {
			printf("The key %d has no predecessor and successor %d.", key, succ);
		}
		else {
			printf("The key %d has the predecessor %d, but no successor.", key, pred);
		}
		printf("\n");
		return true;
	}return 0;
}

//###############################################STACK&QUEUE####################################################################
void pushStack(L* stacklist, int dataValue)
{
	bool insertNode = insert(stacklist, createNode(dataValue));
}

void popStack(L* stacklist)
{
	deleteNode(stacklist, stacklist->head);
}

void pushQueue(L* queueList, int dataValue)
{
	insertLast(queueList, dataValue);
}

void popQueue(L* queueList)
{
	deleteNode(queueList, queueList->head);
}

bool insertLast(L* list, int dataValue)
{
	N* newNode = createNode(dataValue);

	if (list->head == NULL)
	{
		list->head = newNode;
		return true;
	}
	N* temp = list->head;

	while (temp->next != NULL)
	{
		temp = temp->next;
	}

	if (newNode != NULL)
	{
		temp->next = newNode;
		newNode->prev = temp;

		return true;
	}
	return false;
}
