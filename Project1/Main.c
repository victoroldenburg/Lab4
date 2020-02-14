#include "List.h"
#include <stdbool.h>
#include <stdio.h>

int main() {
	int key = 5;
	
	//Create first list
	L* list = createList();

	//We create our node with default structs
	N* newNode = createNode(key);

	//Call Insert newNode in list
	bool insert(list, newNode);

	//Call Search key in list
	N* foundNode = search(list, key);

	printf("%p", foundNode);
	
	return 0;
}
	

