#include<stdio.h>
#include<stdlib.h>
int main ()
{
	size_t len, getr;
	char *buffer = NULL;
	while (1)
	{
		printf("#cisfun$");
		getr = getline(&buffer, &len, stdin);
		if (getr != -1)
		{
			printf("%s", buffer);
		}
		else
		{
			break;
		}
	}
	free(buffer);
	return (0);
}
