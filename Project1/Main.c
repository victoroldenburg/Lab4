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

		//Print true/false from insert
		//printf("%d", testInsert);

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

		//Print true/false from insert
		//printf("%d", testInsert);

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
	

	//Prints list with deleted element
	printf("List_with_delete: ");
	listprint = list->head;
	printlist(listprint);


	//Return the pointer with maximum key value
	N* maximumKey = maximum(list);

	//Return pointer with minimum value
	N* minimumKey = minimum(list);

	return 0;


}
	

