#include "testGraph.h"
#include "loadgraphfile.h"
#include "testBellmanFord.h"

int main() {

	runTestGraph();

	RunTestBellmanFord();

	runEx3SCC();

	return 0;
}
