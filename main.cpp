#include "node_controll.h"

enum state {
	RESET,
	FIND_NAME,
	FIND_SCORE,
	INSERT,
	DELETE,
	PRINT_ALL,
	PRINT_NODE
};

int main()
{
	head = CreateNode((char *)"head", 0);
	//tail = CreateNode((char*)"tail", 0);
	head->nextNode = tail;

	InsertNode(head, (char *)"thsvkd1", 56);
	InsertNode(head, (char *)"thsvkd2", 76);
	InsertNode(head, (char *)"thsvkd3", 34);
	InsertNode(head, (char *)"thsvkd4", 12);

	PrintNode();
	Node *found_node = FindNode((char *)"thsvkd2");
	PrintNode(found_node);

	DeleteNode(found_node);

	PrintNode();
}