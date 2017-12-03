#include "extremite.h"

int main(int argc, char* argv[])
{
	if(argc != 4)
		perror("Erreur d'argument'");
	else
		ext_in(argv[1], argv[2], atoi(argv[3]));
}
