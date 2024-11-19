/*
 * Altera uma posição de um vetor escrito em um arquivo binário. Lê este vetor
 * e o escreve em um arquivo texto.
 */

#include <stdio.h>
#include <stdlib.h>

void altera(int pos, int valor) {
  FILE *f;

  f = fopen ("v.bin", "r+b");

  if (f == NULL) {
    perror("v.bin: ");
    exit(-1);  /* Abandona o programa */  
  }
  
  /* a primeira posição é o tamanho do vetor */
  fseek(f, (pos+1)*sizeof(int), SEEK_SET);
  fwrite(&valor, sizeof(int), 1, f);

  fclose(f);
  
}

int *le_vetor_binario(int *n) {
  FILE  *fr;
  int *v;

  fr = fopen ("v.bin", "rb");

  if (fr == NULL) {
    perror("v.bin: ");
    exit(-1);  /* Abandona o programa */  
  }
  
  fread(n, sizeof(int), 1, fr);
  v = (int *) malloc (*n * sizeof(int));
  
  fread(v, sizeof(int), *n, fr);

  fclose(fr);
  
  return v;
}

void escreve_vetor_texto(int *v, int n) {
  FILE  *fw;
  int i;

  fw = fopen ("v-out.txt", "w");

  if (fw == NULL) {
    perror("v-out.txt ");
    exit(-1);  /* Abandona o programa */  
  }
  
  fprintf(fw, "%d\n", n); /* DimensÃ£o do vetor */
  
  for (i = 0; i < n; i++)
    fprintf(fw, "%d\n", v[i]);

  fclose(fw);  
}

void imprime_vetor(int v[],int n){
    int i;
    for(i=0; i<n; i++){
        printf("%d ",v[i]);
    }    
    printf("\n");
}

  
int main() {
  int *v, n;

  v = le_vetor_binario(&n);
  imprime_vetor(v, n);  
  free(v);
  
  altera (5, -5);
  
  v = le_vetor_binario(&n);
  imprime_vetor(v, n);  
  
  escreve_vetor_texto(v, n);   
  free(v);

  
  return 0;

}
