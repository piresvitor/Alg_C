/*

   Exibe desenhos do tipo:

   *****
   ****
   ***
   **
   *
   
   Base é o número de asterisco da maior linha.
*/

#include <stdio.h>

int main() 
{
	int linha, qtdeLinha, base;

	printf("Base: ");
	scanf("%d", &base);

	linha = 0;  // linha
	while (linha < base) 
  {
    qtdeLinha = 0; // qtde na linha

    while (qtdeLinha < base - linha) 
    {
      printf ("*");
      qtdeLinha = qtdeLinha + 1;
    }

    printf ("\n");    
    linha = linha + 1;
  }
    return (0);
}

