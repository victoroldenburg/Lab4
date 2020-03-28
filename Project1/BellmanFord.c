
#include "BellmanFord.h"
#include <stddef.h>
#include <stdbool.h> 
#include <stdio.h>
#include <stdlib.h>

G* createNewGraph(int sizeVertices, int sizeEdges)
{
    //Allocate graph
    G* graph = (G*)malloc(sizeof(G));

    if (graph != NULL)
    {

        //Assign size to struct
        graph->n_vertices = sizeVertices;
        graph->n_edges = sizeEdges;

        //Allocating space for edges inside of G struct
        graph->edge = (E*)malloc(sizeEdges * sizeof(E));

        return graph;
    }
    return NULL;
}

void BellmanFord(G* graph, int source)
{
    int sizeVertecis = graph->n_vertices;
    int sizeEdges = graph->n_edges;
    
    //Allocate array to save distance and init all values to INT_MAX
    int* arrDistance = calloc(sizeVertecis, sizeof(int));

    if (arrDistance!=NULL)
    {
        for (int i = 0; i < sizeVertecis; i++)
        {
            arrDistance[i] = INT_MAX;
        }

        arrDistance[source] = 0; // Setting start/source vertex to 0

        //Relax V vertices and V-1 edges

        for (int i = 1; i <= sizeVertecis - 1; i++)
        {
            for (int j = 0; j < sizeEdges; j++)
            {
                int vertexSource = graph->edge[j].source;
                int vertexDestination = graph->edge[j].destination;
                int weight = graph->edge[j].weight;

                if (arrDistance[vertexSource] + weight < arrDistance[vertexDestination]) {
                    arrDistance[vertexDestination] = arrDistance[vertexSource] + weight;

                }
            }
        }

        //Check if negative cycles exists, if below functions finds a lower value, then negative cycles exists
        for (int j = 0; j < sizeEdges; j++)
        {
            int vertexSource = graph->edge[j].source;
            int vertexDestination = graph->edge[j].destination;
            int weight = graph->edge[j].weight;

            if (arrDistance[vertexSource] + weight < arrDistance[vertexDestination]) {
                printf("\nBeware! The graph contains negative cycles\n");
                return;
            }
        }
        PrintDistanceArr(arrDistance, sizeVertecis);
    }
}

void PrintDistanceArr(int* arrDistance, int sizeVertices)
{
        // Prints the result
        printf("\nVertex\tShortest distance from source to:\n");

        for (int i = 0; i < sizeVertices; ++i) {
            printf("%d \t\t %d\n", i, arrDistance[i]);
        }
}
