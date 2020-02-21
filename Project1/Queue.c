#include "Queue.h"
#include "List.h"
#include <stddef.h>
#include <stdbool.h> 
#include <stdio.h>
#include <stdlib.h>

Q* createQueueList() {
	//Allocate memory for new list
	Q* list = (Q*)malloc(sizeof(Q));

	//Make sure head of list is NULL before starting any operations
	if (list != NULL) {
		list->tail = NULL;
		list->head = NULL;
		return list;
	}
	return NULL;
}

//Prints the queue
void printlistQueue(N* print) {
	N* temp = print;

	if (temp->prev != NULL) {
		printlistQueue(temp->prev);
	}
	while (temp != NULL) {
		printf("%d ", print->data);
		temp = temp->next;
	}
}

bool enqueue(Q* queueList, N* node) {
	if (queueList->tail != NULL) {
		//Define next pointer of new node to head pointer
		N* temp = node;
		temp->prev = queueList->tail;
		//queueList head not NULL means we already have head
		if (queueList->tail != NULL) {
			//Overwrite head prev with new node
			queueList->tail = temp;
		}
	}
	else {
		//Define next pointer of new node to head pointer
		queueList->tail = node;
	}
	//Check for success
	if (queueList->tail == node) {
		return true;
	}
	else {
		return false;
	}
}

N* dequeue(Q* queueList)
{
	if (queueList != NULL) {
		N* tempNode = queueList->tail;
		if (tempNode != NULL) {
			queueList->tail = tempNode->prev;
		}
		return queueList->tail;
	}
	else {
		printf("List is NULL.\n");
		return NULL;
	}
}