#include <stdio.h>
#include <stdlib.h>

void imprimeMatriz(int *m, int l, int c) 
{
	int i, j;
	/* escreve a matriz */
	for (i=0; i<l; i++) 
	{
		for (j=0; j<c; j++)
			printf("%d\t", *(m + (i * c) + j));
		printf("\n");
	}
}

int *leitura(int l, int c)
{
	int *m;
	int i, j;

	/* aloco espaço suficiente para a matriz l × c */
	m = (int *)malloc(l * c * sizeof(int));
	if (m == NULL) 
	{
		printf("Nao foi possivel alocar a matriz\n");
		exit(0);
	}
	
	/* carrego a matriz */
	for (i=0; i<l; i++)
		for (j=0; j<c; j++) 
		{
			printf("Entre m[%d][%d]: ", i, j);
			scanf("%d", (m + (i * c) + j));
		}
	
	return (m);
}

int main(void) 
{
	int *m; 
	int nlin, ncol;  
	int i, j; 

	/* peço o número de linhas e colunas */
	printf("Entre o numero de linhas e colunas: ");
	scanf("%d %d", &nlin, &ncol);

	/* leitura da matriz */
	m = leitura(nlin, ncol);

	/* imprimo a matriz */
	imprimeMatriz(m, nlin, ncol);

	/* desaloco a matriz */
	free(m);
}

