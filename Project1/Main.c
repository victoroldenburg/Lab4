#include "testGraph.h"
#include "loadgraphfile.h"

int main() {

	//runTestGraph();

		char filename[] = { "graph_data/graph.txt" };


		int width = 0;
		int hight = 0;

		LoadGraph(filename, width, hight);


	return 0;
}
