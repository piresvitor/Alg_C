#include <stdio.h>

int main(void) {

	FILE  *f;
	double d = 12.56;
	int i = 120;
	char ch = 'D';

	f = fopen ("teste.bin", "a+b");

	// testa abertura do arquivo
	if (f == NULL) {
		perror("teste.bin");
	return 0;
	}

	fwrite(&d, sizeof(double), 1, f);  // &d para poder pegar o numero na sua forma binaria, do msm jeito que esta na memoria
	fwrite(&i, sizeof(int), 1, f);
	fwrite(&ch, sizeof(char), 1, f);

	rewind(f); // "rebobina" cursor do arquivo, reposiciona o indicador de posicao do arquivo no inicio do arquivo

	// inicializo as variaveis
	d = 0.00;
	i = 0;
	ch = 'A';

	// leio as variaveis do arquivo
	fread(&d, sizeof(double), 1, f);
	fread(&i, sizeof(int), 1, f);
	fread(&ch, sizeof(char), 1, f);

	printf("%lf %d %c\n", d, i, ch);	

	fclose(f);

	return (0);
}
