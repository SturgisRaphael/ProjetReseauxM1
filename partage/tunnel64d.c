#include <stdio.h>
#include <stdlib.h>
#include "extremite.h"
#include "tun_alloc.h"

int main (int argc, char** argv){
	char tun[80];
	char inip[64];
	char inport[16];
	char options[80];
	char outip[64];
	char outport[16];

	if(argc != 2)
		perror("Erreur d'argument");

	//Recuperation donnee fichier
	FILE* fichier = NULL;
    fichier = fopen(argv[1], "r+");
    if (fichier != NULL)
    {
    	if(fscanf(fichier, "# interface tun\ntun=%s\n# adresse locale\ninip=%s\ninport=%s\noptions=%s\n# adresse distante\noutip=%s\noutport=%s", tun, inip, inport, options, outip, outport) <= 0)
    	{
    		perror("Erreur syntaxe");
    		fclose(fichier);
    		exit(2);
    	}
        fclose(fichier);
    }
    else
    {
    	perror("Impossible de lire le fichier");
    	exit(1);
    }
    
    //printf("# interface tun\ntun=%s\n# adresse locale\ninip=%s\ninport=%s\noptions=%s\n# adresse distante\noutip=%s\noutport=%s\n", tun, inip, inport, options, outip, outport);
	
	int fd = tun_alloc(tun);
	fprintf(stderr,"%d\n",fd);
	
	pid_t filsPID;

    filsPID = fork();

    if(filsPID < 0)
    {
    	perror("Echec fork\n");
        exit(3);
    }
	if(filsPID == 0) //Entree tunnel
	{
		sleep(10); //pour avoir le temps de le lancer sur la 2eme machine
		ext_in(inport, inip, fd);
		return 0;
	}
	
	ext_out(outport, fd);

	
	return 0;
}
