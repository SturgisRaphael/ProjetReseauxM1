#include <stdio.h>
#include <stdlib.h>
#include "extremite.h"
#include "tun_alloc.h"

int main (int argc, char** argv){
	if(argc != 3)
		perror("Erreur d'argument'");

	int fd = tun_alloc(argv[1]);
	fprintf(stderr,"%d\n",fd);
	
	if(!strcmp(argv[2], "ext-out"))
		ext_out("123", fd);
	else if(!strcmp(argv[2], "ext-in"))
		ext_in("123", argv[3], fd);
	else{
		while(1){
			iftun(fd, atoi(argv[2]));
		}
	}
	return 0;
}
