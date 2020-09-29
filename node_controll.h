#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node_controll.h"

typedef struct _Node
{
	char name[20];
	int score;
	_Node *nextNode;
} Node;

extern Node* head, * tail;

Node *CreateNode(char *name, int score);
Node *FindNode(char *name);
Node *FindNode(int score);
Node *InsertNode(Node *cur_node, char *name, int score);
void DeleteNode(Node *cur_node);
void PrintNode();
void PrintNode(Node *cur_node);