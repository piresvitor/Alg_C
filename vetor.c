/*
 * Lê um vetor de um arquivo texto e o escreve em um arquivo de saída binário. 
 *
 * Lê um vetor do arquivo binário e o escreve em um arquivo texto.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
  FILE *fr, *fw;
  int *v1, tam;
  int i;

  // le vetor de arquivo texto
  fr = fopen ("v-in.txt", "r");

  if (fr == NULL) {
  	perror("v-in.txt: ");
  	return 1;  
  }

  fscanf(fr, "%d", &tam); // le tamanho do vetor
  v1 = (int *)malloc(tam*sizeof(int)); // aloca a estrutura 
  for (i = 0; i < tam; i++)     // le o vetor v1 do arquivo v-in.txt
  	fscanf(fr, "%d", &v1[i]);

  fclose(fr);

  // escreve vetor em arquivo binario
  fw = fopen ("v.bin", "wb");    

  if (fw == NULL) {
  	perror("v.bin");
  	return 2;  
  }

  fwrite(&tam, sizeof(int), 1, fw);
  fwrite(v1, sizeof(int), tam, fw);
  fclose(fw);

  // inicializa as variaveis
  tam = 0;
  free(v1);

  // le vetor de arquivo binario e imprime na tela
  fr = fopen ("v.bin", "rb");    

  if (fr == NULL) {
    perror("v.bin");
    return 2;  
  }

  fread(&tam, sizeof(int), 1, fr); // le o tamanho do vetor
  v1 = (int *)malloc(tam*sizeof(int)); // aloca a estrutura
  fread(v1, sizeof(int), tam, fr); // le o vetor do arquivo v.bin

  fclose(fr);

  for (i = 0; i < tam; i++)     // imprime o vetor na tela
    printf("%d\n", v1[i]);

  free (v1);

  return 0;
}
