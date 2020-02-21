#include "List.h"
#include <stddef.h>
#include <stdbool.h> 
#include <stdio.h>
#include <stdlib.h>

int main() {
	int key = 0;
	int size = 0;
//Doubly Linked List
	L* list1 = createList();
	L* list2 = createList();
//Stacks and queues
	L* stackList = createList();
	L* queueList = createList();

	int input1[] = { 3, 1, 5, 10, 8, 7 };	//3, 1, 5, 10, 8, 7
	int input2[] = { 5, 2, 9, 6, 1, 2 };	//5, 2, 9, 6, 1, 2 

//Create first list 
	size = sizeof(input1) / sizeof(input1[0]);
	for (int i = size - 1; i >= 0; i--) {
		//Runs the insert funtion and return true/false 
		bool insertNode = insert(list1, createNode(input1[i]));
	}

//Create second list 
	size = sizeof(input2) / sizeof(input2[0]);
	for (int i = size - 1; i >= 0; i--) {
		//Runs the insert funtion and return true/false 
		bool insertNode = insert(list2, createNode(input2[i]));
	}

/* Print Messages */

	printf("Printing lists...\n");
//Prints the first list
	printf("List 1: ");
	N* listprint = list1->head;
	printlist(listprint);
//Prints list
	printf("List 2: ");
	listprint = list2->head;
	printlist(listprint);

	printf("\nPrinting maximum and minimum values for each list...\n");
//Return max/min value for L1 and L2
//Print Maximum and minimum of each list.
	N* maxNode1 = maximum(list1);
	N* minNode1 = minimum(list1);
	if (maxNode1 != NULL && minNode1 != NULL) {
		printf("The maximum of List 1 is %d\n", maxNode1->data);
		printf("The minimum of List 1 is %d\n", minNode1->data);
	}
	else {
		printf("The list only value is 0.\n");
	}

	N* maxNode2 = maximum(list2);
	N* minNode2 = minimum(list2);
	if (maxNode2 != NULL && minNode2 != NULL) {
		printf("The maximum of List 2 is %d\n", maxNode2->data);
		printf("The minimum of List 2 is %d\n", minNode2->data);
	}
	else {
		printf("The list only value is 0.\n");
	}

	printf("\nPrinting successors and predecessors of keys...\n");
//Return succ and pred of key
//List 1
	key = 5;
	printf("Key: %d\n", key);

	N* foundNode = search(list1, key);
	if (foundNode != NULL) {
		N* successorNode = successor(list1, foundNode);
		N* predecessorNode = predecessor(list1, foundNode);
		//Print Successor and predecessor of key in List 1.
		void* PSK = printPSK(foundNode, successorNode, predecessorNode);
	}
	else {
		printf("This program cannot find key, %d, in list 1.\n", key);
	}
//List 2
	key = 9;
	printf("Key: %d\n", key);

	foundNode = search(list2, key);
	if (foundNode != NULL) {
		N* successorKey = successor(list2, foundNode);
		N* predecessorKey = predecessor(list2, foundNode);
		//Print Successor and predecessor of key in List 2.
		void* PSK = printPSK(foundNode, successorKey, predecessorKey);
	}
	else {
		printf("This program cannot find key, %d, in list 2.\n", key);
	}

	printf("\nPrinting the key of the predecessor in List 2 of the maximum of List 1...\n");
//Print: The key of the predecessor in List 2 of the maximum of List 1
	N* predL2maxL1 = predecessor(list2, maximum(list1));
	if (predL2maxL1 != NULL) {
		printf("The key of the predecessor in List 2 of the maximum of List 1 is %d\n", predL2maxL1->data);
	}

	printf("\nPrinting the key of the predecessor in List 1 of the maximum of List 2...\n");
//Print: The key of the predecessor in List 1 of the maximum of List 2
	N* predL1maxL2 = predecessor(list1, maximum(list2));
	if (predL1maxL2 != NULL) {
		printf("The key of the predecessor in List 1 of the maximum of List 2 is %d\n", predL1maxL2->data);
	}

//###############################################STACK&QUEUE####################################################################
	printf("\nPrinting Stacks 'n' Queues...\n");
//Push and pop stack & prints
	pushStack(stackList, 1);
	pushStack(stackList, 9);
	pushStack(stackList, 8);
	pushStack(stackList, 7);
	pushStack(stackList, 0);
	pushStack(stackList, 2);
	pushStack(stackList, 2);
	pushStack(stackList, 0);
	printf("The stack contains ");
	printlist(stackList->head);

	popStack(stackList);
	popStack(stackList);
	printf("After pop ");
	printlist(stackList->head);
	printf("\n\n");

//Push and pops Queue & prints
	pushQueue(queueList, 1);
	pushQueue(queueList, 9);
	pushQueue(queueList, 8);
	pushQueue(queueList, 7);
	pushQueue(queueList, 0);
	pushQueue(queueList, 2);
	pushQueue(queueList, 2);
	pushQueue(queueList, 0);
	printf("The queue contains ");
	printlist(queueList->head);

	popQueue(queueList);
	printf("After pop ");
	printlist(queueList->head);

	return 0;
}
