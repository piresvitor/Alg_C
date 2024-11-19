/*
 * Lê um vetor de um arquivo texto. O primeiro inteiro lido é
 * a dimensão do vetor.
 *
 * Escreve o vetor em um arquivo de saí­da binário. 
 *
 * Lê um vetor do arquivo binário e o escreve em um arquivo texto.
 */

#include <stdio.h>
#include <stdlib.h>

int *le_vetor_texto(int *n, char *fileName) {
  FILE  *fr;
  int *v;
  int i;

  fr = fopen (fileName, "r");

  if (fr == NULL) {
    perror(fileName);
    exit(-1);  /* Abandona o programa */  
  }
  
  fscanf(fr, "%d", n);
  v = (int *) malloc (*n * sizeof(int));
  
  for (i = 0; i < *n; i++)
    fscanf(fr, "%d", &v[i]);

  fclose(fr);
  
  return v;
}

int *le_vetor_binario(int *n, char *fileName) {
  FILE  *fr;
  int *v;

  fr = fopen (fileName, "rb");

  if (fr == NULL) {
    perror(fileName);
    exit(-1);  /* Abandona o programa */  
  }
  
  fread(n, sizeof(int), 1, fr);
  v = (int *) malloc (*n * sizeof(int));
  
  fread(v, sizeof(int), *n, fr);

  fclose(fr);
  
  return v;
}

void escreve_vetor_texto(int *v, int n, char *fileName) {
  FILE  *fw;
  int i;

  fw = fopen (fileName, "w");

  if (fw == NULL) {
    perror(fileName);
    exit(-1);  /* Abandona o programa */  
  }
  
  fprintf(fw, "%d\n", n); /* Dimensão do vetor */
  
  for (i = 0; i < n; i++)
    fprintf(fw, "%d\n", v[i]);

  fclose(fw);  
}

void escreve_vetor_binario(int *v, int n, char *fileName) {
  FILE  *fw;

  fw = fopen (fileName, "wb");

  if (fw == NULL) {
    perror(fileName);
    exit(-1);  /* Abandona o programa */  
  }
  
  /* Dimensão do vetor */
  fwrite(&n, sizeof(int), 1, fw); 
  fwrite(v, sizeof(int), n, fw); 

  fclose(fw);  
}

int main() {
  char textFileIn[255] = "v-in.txt", textFileOut[255] = "v-out.txt", binFile[255] = "v.bin"; 
  int *v1, *v2;
  int n1, n2;
  
  v1 = le_vetor_texto(&n1, textFileIn);
  escreve_vetor_binario(v1, n1, binFile);
  
  v2 = le_vetor_binario(&n2, binFile);
  escreve_vetor_texto(v2, n2, textFileOut);

  free(v1);
  free(v2);
  
  return 0;

}
