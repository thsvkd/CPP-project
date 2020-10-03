#include "node_controll.h"
#include "database_controll.h"

enum state
{
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

	char *tmp = ReadFile((char*)"database.txt");
	printf("read data : \n%s", tmp);

	Make_Linkedlist(tmp);

	/*InsertNode(head, (char *)"thsvkd1", 33);
	InsertNode(head, (char *)"thsvkd2", 76);
	InsertNode(head, (char *)"thsvkd3", 34);
	InsertNode(head, (char *)"thsvkd4", 12);
	InsertNode(head, (char *)"thsvkd5", 112);*/

	WriteFile((char*)"database.txt");

	PrintNode();
	Node *found_node = FindNode((char *)"thsvkd2");
	PrintNode(found_node);

	DeleteNode(found_node);

	PrintNode();
}