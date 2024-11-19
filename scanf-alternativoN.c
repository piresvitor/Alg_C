#include <stdio.h>

int main (void) 
{  
	char texto1[11];
	char texto2[11];

	/* Interrompe a leitura ao encontrar um \n ou apos 10 caracteres */
	scanf("%10[^\n]%*c",texto1);
	printf ("%s\n", texto1);


	// Outra opção é usar fgets e limitar o tamanho
	// fgets(texto2, 10, stdin);
	// printf ("%s\n", texto2);


	return 0;
}
