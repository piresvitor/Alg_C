#include <stdio.h>
#include <stdlib.h>

/* !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */
/* Nao rode este programa. Ele pode travar a sua máquina... */

int main(void) 
{
  	char *p;

  	while (p != NULL)
		p = (char *) malloc(100*sizeof(char));
  
  	printf("Memoria esgotada.\n");

	free(p);

  	return 0;
}
