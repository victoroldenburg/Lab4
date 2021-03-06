#include "graph.h"

#include <stddef.h>
#include <stdbool.h> 
#include <stdio.h>
#include <stdlib.h>

//####################MAIN FUNCTIONS#################################################
//Create Node
N* createNode(int key) {
	//Allocate memory for newNode
	N* x = (N*)malloc(sizeof(N));

	//Make sure all values for a new node is set
	if (x != NULL) {
		x->data = key;
		x->next = NULL;
		x->prev = NULL;
		return x;
	}
	return x;
}

G* createGraph(int n)
{
	//Create graph (Pointer to vertex array)
		//Allocate memory for new pointer
	G* graph = malloc(sizeof(G));

	if (graph != NULL)
	{
		graph->n_vertices = n;

		//graph->shortPath = malloc(n * sizeof(int));

	}

	//Create vertex array
	int size_t = n + 8;
	V* vertex = calloc(size_t, sizeof(V));

	if (vertex != NULL) {
		vertex->head = NULL; //Make sure head of list is NULL before starting any operations

		if (graph != NULL)
		{
			graph->source = vertex; //Save adress to the array in the Graph source pointer
		}
		//Save index value in evey allocated memoryspace in array
		int i = 0;

		for (i = 0; i < n; i++)
		{
			if (vertex != NULL) {
				vertex[i].index = i;
				//graph->vertex[i] = vertex[i]; //save every vertex in the graph for access (What does this line do? /victor)
			}
		}
		vertex[n].index = INT_MAX; //Ends array with INT_MAX value
	}
	return graph;
}

int getNumVertices(G* graph) {

	V* vertex = graph->source;

	int i = 0;
	int num = 0;
	while (vertex[i].index < 10000)
	{
		if (vertex[i].head != NULL) {
			num++;
		}
		i++;
	}
	int nrOfVertices = num;
	return nrOfVertices; //Return int number of vertices
}

int getNumEdges(G* graph)
{
	V* vertex = graph->source;

	int n = getNumVertices(graph);
	int i = 0;
	int edgeCounter = 0;

	for (i = 0; i < n; i++)
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
	return edgeCounter; //Return number of edges found in array connected to graph
}

int* getNeighbors(G* graph, V* vertex)
{
	int* inNeighborsArray = getInNeighbors(graph, vertex);
	int* outNeighborsArray = getOutNeighbors(graph, vertex);

	int nrOfInN = 0;
	int nrOfOutN = 0;

	while (inNeighborsArray[nrOfInN] != INT_MAX)
	{
		nrOfInN++;
	}
	while (outNeighborsArray[nrOfOutN] != INT_MAX)
	{
		nrOfOutN++;
	}
	int n = nrOfInN + nrOfOutN;

	//int* nrOfNeighborsArray = calloc(n+1, sizeof(int));
	int size_t = n + 1;
	int* nrOfNeighborsArray = calloc(size_t, sizeof(int));

	if (nrOfNeighborsArray != NULL)
	{
		int i = 0;

		for (i = 0; i < nrOfInN; i++)
		{
			if (sizeof(nrOfNeighborsArray[i]) >= sizeof(inNeighborsArray[i])) {

			nrOfNeighborsArray[i] = inNeighborsArray[i];
			}
		}

		i = 0;

		for (i = 0; i < nrOfOutN; i++)
		{
			nrOfNeighborsArray[i + nrOfInN] = outNeighborsArray[i];
		}
		nrOfNeighborsArray[nrOfInN + nrOfOutN] = INT_MAX;
		return nrOfNeighborsArray;
	}
	return false;
}

int* getInNeighbors(G* graph, V* vertex)
{
	int n = getNumVertices(graph);
	int i = 0;
	int j = 0;

	V* startVertex = graph->source;
	N* temp1 = startVertex->head;

	//int* arr2 = (int*)calloc(n + 8, sizeof(int));
	int size_t = n + 8;
	int* arr2 = calloc(size_t, sizeof(int));

	for (i = 1; i < n; i++)
	{
		N* temp2 = startVertex[i].head;

		//Itterate until last node
		while (temp2 != NULL) {
			//Assign Next pointer of node to temp
			if (vertex->index == temp2->data && arr2 != NULL)
			{
				arr2[j] = startVertex[i].index;
				j++;
			}
			temp2 = temp2->next;
		}
	}

	//Insert INT_MAX at the end of array
	if (arr2 != NULL)
	{
		arr2[j] = INT_MAX;
	}
	return arr2;
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
	//int* arr = (int*)calloc(n + 8, sizeof(int));
	int size_t = n + 8;
	int* arr = calloc(size_t, sizeof(int));

	int i = 0;
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
	//Insert INT_MAX at the end of array
	if (arr != NULL)
	{
		arr[i] = INT_MAX;
	}
	return arr;
}

void addDirectedEdge(V* vertex1, V* vertex2)
{
	int index2 = vertex2->index;
	insertEdge(vertex1, createNode(index2));
}

void addUndirectedEdge(V* vertex1, V* vertex2)
{
	int index1 = vertex1->index;
	int index2 = vertex2->index;

	N* nodeAlreadyExists1 = searchEdge(vertex1, index2);

	//Check if node already exists, if no, add edge
	if (nodeAlreadyExists1 == NULL)
	{
		insertEdge(vertex1, createNode(index2));
	}

	N* nodeAlreadyExists2 = searchEdge(vertex2, index1);

	//Check if node already exists, if no, add edge
	if (nodeAlreadyExists2 == NULL)
	{
		insertEdge(vertex2, createNode(index1));
	}
}

bool hasEdge(V* vertex1, V* vertex2)
{
	int index2 = vertex2->index;

	N* foundEdge = searchEdge(vertex1, index2); //Search for edges

	if (foundEdge != NULL)
	{
		return true;
	}
	return false;
}


//##########################SUPPORT FUCTIONS###########################################
//Print V* struct array
void printArray(G* graph) {

	int num = getNumVertices(graph); //Vertices not NULL
	int n = graph->n_vertices;

	printf("Printing vertices in Array not NULL out of %d: \n", num);

	V* vertex = graph->source;

	for (int i = 0; i < n; i++)
	{
		int temp = vertex[i].index;

		if (vertex[i].head != NULL) {
			printf("%d ", temp);
			printf("%p: ", vertex[i].head);

			//###################################################

			//Defining a temp varible
			N* temp2 = vertex[i].head;
			//Itterate until last node
			while (temp2 != NULL) {
				//Assign Next pointer of node to temp
				int edgeToNode = temp2->data;
				printf("%d ", edgeToNode);
				temp2 = temp2->next;
			}

			printf("\n");
			//##################################################
		}
	}
	printf("\n");
}

//Print array of ints
void printIntArray(int* array) {

	int i = 0;

	while (array[i] != INT_MAX)
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
	//printf("Searching for key: %d\n", key);
	//Itterate when key is not empty and temp is not the key
	while (temp != NULL && temp->data != key) {
		//Assign Next pointer of node to temp
		temp = temp->next;
	}
	//Return what you found
	if (temp != NULL) {
		if (temp->data == key) {
			//printf("Found the key %d\n", temp->data);
			return temp;
		}
	}
	//printf("Did not find the key \n");
	return NULL;
}

//Function to delete nodes in list
bool deleteNodeGraph(V* vertex, N* node) {
	if (node != NULL) {
		if (node->prev != NULL) {
			node->prev->next = node->next;
		}
		else {
			vertex->head = node->next;
		}

		if (node->next != NULL) {
			node->next->prev = node->prev;
		}
	}
	return true;
}

//Free allocated memory
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
	return true;
}
