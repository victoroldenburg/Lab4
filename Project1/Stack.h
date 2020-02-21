#pragma once
#include "List.h"
#include <stdbool.h>

typedef struct Stack {
	struct Node* head;
} S;

S* createStackList();

N* popStack(S* stacklist);

N* pushStack(S* stacklist, N* node);
