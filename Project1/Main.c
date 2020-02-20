#include "List.h"
#include <stdbool.h>
#include <stdio.h>

int main() {
	int key = 0;
	int size = 0;

	L* list1 = createList();
	L* list2 = createList();
	L* stackList = createList();
	L* queueList = createList();

	int input1[] = { 3, 1, 5, 10, 8, 7};
	int input2[] = { 5, 2, 9, 6, 1, 2};

	N* listprint = NULL;
	N* foundNode = NULL;
	N* deletedNode = NULL;
	N* nodeofKey = NULL;
	N* successorNode = NULL;
	N* predecessorNode = NULL;

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

/**Function calls**/
//Call Search key in list
	foundNode = search(list1, key);
	
//Delete node found in search
	deletedNode = deleteNode(list1, foundNode);

/* Print Messages */
//Printing key
	int printKey = printf("The key is %d \n", key);

//Prints the first list in order
	printf("List1: ");
	listprint = list1->head;
	printlist(listprint);

//Prints list2 in order
	printf("List2: ");
	listprint = list2->head;
	printlist(listprint);
	printKey;

//Return max/min value for L1 and L2
	N* maximumNode1 = maximum(list1);
	N* minimumNode1 = minimum(list1);
	N* maximumNode2 = maximum(list2);
	N* minimumNode2 = minimum(list2);
//Print Maximum and minimum of each list.
	printf("The maximum of List 1 is %d\n", maximumNode1->data);
	printf("The minimum of List 1 is %d\n", minimumNode1->data);
	printf("The maximum of List 2 is %d\n", maximumNode2->data);
	printf("The minimum of List 2 is %d\n", minimumNode2->data);

//Return succ and pred of key
//List 1
	key = 5;
	nodeofKey = search(list1, key);
	successorNode = successor(list1, nodeofKey);
	predecessorNode = predecessor(list1, nodeofKey);
//Print Successor and predecessor of 5 in List 1.
	int PSK = printPSK(nodeofKey, successorNode, predecessorNode);
//List 2
	key = 9;
	nodeofKey = search(list2, key);
	successorNode = successor(list2, nodeofKey);
	predecessorNode = predecessor(list2, nodeofKey);
//Print Successor and predecessor of 5 in List 1.
	PSK = printPSK(nodeofKey, successorNode, predecessorNode);
	
//Print: The key of the predecessor in List 2 of the maximum of List 1
	N* predL2maxL1 = predecessor(list2, maximum(list1));
	printf("The key of the predecessor in List 2 of the maximum of List 1 is %d\n", predL2maxL1->data);
//Print: The key of the predecessor in List 1 of the maximum of List 2
	N* predL1maxL2 = predecessor(list1, maximum(list2));
	printf("The key of the predecessor in List 1 of the maximum of List 2 is %d\n", predL1maxL2->data);

//###############################################STACK&QUEUE####################################################################
//Push and pop stack & prints
	printf("\n\n\n");
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
