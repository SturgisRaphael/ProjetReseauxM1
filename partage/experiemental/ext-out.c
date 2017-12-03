#include "extremite.h"

int main(int argc, char* argv[])
{
	if(argc != 2)
		perror("Erreur d'argument'");
	else
		ext_out(argv[1]);
}
