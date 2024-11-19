#include <stdio.h>

/* Retorna o fatorial de n */

unsigned long fatorial(unsigned long n) 
{
	unsigned long i, fat = 1;

  for(i = 2; i<=n; i++)
	 fat = fat * i;

	return (fat);
}

int main(void) 
{
	unsigned long n, f;

	printf("Digite n: ");
	scanf("%lu", &n);  
  	
	f = fatorial(n);
	printf("Resultado final = %lu\n", f);
 	
	return 0;
}
