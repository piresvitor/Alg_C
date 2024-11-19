#include <stdio.h>

#define STR_LEN 1000

int count_spaces(const char s[]);


int main (void) 
{  
	char texto[STR_LEN+1];

	scanf("%[^\n]", texto);

	printf("%d espaços em branco.\n", count_spaces(texto));

	return 0;
}


int count_spaces(const char s[])
{
	int count = 0, i;

	for (i = 0; s[i] != '\0'; i++){
		if (s[i] == ' ') {
			count++;
		}
	}

	return count;
}