#ifndef __NODE_H
#define __NODE_H

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct _Node {
	char data;
	struct _Node *Left;
	struct _Node *Right;
}Node;

Node *HeadNode, *EndNode;

#endif
