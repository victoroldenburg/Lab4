#include "List.h"
#include <stdbool.h>
#include <stdio.h>

int main() {
	int key = 0;

	//Create first list
	L* list = createList();

	while (key < 5) {
		//We create our node with default structs
		N* newNode = createNode(key);

		//Runs the insert funtion and return true/false 
		bool testInsert = insert(list, newNode);

		//Print true/false from insert
		printf("%d", testInsert);

		//Itterate key for testing for node with next key
		key++;
	}

	key = 5;

	//Call Search key in list
	N* foundNode = search(list, key);

	//Print data from search
	if (foundNode != NULL) {
		printf("%d", foundNode->data);
	}
	else {
		printf("%p", foundNode);
	}


	return 0;
}
	

