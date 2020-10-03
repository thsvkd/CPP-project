#include "database_controll.h"

#define DEFAULT_TMP_SIZE 100

char *ReadFile(char *file_name)
{
	FILE *p = fopen(file_name, "r");
	char c;
	char *tmp = (char *)calloc(DEFAULT_TMP_SIZE, sizeof(char));
	int i = 0;

	while ((c = fgetc(p)) != EOF)
	{
		if (tmp[_msize(tmp) - 1] != 0)
			tmp = (char *)realloc(tmp, _msize(tmp) * 2);
		tmp[i++] = c;
	}

	fclose(p);

	for (i = 0; tmp[i] != '\n'; i++);

	return tmp + i + 1;
}

void WriteFile(char *file_name)
{
	FILE *p = fopen(file_name, "w");
	char str_out[DEFAULT_TMP_SIZE];

	Node *tmp = head;

	strcpy(str_out, "name, score\n");

	while (tmp->nextNode)
	{
		strcat(str_out, tmp->nextNode->name);
		strcat(str_out, ", ");
		char str_tmp[5] = { 0 };
		sprintf(str_tmp, "%d", tmp->nextNode->score);
		strcat(str_out, str_tmp);
		strcat(str_out, "\n");
		tmp = tmp->nextNode;
	}

	printf("write contents : \n%s", str_out);
	fputs(str_out, p);
	fclose(p);
}

void Make_Linkedlist(char *data)
{
	int brnum = 0;
	char* tmp;

	for (int i = 0; data[i] != NULL; i++)
	{
		if (data[i] == '\n')
			brnum++;
	}

	for (int i = 0; i < brnum; i++)
	{
		if (i == 0)
			tmp = strtok(data, ", ");
		else
			tmp = strtok(NULL, ", ");
		char name[DEFAULT_TMP_SIZE] = { 0 };
		strcpy(name, tmp);

		tmp = strtok(NULL, "\n");
		char score = atoi(tmp);
		InsertNode(head, (char*)name, score);
	}

	printf("load database success!!\n");
	PrintNode();
}