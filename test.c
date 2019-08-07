#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
	time_t now;
	time(&now);
	char *new = ctime(&now);
	printf("%s\n", new);
	free(new);
}
