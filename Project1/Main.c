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
	int maximumKey1 = maximum(list1);
	int minimumKey1 = minimum(list1);
	int maximumKey2 = maximum(list2);
	int minimumKey2 = minimum(list2);
//Print Maximum and minimum of each list.
	printf("The maximum of List 1 is %d\n", maximumKey1);
	printf("The minimum of List 1 is %d\n", minimumKey1);
	printf("The maximum of List 2 is %d\n", maximumKey2);
	printf("The minimum of List 2 is %d\n", minimumKey2);

	printf("\nPrinting successors and predecessors of keys...\n");
//Return succ and pred of key
//List 1
	key = 5;
	printf("Key: %d\n", key);

	int newKey = search(list1, key);
	if (newKey != 0) {
		int successorKey = successor(list1, newKey);
		int predecessorKey = predecessor(list1, newKey);
		//Print Successor and predecessor of key in List 1.
		int PSK = printPSK(newKey, successorKey, predecessorKey);
	}
	else {
		printf("This program cannot find key, %d, in list 1.\n", key);
	}
//List 2
	key = 9;
	printf("Key: %d\n", key);

	newKey = search(list2, key);
	if (newKey != 0) {
		int successorKey = successor(list2, newKey);
		int predecessorKey = predecessor(list2, newKey);
		//Print Successor and predecessor of key in List 2.
		int PSK = printPSK(newKey, successorKey, predecessorKey);
	}
	else {
		printf("This program cannot find key, %d, in list 2.\n", key);
	}

	printf("\nPrinting the key of the predecessor in List 2 of the maximum of List 1...\n");
//Print: The key of the predecessor in List 2 of the maximum of List 1
	int predL2maxL1 = predecessor(list2, maximum(list1));
	if (predL2maxL1 != 0) {
		printf("The key of the predecessor in List 2 of the maximum of List 1 is %d\n", predL2maxL1);
	}
	else {
		printf("That key, %d, does not have a predecessor in list 2.\n", maximum(list1));
	}

	printf("\nPrinting the key of the predecessor in List 1 of the maximum of List 2...\n");
//Print: The key of the predecessor in List 1 of the maximum of List 2
	int predL1maxL2 = predecessor(list1, maximum(list2));
	if (predL1maxL2 != 0) {
		printf("The key of the predecessor in List 1 of the maximum of List 2 is %d\n", predL1maxL2);
	}
	else {
		printf("That key, %d, does not have a predecessor in list 1.\n", maximum(list2));
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
