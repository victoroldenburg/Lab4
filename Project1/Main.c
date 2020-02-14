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

		//Call Search key in list
		N* foundNode = search(list, key);

		//Print data from search
		printf("%d", foundNode->data);

		//Itterate key for testing for node with next key
		key++;
	}
	return 0;
}
	

