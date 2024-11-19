#include <stdio.h>

int main (void) 
{  
	char texto[10];
	char texto2[10];

	/* Interrompe a leitura ao encontrar um \n */
	scanf("%[^\n]%*c",texto);
	printf ("%s\n", texto);

	scanf("%[^\n]%*c",texto2);
	printf ("%s\n", texto2);


	return 0;
}
