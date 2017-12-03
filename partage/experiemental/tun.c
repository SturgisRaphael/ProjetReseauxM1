#include "tun_alloc.h"

int main(int argc, char* argv[])
{
	if(argc != 2)
		perror("Erreur d'argument'");
	else
	{
		int fd = tun_alloc(argv[1]);
		fprintf(stderr,"%d\n",fd);
		while(1);
	}
}
