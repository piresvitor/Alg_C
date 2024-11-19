#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define REGISTER_SIZE 200  //tamanho maximo de cada registro
#define NAME_SIZE     100  //tamanho maximo por nome


typedef struct amigo{
	char nome[NAME_SIZE];
	int  telefone;
} Amigo;

typedef struct agenda{
	Amigo *amigo;
	int num_amigos;
} Agenda;


//Prototipos de funcoes
Agenda LeAgenda(char *nomearq);
void   OrdenaAgenda(Agenda a);
void   GravaAgenda(Agenda a, char *nomearq);
void   DestroiAgenda(Agenda a);


Agenda LeAgenda(char *nomearq)
{
	int i;
	FILE *aparq;
	Agenda a;

	aparq = fopen(nomearq,"rb"); /* Abre o arquivo binário para leitura */

	/* le 1 elemento do tamanho de um inteiro copiano sua sequencia de 
		bytes para a memoria a partir do endereco apontado por 
		&a.num_amigos. Avanca o respectivo numero de bytes na posicao para a
		proxima leitura. */
	fread(&a.num_amigos, sizeof(int), 1, aparq);

	a.amigo = (Amigo *) calloc(a.num_amigos,sizeof(Amigo));

	printf("Arquivo: %s\n", nomearq);

	for (i=0; i < a.num_amigos; i++){
		printf("Byte: %ld\n", ftell(aparq)); /* Apenas curiosidade. Informa a posicao no arquivo para leitura */
		fread(&a.amigo[i], sizeof(Amigo), 1, aparq);
		printf("Nome: %s | telefone: %d\n", a.amigo[i].nome, a.amigo[i].telefone);
	}

	printf("\n\n");
	fclose(aparq);
	
	return(a);
}


void OrdenaAgenda(Agenda a)
{
	int i, j, jm;
	Amigo aux;

	for (j=0; j < a.num_amigos-1; j++){
		jm = j;
		for (i=j+1; i < a.num_amigos; i++){
			if (strcmp(a.amigo[i].nome, a.amigo[jm].nome) < 0)
				jm = i;
		}

		if (j != jm){
			aux = a.amigo[j];
			a.amigo[j] = a.amigo[jm];
			a.amigo[jm] = aux;
		}
	}
}


void GravaAgenda(Agenda a, char *nomearq)
{
	int i;
	FILE *aparq;

	aparq = fopen(nomearq, "wb"); //cria novo arquivo binario aberto para escrita

	/* Escreve 1 elemento do tamanho de um inteiro na posicao atual de 
		escrita no arquivo, copiando sua sequencia de bytes da memoria a
		partir do endereco apontado por &a.num_amigos. Avanca o respectivo
  		numero de bytes na posicao para a proxima escrita. */

	fwrite(&a.num_amigos, sizeof(int), 1, aparq);

	for (i=0; i < a.num_amigos; i++)
		fwrite(&a.amigo[i], sizeof(Amigo), 1, aparq);

	fclose(aparq);
}


void AlteraRegistro(char *nomearq)
{
	FILE *aparq;
	Amigo aux;

	/* Abre arquivo para leitura e escrita */
	aparq = fopen(nomearq, "r+b");

	/* posiciona leitura/escrita no inicio do segundo registro */
	fseek(aparq, sizeof(int)+sizeof(Amigo), SEEK_SET);

	fread(&aux, sizeof(Amigo), 1, aparq); /* le nome e telefone */
	aux.telefone = 100000; /* Altera telefone */

	/* posiciona leitura/escrita no inicio do segundo registro */
	fseek(aparq, sizeof(int)+sizeof(Amigo), SEEK_SET);

	fwrite(&aux, sizeof(Amigo), 1, aparq); /* grava registro modificado */

	fclose(aparq);
}


void AdicionaRegistro(char *nomearq)
{
	FILE *aparq;
	Amigo aux;
	int num_amigos;

	/* abre arquivo para leitura/escrita. Posiciona escrita no final
		do arquivo, mas permite leitura dos registros se o apontador for
		reposicionado. Só permite escrita no final. */
	aparq = fopen(nomearq, "a+b");

	sprintf(aux.nome, "Tiago Almeida");
	aux.telefone = 889900;
	fwrite(&aux, sizeof(Amigo), 1, aparq); /* Grava no final */
	fseek(aparq, 0, SEEK_SET); /* Posiciona leitura no inicio do arquivo */
	fread(&num_amigos, sizeof(int), 1, aparq); /* le numero de amigos */
	num_amigos++;

	fclose(aparq);

	/* abre para leitura/escrita em qualquer posicao */
	aparq = fopen(nomearq, "r+b");

	/* grava numero de amigos atualizado */
	fwrite(&num_amigos, sizeof(int), 1, aparq);
	fclose(aparq);
}


void DestroiAgenda(Agenda a)
{
	if (a.amigo != NULL)
		free(a.amigo);
}

int main() {
	Agenda a;
	
	a.num_amigos = 3;
	a.amigo = (Amigo *) calloc(a.num_amigos,sizeof(Amigo));

	sprintf(a.amigo[0].nome, "Fulando da Silva");
	a.amigo[0].telefone = 123456;

	sprintf(a.amigo[1].nome, "Siclano de Souza");
	a.amigo[1].telefone = 654321;

	sprintf(a.amigo[2].nome, "Beltrano de Oliveira");
	a.amigo[2].telefone = 665544;

	GravaAgenda(a, "agenda.bin");

	AdicionaRegistro("agenda.bin");
	
	AlteraRegistro("agenda.bin");

	DestroiAgenda(a);



	a = LeAgenda("agenda.bin");

	OrdenaAgenda(a);		

	GravaAgenda(a, "agenda_ord.bin");

	a = LeAgenda("agenda_ord.bin");

	DestroiAgenda(a);
	
	return(0);
}





