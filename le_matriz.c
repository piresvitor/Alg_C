/*
 * Lê uma matriz de um arquivo. Os dois primeiros inteiros lidos são
 * a dimensão da matriz. A matriz é armazenada em memória e depois
 * escrita novamente em outro arquivo-texto. 
 */
#include <stdio.h>
#include <stdlib.h>

int *le_matriz(int *nlin, int* ncol) {
  FILE  *fr;
  int *m;
  int i, j;

  fr = fopen ("m-in.txt", "r");

  if (fr == NULL) {
    perror("m-in.txt: ");
    exit(-1);  /* Abandona o programa */  
  }
  
  fscanf(fr, "%d %d", nlin, ncol); // lê as dimensoes da matriz

  m = (int *) malloc (*nlin * *ncol * sizeof(int)); // aloco memória para a matriz
  
  for (i = 0; i < *nlin; i++)
    for (j = 0; j < *ncol; j++)
      fscanf(fr, "%d", &m[i * *ncol + j]);

  fclose(fr);
  
  return (m);
}


void escreve_matriz(int *m, int nlin, int ncol) {
  FILE  *fw;
  int i, j;

  fw = fopen ("m-out.txt", "w");

  if (fw == NULL) {
    perror("m-out.txt ");
    exit(-1);  /* Abandona o programa */  
  }
  
  fprintf(fw, "%d %d\n", nlin, ncol); /* Escreve as dimensões da matriz */
  
  for (i = 0; i < nlin; i++) {
    for (j = 0; j < ncol; j++)
      fprintf(fw, "%d ", m[i * ncol + j]);
      
    fprintf(fw, "\n");
  }

  fclose(fw);  
}


int main() {
  int *m;
  int nlin, ncol;
  
  m = le_matriz(&nlin, &ncol);
  escreve_matriz(m, nlin, ncol);

  free(m);
  
  return 0;

}
