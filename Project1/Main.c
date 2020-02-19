#include "List.h"
#include <stdbool.h>
#include <stdio.h>

int main() {
	int key = 5;

	//Create first list
	L* list = createList();
	L* list2 = createList();

	int input1[] = {3, 1, 5, 10, 8, 7};
	int input2[] = {5, 2, 9, 6, 1, 2};

	//Create first list
	while (key >= 0) {
		//We create our node with default structs
		int inputValue = input1[key];

		N* newNode = createNode(inputValue);

		//Runs the insert funtion and return true/false 
		bool testInsert = insert(list, newNode);

		//Itterate key for testing for node with next key
		key--;
	}
	
	//Create second list
	key = 5;
	while (key >= 0) {
		//We create our node with default structs
		int inputValue = input2[key];

		N* newNode = createNode(inputValue);

		//Runs the insert funtion and return true/false 
		bool testInsert = insert(list2, newNode);

		//Itterate key for testing for node with next key
		key--;
	}

	//Prints the first list in order
	printf("List1: ");
	N* listprint = list->head;
	printlist(listprint);

	//Prints list2 in order
	printf("List2: ");
	listprint = list2->head;
	printlist(listprint);

	//Call Search key in list
	key = 8;
	N* foundNode = search(list, key);

	//What if key only is in list number 2?

	//Print data from search
	if (foundNode != NULL) {
		printf("This is the value I found: %d\n", foundNode->data);
	}
	else {
		printf("Search returned NULL %p", foundNode);
	}
	
	//Delete node found in search
	if (foundNode != NULL)
	{
		N* deletedNode = deleteNode(list, foundNode);
	}
	//Print data deleted
	if (foundNode != NULL) {
		printf("This is the value I deleted: %d\n", foundNode->data);
	}
	else {
		printf("Delete returned NULL %p", foundNode);
	}

	//Prints list with deleted element
	printf("List_with_delete: ");
	listprint = list->head;
	printlist(listprint);

	//Return the pointer with maximum key value
	N* maximumKey = maximum(list);

	//Return pointer with minimum value
	N* minimumKey = minimum(list);

	//Return successor key
	N* sucessorKey = succ(list, foundNode);

	//Print data 
	if (sucessorKey != NULL) {
		printf("This is the successor: %d\n", sucessorKey->data);
	}
	else {
		printf("The key is the maximum value.");
	}

	//Return predecessor of key value
	N* predecessorKey = pred(foundNode);

	//Print data 
	if (predecessorKey != NULL) {
		printf("This is the successor: %d\n", predecessorKey->data);
	}
	else {
		printf("The key is the minimum value.");
	}

	return 0;
}
	

