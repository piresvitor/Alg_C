// Resolve recursivamente o problema da torre de Hanoi

#include <stdio.h>

// declaracao de funcoes
void hanoi (int discos, char origem, char destino, char auxiliar);


int main (void){

   int qtdDiscos;

	// entrada dos dados
   printf("\t Introduza o número de discos: ");
   scanf("%d",&qtdDiscos);
   printf ("\n\n\n");

	// solucao por recursao
   hanoi(qtdDiscos,'A','C','B');
   printf("\n\n\n");
}


void hanoi (int discos, char origem, char destino, char auxiliar) {

   if (discos==1)
   	printf("\t Mova o disco %d de %c para %c \n", discos, origem, destino);
   else {
		hanoi(discos-1, origem, auxiliar, destino);
		printf("\t Mova o disco %d de %c para %c \n", discos, origem, destino);
		hanoi(discos-1,auxiliar,destino,origem);
   }
} 

