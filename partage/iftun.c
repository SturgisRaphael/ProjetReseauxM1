#include "iftun.h"

void iftun(int src, int dest)
{
	char buffer[SIZE_BUFFER];
	if(src < 0 || dest < 0)
	{
		perror("Error: problem with files descriptors");
		exit(1);
	}
	int readed = read(src, buffer, SIZE_BUFFER);

	if(readed == -1)
	{
		perror("Error: read");
		exit(2);
	}

	write(dest, buffer, readed);
}
