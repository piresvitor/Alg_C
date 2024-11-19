/* 
	Soma n parcelas informadas pelo usuario.
*/

#include <stdio.h>

int main() 
{
	int n;
	int soma, parcela;

	printf("Quantas parcelas? ");
	scanf("%d", &n);

	soma = 0;

	while (n > 0) 
  {
  		printf("Parcela a ser somada: ");
  		scanf("%d", &parcela);
  		soma = soma + parcela;
  		n = n - 1;
	}
	
  printf("Soma: %d\n", soma);

  return (0);
}
