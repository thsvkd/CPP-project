#include "database_controll.h"
#define DEFAULT_TMP_SIZE 100

char* ReadFile(char *file_name)
{
	FILE* p = fopen(file_name, "r");
	char c;
	char* tmp = (char*)calloc(DEFAULT_TMP_SIZE, sizeof(char));
	int i = 0;

	while ((c = fgetc(p)) != EOF)
	{
		if (tmp[_msize(tmp) - 1] != 0)
			tmp = (char*)realloc(tmp, _msize(tmp) * 2);
		tmp[i++] = c;
	}

	return tmp;
}

void WriteFile(char* file_name)
{
	FILE* p = fopen(file_name, "w");
	char c;


}