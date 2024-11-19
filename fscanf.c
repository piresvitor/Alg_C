/*
 * Cópia de arquivo para a saída padrão.
 */
#include<stdio.h>

int main(void) 
{
  	FILE *f;   // f eh um apontador para um FILE
  	int num;
  
  	f = fopen ("teste.txt", "r");   // abre teste.txt para leitura... f aponta para o inicio de teste.txt 

  	if (f == NULL) // nao conseguiu abrir o arquivo
	{
    		perror("teste.txt");  // exibe uma mensagem explicativa
    		return 1;
  	}
  
	// EOF = End Of File
 	while (fscanf(f, "%d", &num) != EOF)  // eqto nao chegou no fim, le um numero do arquivo apontado por f e guarda no endereco &num
    		printf("%d ", num);  // imprime o num lido do arquivo na tela
  	
	fclose(f);    // fecha o arquivo
 
  	return 0;
}
