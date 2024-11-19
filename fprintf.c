/*
 * Cópia de arquivo para outro arquivo.
 */
#include<stdio.h>

int main(void) 
{
  	FILE  *fr, *fw;
  	int num;
  
  	fr = fopen ("teste.txt", "r");   // vamos ler dados deste arquivo
  	fw = fopen ("saida.txt", "w");   // vamos escrever dados neste arquivo

  	if (fr == NULL) 
	{
    		perror("teste.txt");
    		return 1;
  	}

  	if (fw == NULL) 
	{
    		perror("saida.txt");
    		return 2;
  	}
  
  	while (fscanf(fr, "%d", &num) != EOF)   // enquanto nao chegou no fim do arquivo apontado por fr, le um numero
    		fprintf(fw, "%d ", num);   // escreve o num no arquivo apontado por fw
  
  	fclose(fr);
  	fclose(fw);

  	return 0;
}
