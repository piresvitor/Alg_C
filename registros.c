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
	Agenda a;
	FILE *aparq;
	int i;
	char linha[REGISTER_SIZE], *pos;

	if	((aparq = fopen(nomearq, "r")) == NULL) {
		perror("Erro ao abrir o arquivo: ");
		exit(EXIT_FAILURE);
	}
	

	fgets(linha, REGISTER_SIZE-1, aparq); // le cadeia de caracteres do arquivo ate \n
	sscanf(linha, "%d", &a.num_amigos); // coloca valor de linha no campo num_amigos

	a.amigo = (Amigo *) calloc(a.num_amigos, sizeof(Amigo)); // Aloca estruturas
	
	if (a.amigo != NULL) {
		for (i=0; i<a.num_amigos; i++){
			fgets(linha, REGISTER_SIZE-1, aparq); // lê próxima linha do arquivo
			pos = strchr(linha, '@'); // retorna ponteiro para primeira ocorrencia de '@' em linha
			strncpy(a.amigo[i].nome, linha, pos-linha); //copia em nome pos-1 caracteres de linha
			sscanf(pos+1, "%d", &a.amigo[i].telefone); //coloca o restante de linha apos '@' no campo telefone
		}
	}
	
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

	aparq = fopen(nomearq, "w"); //cria novo arquivo

	fprintf(aparq, "%d\n", a.num_amigos); // escreve primeira linha

	for (i=0; i < a.num_amigos; i++)
		fprintf(aparq,"%s@%d\n",a.amigo[i].nome, a.amigo[i].telefone); //escreve registros

	fclose(aparq);
}


void DestroiAgenda(Agenda a)
{
	if (a.amigo != NULL)
		free(a.amigo);
}

int main() {
	Agenda a;
	
	a = LeAgenda("agenda.in");
	OrdenaAgenda(a);
    GravaAgenda(a, "agendaOrdenada.out");
	DestroiAgenda(a);

	return(0);
}





