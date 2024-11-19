#include <stdio.h>

int main(void)
{
  	int t = 2;
	int *p = &t;
	
	printf("Valor de t.........: %d\n", t);
	printf("Endereco de t (HEX): %p\n", &t);
	printf("Endereco de t (DEC): %u\n", &t);
	printf("Valor de p (HEX)...: %p\n", p);
	printf("Valor de p (DEC)...: %u\n", p);
	printf("Valor de *p........: %d\n", *p);
	printf("\n");

  	return (0);
}
