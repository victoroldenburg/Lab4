#include "testBellmanFord.h"
#include "BellmanFord.h"

void RunTestBellmanFord()
{
	int numberOfVertices = 6;
	int numberOfEdges = 7;
	int vertexSource = 0; //Start vertex

	//Input data array
	int arrSource[] = {0, 0,2,3,1,4,  2}; //Edge from
	int arrDestin[] = {1, 2,3,5,4,5,  1}; //Edge to
	int arrWeight[] = {1,-1,4,8,2,7,-10}; //Weight of edge

	G* graph = createNewGraph(numberOfVertices, numberOfEdges);

	for (int i = 0; i < numberOfEdges; i++)
	{
		graph->edge[i].source = arrSource[i];
		graph->edge[i].destination = arrDestin[i];
		graph->edge[i].weight = arrWeight[i];
	}
	
	BellmanFord(graph, vertexSource);

}
