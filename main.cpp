#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Node
{
	char name[20];
	int score;
	_Node* nextNode;
} Node;

Node* CreateNode(char* name, int score);
Node* FindNode(char* name);
Node* FindNode(int score);
Node* InsertNode(Node* cur_node, char* name, int score);
void DeleteNode(Node* cur_node);
void PrintNode();

Node *head, *tail;

int main()
{
	head = CreateNode((char*)"head", 0);
	head->nextNode = tail;

	InsertNode(head, (char*)"thsvkd1", 56);
	InsertNode(head, (char*)"thsvkd2", 76);
	InsertNode(head, (char*)"thsvkd3", 34);
	InsertNode(head, (char*)"thsvkd4", 12);

	PrintNode();
	Node* found_node = FindNode((char*)"thsvkd2");
	printf("i found : %s, %d\n", found_node->name, found_node->score);

	DeleteNode(found_node);

	PrintNode();
}

Node* CreateNode(char* name, int score)
{
	Node* tmp;
	tmp = (Node*)malloc(sizeof(Node));
	strcpy(tmp->name, name);
	tmp->score = score;

	return tmp;
}

Node* FindNode(char* name)
{
	Node* tmp = head;

	while (tmp->nextNode)
	{
		if (!strcmp(tmp->nextNode->name, name))
			return tmp->nextNode;
		tmp = tmp->nextNode;
	}

	return tmp;
}

Node* FindNode(int score)
{
	Node* tmp = head;

	while (tmp->nextNode)
	{
		if (tmp->nextNode->score == score)
			return tmp->nextNode;
		tmp = tmp->nextNode;
	}

	return tmp;
}

Node* InsertNode(Node* cur_node, char* name, int score)
{
	Node* new_node;
	new_node = CreateNode(name, score);
	new_node->nextNode = cur_node->nextNode;
	cur_node->nextNode = new_node;

	return new_node;
}

void DeleteNode(Node* cur_node)
{
	Node* tmp;

	if (!cur_node->nextNode)
	{
		free(cur_node);
	}
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
	Node* tmp = head;

	while (tmp->nextNode)
	{
		printf("name : %s, score : %d\n", tmp->nextNode->name, tmp->nextNode->score);

		tmp = tmp->nextNode;
	}
}