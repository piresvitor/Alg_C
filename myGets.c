#include <stdio.h>

#define STR_LEN 10

int read_line(char str[], int n);


int main (void) 
{  
	char texto[STR_LEN+1];
	int texto_tam;

	texto_tam = read_line(texto, STR_LEN);
		
	printf ("%s tem %d caracteres.\n", texto, texto_tam);

	return 0;
}


int read_line(char str[], int n)
{
	int ch, i = 0; /* ch é int porque getchar retorna int */
	                 
	while ((ch = getchar()) != '\n'){  // getchar: lê um caractere do teclado
	 if (i < n) {
	    str[i] = ch;
	    i++;
	 }
	}

	str[i] = '\0';      /* fecha a string */
	
	return i;   /* num. caracteres de str */
}
