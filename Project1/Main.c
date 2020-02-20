#include "List.h"
#include <stdbool.h>
#include <stdio.h>

int main() {
	int key = 0;
	int size = 0;

	//Create first list
	L* list = createList();
	L* list2 = createList();

	int input1[] = { 3, 1, 5, 10, 8, 7, 9, 12};
	int input2[] = { 5, 2, 9, 6, 1, 11, 7, 15};

	//Create first list in order of array
	size = sizeof(input1) / sizeof(input1[0]);

	printf("List 1 created: ");
	for (int i = size - 1; i >= 0; i--) {
		//Runs the insert funtion and return true/false 
		bool insertNode = insert(list, createNode(input1[i]));

		//Print true/false
		if (insertNode != false) {
			printf("Node %d true. ", input1[i]);
		}
		else {
			printf("Node %d false. ", input1[i]);
		}
	}printf("\n");

	//Create second list reverse array
	size = sizeof(input2) / sizeof(input2[0]);

	printf("List 2 created: ");
	for (int i = 0; i < size; i++) {
		//Runs the insert funtion and return true/false 
		bool insertNode = insert(list2, createNode(input2[i]));

		//Print true/false
		if (insertNode != false) {
			printf("Node %d true. ", input2[i]);
		}
		else {
			printf("Node %d false. ", input2[i]);
		}
	}printf("\n");

	//Prints the first list in order
	printf("List1: ");
	N* listprint = list->head;
	printlist(listprint);

	//Prints list2 in order
	printf("List2: ");
	listprint = list2->head;
	printlist(listprint);

	//Call Search key in list
	printf("The key is: %d \n", key);
	N* foundNode = search(list, key);

	//Print data from search
	if (foundNode != NULL) {
		printf("I found: %d\n", foundNode->data);
	}
	else {
		printf("Search returned NULL! \n");
	}
	
	//Delete node found in search
	if (foundNode != NULL){
		N* deletedNode = deleteNode(list, foundNode);
	}
	//Print data deleted
	if (foundNode != NULL) {
		printf("This is the value I deleted: %d\n", foundNode->data);
	}
	else {
		printf("Delete returned NULL \n");
	}

	//Prints list with deleted element
	printf("List_with_delete: ");
	listprint = list->head;
	printlist(listprint);

	//Return the pointer with maximum key value
	N* maximumNode = maximum(list);
		printf("This is the maximum in List1: %d\n", maximumNode->data);

	//Return pointer with minimum value
	N* minimumNode = minimum(list);
		printf("This is the minimum in List1: %d\n", minimumNode->data);

	//Return successor key
	N* sucessorNode = succ(list, foundNode);

	//Print data 
	if (sucessorNode != NULL && foundNode != NULL) {
		printf("The successor of %d is %d.\n", foundNode->data, sucessorNode->data);
	}
	else {
		printf("The successor is NULL.\n");
	}

	//Return predecessor of key value
	N* predecessorNode = pred(list, foundNode);

	//Print data 
	if (predecessorNode != NULL && foundNode != NULL) {
		printf("The predecessor of %d is %d.\n", foundNode->data, predecessorNode->data);
	}
	else {
		printf("The predecessor is NULL.\n");
	}

	return 0;
}
	

