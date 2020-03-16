#include "List.h"
#include <stddef.h>
#include <stdbool.h> 
#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

G* createGraph(int n)
{
	//Create graph (Pointer to vertex array)
		//Allocate memory for new list
		G* graph = (G*)malloc(sizeof(G));

		//Set n_size equall to n
		if (graph != NULL)
		{
			graph->n_vertices = n;
		}
		
		//Create vertex array
		V* vertex = (V*)calloc(n + 8, sizeof(V));

		//Make sure head of list is NULL before starting any operations
		if (vertex != NULL) {
			vertex->head = NULL;
		}

		//Save pointer to array in Graph source pointer
		if (graph!=NULL)
		{
			graph->source = vertex;
		}

		//Save index value in evey allocated memoryspace in array
		int i = 1;

		for (i = 0; i <= n; i++)
		{
			if(vertex != NULL){
				vertex[i].index = i;
			}
		}
		return graph;
}

int getNumVertices(G* graph) {

	V* vertex = graph->source;

	int i = 1;

	while (vertex[i].index != 0)
	{
		i++;
	}

	int nrOfVertices = i-1;

	return nrOfVertices;
}

int getNumEdges(G* graph)
{
	V* vertex = graph->source;

	int n = getNumVertices(graph);

	int i = 0;
	int edgeCounter = 0;

	for (i = 1; i < n; i++)
	{
		//Defining a temp varible
		N* temp = vertex[i].head;
		//Itterate until last node
		while (temp != NULL) {
			//Assign Next pointer of node to temp
			temp = temp->next;
			edgeCounter++;
		}

		
	}

	return edgeCounter;
}

int* getNeighbors(G* graph, V* vertex)
{
	return NULL;
}

int* getInNeighbors(G* graph, V* vertex)
{
	return NULL;
}

int* getOutNeighbors(G* graph, V* vertex)
{
	
	//Defining a temp varible
	N* temp = vertex->head;
	int counter = 0;

	//Check how many out going gedges
	while (temp != NULL) {
		//Assign Next pointer of node to temp
		temp = temp->next;
		counter++;
	}

	int n = counter;

	//Allocate array and save index in array
	int* arr = (int*)calloc(n + 8, sizeof(int));

	int i = 1;

	N* temp2 = vertex->head;

	while (temp2 != NULL) {
		//Assign Next pointer of node to temp
		

		if (arr != NULL)
		{
			arr[i] = temp2->data;
			temp2 = temp2->next;
			i++;
		}

	}

	return arr;
}

void addDirectedEdge(V* vertex1, V* vertex2)
{
	int index2 = vertex2->index;

	///* Print Messages */
	//printf("Printing lists...\n");
	////Prints the first list
	//printf("Vertex list inside function: ");
	//N* listprint = vertex1->head;
	//printlist(listprint);

	bool insertNode = insertEdge(vertex1, createNode(index2));

}

void addUndirectedEdge(V* vertex1, V* vertex2)
{
	int index1 = vertex1->index;
	int index2 = vertex2->index;
	

	///* Print Messages */
	//printf("Printing lists...\n");
	////Prints the first list
	//printf("Vertex list inside function: ");
	//N* listprint = vertex1->head;
	//printlist(listprint);

	bool testinsert = insertEdge(vertex1, createNode(index2));
	testinsert = insertEdge(vertex2, createNode(index1));

}

bool hasEdge(V* vertex1, V* vertex2)
{
	//int index1 = vertex1->index;
	int index2 = vertex2->index;

	N* foundEdge = searchEdge(vertex1, index2);

	if (foundEdge != NULL)
	{
		return true;
	}
	return false;
}



//##########################SUPPORT FUCTIONS###########################################

//Print array
G* printArray(G* graph) {

	printf("Prints all index and adresses in the struct array\n");

	int n = graph->n_vertices;

	V* vertex = graph->source;


	for (int i = 1; i <= n; i++)
	{
		int temp = vertex[i].index;

		printf("%d ", temp);
		printf("%p \n", vertex[i].head);
	}

	return graph;
}

//Print array of ints
void printIntArray(int* array) {

	printf("Print array of integers: ");

	int i = 1;

	while (array[i] != 0)
	{
		printf("%d ", array[i]);
		i++;
	}

}

//Insert edge/node in beginning of list
bool insertEdge(V* vertex, N* newNode) {
	if (vertex->head != NULL) {
		//Define next pointer of new node to head pointer
		newNode->next = vertex->head;
		//List head not NULL means we already have head
		if (vertex->head != NULL) {
			//Overwrite head prev with new node
			vertex->head->prev = newNode;
		}
		//Replace head with new node.
		vertex->head = newNode;
		//Should not point back.
		newNode->prev = NULL;
	}
	else {
		vertex->head = newNode;
	}
	//Check for success
	if (vertex->head == newNode) {
		return true;
	}
	else {
		return false;
	}
}

//Search List
N* searchEdge(V* vertex, int key) {
	//Defining a temp varible
	N* temp = vertex->head;
	printf("Searching for key: %d\n", key);
	//Itterate when key is not empty and temp is not the key
	while (temp != NULL && temp->data != key) {
		//Assign Next pointer of node to temp
		temp = temp->next;
	}
	//Return what you found
	if (temp != NULL) {
		if (temp->data == key) {
			printf("Found the key %d\n", temp->data);
			return temp;
		}
	}
	printf("Did not find the key \n");
	return NULL;
}


bool freeMemory(G* graph)
{
	V* vertex = graph->source;

	int n = getNumVertices(graph);

	int i = 0;
	int edgeCounter = 0;

	for (i = 1; i < n; i++)
	{
		//Defining a temp varible
		N* temp = vertex[i].head;
		//Itterate until last node
		while (temp != NULL) {
			//Assign Next pointer of node to temp
			temp = temp->next;
			
		}

		free(temp);
		

	}
	free(vertex);
	free(graph);
	
	return true;
}
