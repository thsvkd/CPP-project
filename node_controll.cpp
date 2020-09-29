#include "node_controll.h"

Node* head, * tail;

Node *CreateNode(char *name, int score)
{
	Node *tmp;
	tmp = (Node *)malloc(sizeof(Node));
	strcpy(tmp->name, name);
	tmp->score = score;

	return tmp;
}

Node *FindNode(char *name)
{
	Node *tmp = head;

	while (tmp->nextNode)
	{
		if (!strcmp(tmp->nextNode->name, name))
			return tmp->nextNode;
		tmp = tmp->nextNode;
	}

	return tmp;
}

Node *FindNode(int score)
{
	Node *tmp = head;

	while (tmp->nextNode)
	{
		if (tmp->nextNode->score == score)
			return tmp->nextNode;
		tmp = tmp->nextNode;
	}

	return tmp;
}

Node *InsertNode(Node *cur_node, char *name, int score)
{
	Node *new_node;
	new_node = CreateNode(name, score);
	new_node->nextNode = cur_node->nextNode;
	cur_node->nextNode = new_node;

	return new_node;
}

void DeleteNode(Node *cur_node)
{
	Node *tmp;

	if (!cur_node->nextNode)
		free(cur_node);
	else
	{
		tmp = head;

		while (tmp->nextNode)
		{
			if (tmp->nextNode == cur_node)
			{
				tmp->nextNode = cur_node->nextNode;
				free(cur_node);
				return;
			}

			tmp = tmp->nextNode;
		}
	}
}

void PrintNode()
{
	Node *tmp = head;

	printf("============current list==============\n");
	while (tmp->nextNode)
	{
		printf("name : %s, score : %d\n", tmp->nextNode->name, tmp->nextNode->score);

		tmp = tmp->nextNode;
	}
	printf("======================================\n");
}

void PrintNode(Node* cur_node)
{
	printf("Founded node -> name : %s, score : %d\n", cur_node->name, cur_node->score);
}