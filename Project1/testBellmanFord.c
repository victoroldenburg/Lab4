#include "testBellmanFord.h"
#include "BellmanFord.h"

void RunTestBellmanFord()
{
	printf("\n##############RUNNING BELLMAN-FORD ALGORITHM##############\n");

	//Input data
	//int arrSource[] = {0, 0,2,3,1,4,2,  1}; //Edge from
	//int arrDestin[] = {1, 2,3,5,4,5,1,  0}; //Edge to
	//int arrWeight[] = {3,-1,4,8,2,7,3,-11}; //Weight of edge

	int arrSource[] = { 0, 0,2,3,1,4,2}; //Edge from
	int arrDestin[] = { 1, 2,3,5,4,5,1}; //Edge to
	int arrWeight[] = { 3,-1,4,8,2,7,3}; //Weight of edge

	int numberOfVertices = 6; //Number of vertices
	int vertexSource = 0; //Start vertex


	int numberOfEdges = sizeof(arrSource) / sizeof(arrSource[0]);
	

	G* graph = createNewGraph(numberOfVertices, numberOfEdges);

	for (int i = 0; i < numberOfEdges; i++)
	{
		graph->edge[i].source = arrSource[i];
		graph->edge[i].destination = arrDestin[i];
		graph->edge[i].weight = arrWeight[i];
	}
	
	BellmanFord(graph, vertexSource);

}
