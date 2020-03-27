
#include <stddef.h>
#include <stdbool.h> 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"


G* LoadGraph(char* filename)
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

    //Reads every line and insert integers to graph
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
                if (i == 0) //First value is vertex index
                {
                    vertex_index1 = arr[i];
                    i++;
                }
                
                //Second value is edge value
                int vertex_index2 = arr[i];
                
                 addUndirectedEdge(&vertex[vertex_index1], &vertex[vertex_index2]);

                 //addDirectedEdge(&vertex[vertex_index1], &vertex[vertex_index2]);


                i++;
            }

            val = strtok(NULL, delims);
            read_n = (val == NULL) ? 0 : sscanf(val, "%d", &arr[0]);
            
            arr[0] = arr[1] = arr[2] = arr[3] = arr[4] = arr[5] = INT_MAX; //Resets array before next line
        }
    }
     
    //Delete black marked squares in graph
    int arrtodelete[] = {4,14,24,34,44,45,46,47,48,54,64,74,81,82,83,84};
    N* nodetodelete;

    for (int vertex_index= 0; vertex_index < n_graph; vertex_index++) //Cycle through every vertex
    {
        for (int delete_index = 0; delete_index < 16; delete_index++) //Cycle thorugh every value to delete
        {
            vertex[arrtodelete[delete_index]].head = NULL; //Setting black square vertex to NULL

            do //While loop if there is more than one edge with same index
            {
                //Searching for specific edge beloning to specific vertex
                nodetodelete = searchEdge(&vertex[vertex_index], arrtodelete[delete_index]);

                //Delete black edge/node from graph
                bool isDeleted = deleteNodeGraph(&vertex[vertex_index], nodetodelete);

            } while (nodetodelete != 0);

            
        }
    }
        
    //printArray(graph);
    fclose(filepoint);	//Close file
    return graph;
}

