#include <stdio.h>

int main (void) 
{  
	char texto[10];

	/* Interrompe a leitura no primeiro espaço em branco */
	scanf ("%s", texto);
	printf ("%s\n", texto);

	return 0;
}
