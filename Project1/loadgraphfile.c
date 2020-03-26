
#include <stddef.h>
#include <stdbool.h> 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"


void LoadGraph(char* filename)
{
    //Create new graph
    int n_graph = 100; //number of vertices to create
    G* graph = createGraph(n_graph); //create graph w/o any edges
    V* vertex = graph->source;


    //Load data from graph_.txt and insert to created graph
    FILE* filepoint;

    errno_t err = fopen_s(&filepoint, filename, "r");

    if (filepoint == NULL) {
        printf("Error: file does not exist. \n");
        exit(1);
    }

    int read_n;
    int arr[6] = {INT_MAX,INT_MAX ,INT_MAX ,INT_MAX ,INT_MAX ,INT_MAX };
    char line[60];
    char* val;
    char delims[] = "\n";

    while (fgets(line, 60, filepoint) != NULL)
    {
        val = strtok(line, delims);
        read_n = sscanf(val, "%d %d %d %d %d %d", &arr[0], &arr[1], &arr[2], &arr[3], &arr[4], &arr[5]);
        int i = 0;
        while (read_n > 0)
        {
            //Test print function
            //printf("Read [%d %d %d %d %d %d]\n", arr[0], arr[1], arr[2], arr[3], arr[4], arr[5]);
            
            int vertex_index1 = 0;
            //Insert values to graph
            while (arr[i] != INT_MAX)
            {
                if (i == 0)
                {
                    vertex_index1 = arr[i];
                    i++;
                }
                
                int vertex_index2 = arr[i];
                addDirectedEdge(&vertex[vertex_index1], &vertex[vertex_index2]);
                i++;
            }

            val = strtok(NULL, delims);
            read_n = (val == NULL) ? 0 : sscanf(val, "%d", &arr[0]);
            
            arr[0] = arr[1] = arr[2] = arr[3] = arr[4] = arr[5] = INT_MAX;
        }
    }
     
    //Delete black marked squares in graph
    int arrtodelete[8] = {};

    //Searching for specific edge beloning to specific vertex
    N* nodetodelete = searchEdge(vertex[i], arrtodelete[j]);

    //Delete edge-node from graph
    bool isDeleted = deleteNode(vertex[i], nodetodelete);


    printArray(graph);
    fclose(filepoint);	//Close file
    return graph;
}

