#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	char *texto = NULL;
	int n;
	printf("Digite o tamanho do texto: ");
	scanf("%d", &n);

	texto = (char *) malloc(n*sizeof(char));
	if (texto == NULL)
	{
		printf("Memoria nao alocada");
		exit(1);
	}

	printf("0x%x ", texto);
	printf("%s\n", texto);	

	// ERRADO fazer:  texto = "ALG 2";
	// pois o computador alocara novo espaco para armazenar a cadeia "ALG 2" e atribuira o endereco deste
     // novo espaco para texto.Com isso o endereco alocado inicialmente para texto ficara perdido.
	// CORRETO eh:
	sprintf(texto, "ALG 2"); // coloca a cadeia "ALG 2" na memoria apontada por texto

	printf("0x%x ", texto);
	printf("%s\n", texto);
	printf("\n", texto);

	free(texto);	
	return 0;
}
