#include "Stack.h"
#include "List.h"
#include <stddef.h>
#include <stdbool.h> 
#include <stdio.h>
#include <stdlib.h>

S* createStackList() {
	//Allocate memory for new list
	S* list = (S*)malloc(sizeof(S));

	//Make sure head of list is NULL before starting any operations
	if (list != NULL) {
		list->head = NULL;
		return list;
	}
	return NULL;
}

//Push new item onto stack
N* pushStack(S* stacklist, N* node) {
	if (stacklist->head != NULL) {
		//Define next pointer of new node to head pointer
		node->next = stacklist->head;
		//stacklist head not NULL means we already have head
		if (stacklist->head != NULL) {
			//Overwrite head prev with new node
			stacklist->head->prev = node;
		}
		//Replace head with new node.
		stacklist->head = node;
		//Should not point back.
		node->prev = NULL;
	}
	else {
		//Define next pointer of new node to head pointer
		stacklist->head = node;
	}
	//Check for success
	if (stacklist->head == node) {
		return stacklist->head;
	}
	else {
		return NULL;
	}
}

//Pop first item on stack
N* popStack(S* stacklist) {
	if (stacklist != NULL) {
		N* tempNode = stacklist->head;
		if (tempNode != NULL) {
			stacklist->head = tempNode->next;
		}
		return stacklist->head;
	}
}
