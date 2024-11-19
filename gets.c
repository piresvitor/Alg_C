#include <stdio.h>

int main (void) 
{  
	char texto[10];

	gets (texto); /*warning: the `gets' function is dangerous and should not be used.*/

	printf ("%s\n", texto);

	return 0;
}
