#pragma once
#include "List.h"
#include <stdbool.h>

typedef struct Queue {
	struct Node* head;
	struct Node* tail;
} Q;

Q* createQueueList();

N* enqueue(Q* queueList, N* node);

N* dequeue(Q* queueList);

void printlistQueue(N* print);
