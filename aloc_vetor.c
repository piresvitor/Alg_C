#include<stdio.h>
#include<stdlib.h>

void le_vetor(int *v, int n)
{
	int i;
	for (i=0; i<n; i++)
		scanf("%d", &v[i]);
}


void imprime_vetor(int *v, int n)
{
	int i;
	for (i=0; i<n; i++)
		printf("%d ", v[i]);
}

int main(void)
{
	int n, *v;
	scanf("%d", &n);
	v = (int *) malloc(n*sizeof(int));
	le_vetor(v, n);
	imprime_vetor(v, n);
	printf("\n");
	free(v);
	return 0;
}
