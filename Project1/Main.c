#include "List.h"
#include "Stack.h"
#include "Queue.h"
#include "graph.h"
#include <stddef.h>
#include <stdbool.h> 
#include <stdio.h>
#include <stdlib.h>

int main() {

	int n = 72;

	G* graph = createGraph(n);

	G* graphr = printArray(graph);

	int nrOfVertices = getNumVertices(graph);

	free(graph);

	return 0;
}
