#pragma once
#include "graph.h"

void BFS(G* graph, V* source, V* sheep);

void Enqueue(G* graph, V* head, int index);

int Dequeue(G* graph, int* index);