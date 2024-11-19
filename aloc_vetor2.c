#include<stdio.h>
#include<stdlib.h>

int *le_vetor(int n)
{
	int i, *v;
	v = (int *) malloc(n*sizeof(int));
	for (i=0; i<n; i++)
		scanf("%d", &v[i]);
	return v;
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

	v = le_vetor(n);
	imprime_vetor(v, n);

	printf("\n");

	free(v);

	return 0;
}
