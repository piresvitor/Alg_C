/*
 * Escreve um banco de dados de registros. Depois altera
 * um registro específico diretamente no arquivo em disco.
 */

#include <stdio.h>
#include <stdlib.h>

#define SIZE_NAME 255
#define REGS  5

typedef struct reg {int ra;
  char nome[30];
  char disciplinas[4][6];
  float cr;
}Reg_aluno;


void escreve_dados(Reg_aluno dados[], char *fileName) {
  FILE  *fw;

  fw = fopen (fileName, "wb");

  if (fw == NULL) {
  	perror(fileName);
  	exit(-1);  /* Abandona o programa */  
  }

  fwrite(dados, sizeof(Reg_aluno), REGS, fw); 

  fclose(fw);  
}


void altera_dados(char *fileName, int i, int novora) {
  FILE  *f;
  Reg_aluno dado;

  f = fopen (fileName, "r+b");

  if (f == NULL) {
  	perror(fileName);
  	exit(-1);  /* Abandona o programa */  
  }

  fseek(f, i * sizeof(Reg_aluno), SEEK_SET);
  fread(&dado, sizeof(Reg_aluno), 1, f);
  printf("antes %d\n", dado.ra);  	
  dado.ra = novora;
  printf("depois %d\n", dado.ra);	

  fseek(f, i * sizeof(Reg_aluno), SEEK_SET);
  fwrite(&dado, sizeof(Reg_aluno), 1, f);

  fclose(f);
}



void escreve_registro_texto(char *binFileName, char *textFileName) {
  FILE  *fw, *fr;
  int i;
  Reg_aluno dados[REGS];

  fr = fopen (binFileName, "rb");

  if (fr == NULL) {
  	perror(binFileName);
  	exit(-1);  /* Abandona o programa */  
  }

  fread(dados, sizeof(Reg_aluno), REGS, fr); 

  fclose(fr); 

  fw = fopen (textFileName, "w");

  if (fw == NULL) {
  	perror(textFileName);
  	exit(-1);  /* Abandona o programa */  
  }

  for (i = 0; i < REGS; i++) {
    fprintf(fw, "%d ", dados[i].ra);
    fprintf(fw, "%s ", dados[i].nome);
    fprintf(fw, "%s ", dados[i].disciplinas[0]);
    fprintf(fw, "%s ", dados[i].disciplinas[1]);
    fprintf(fw, "%s ", dados[i].disciplinas[2]);
    fprintf(fw, "%s ", dados[i].disciplinas[3]);
    fprintf(fw, "%.1f\n", dados[i].cr);
  }

  fclose(fw);  
}


int main(void) {
  char textFileName[SIZE_NAME+1] = "dados_aluno.txt";
  char binFileName[SIZE_NAME+1] = "dados_aluno.bin";

  Reg_aluno dados[REGS] =  {
    {12436, "Maria", {"MC102\0", "MA141\0", "FP128\0", "FU129\0"}, 0.2},
    {12232, "Joao",  {"MC202\0", "MA211\0", "FP228\0", "FU229\0"}, 0.8},
    {12789, "Jose",  {"MC102\0", "MA141\0", "FP128\0", "FU129\0"}, 0.7},
    {12123, "Carlos",{"MC202\0", "MA211\0", "FP228\0", "FU229\0"}, 0.9},			
    {12345, "Carla", {"MC202\0", "MA211\0", "FP228\0", "FU229\0"}, 0.5},
  };

  escreve_dados(dados, binFileName);
  altera_dados(binFileName, 2, 12222);  // altera o registro da posição 2 do vetor
  escreve_registro_texto(binFileName, textFileName);

  return (0);
}
