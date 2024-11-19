#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int chave;
  int valor;
} ITEM;

typedef struct NO {
  ITEM item;
  struct NO *proximo;
} NO;

typedef struct {
  NO *inicio;
  NO *fim;
} LISTA_LIGADA;

void criar(LISTA_LIGADA *lista);
int vazia(LISTA_LIGADA *lista);
void imprimir(LISTA_LIGADA *lista);
int buscar(LISTA_LIGADA *lista, int chave, ITEM *item);
int inserir(LISTA_LIGADA *lista, ITEM *item);
int remover_fim(LISTA_LIGADA *lista);


int main() {
  int i;

  //criar a lista
  LISTA_LIGADA lista;
  criar(&lista);

  //inserir itens na lista
  for (i = 0; i < 10; i++) {
    ITEM item;
    item.chave = i;
    item.valor = rand()%100;
    inserir(&lista, &item);
  }

  printf("--- Lista --- \n");
  imprimir(&lista);
  
  ITEM item;
  if (buscar(&lista, 5, &item)){
    printf("\nEncontrado: %d - %d\n", item.chave, item.valor);
  }

  for (i = 0; i < 10; i++) {
    remover_fim(&lista);
  }

  printf("\n--- Lista --- \n");
  imprimir(&lista);

  return 0;
}
// inicializa campos inicio e fim da LISTA com NULL
void criar(LISTA_LIGADA *lista) {
  lista->inicio = NULL;
  lista->fim = NULL;
}

// verifica se inicio da lista é NULL
int vazia(LISTA_LIGADA *lista) {
  return (lista->inicio == NULL);
}

void imprimir(LISTA_LIGADA *lista) {

  if (!vazia(lista)){
    NO *paux = lista->inicio;

    while (paux != NULL) {
      printf("%d - %d\n", paux->item.chave, paux->item.valor);
      paux = paux->proximo;
    }
  }
  else
    printf("LISTA VAZIA!\n\n");
}

int buscar(LISTA_LIGADA *lista, int chave,  ITEM *item) {
  NO *paux = lista->inicio;

  while (paux != NULL) {
    if (paux->item.chave == chave) {
      *item = paux->item;  
      return 1;
    }
    paux = paux->proximo;
  }

  return 0;
}

// Insere na ultima posicao
int inserir(LISTA_LIGADA *lista, ITEM *item) {
  //cria um novo nó
  NO *pnovo = (NO *)malloc(sizeof(NO));

  if (pnovo != NULL) { //verifica se a memória foi alocada
    pnovo->item = *item; //preenche os dados
    pnovo->proximo = NULL; //define que o próximo é nulo

    if (vazia(lista)) { //se a lista for vazia
      lista->inicio = pnovo; //inicio aponta para novo
    } else {
      lista->fim->proximo = pnovo; //proximo do fim aponto para novo
    }

    lista->fim = pnovo; //fim aponta para novo

    return 1;
  } else {
    return 0;
  }
}

int remover_fim(LISTA_LIGADA *lista) {
  if (!vazia(lista)) {
    //procura o penúltimo nó
    NO *paux  = lista->inicio;
    while (paux->proximo != NULL && paux->proximo != lista->fim) {
      paux = paux->proximo;
    }

    if (lista->inicio == lista->fim) {//a lista tem um nó
      free(paux->proximo); //libera o único nó
      lista->inicio = lista->fim = NULL; //lista vazia
    } else {
      free(lista->fim); //libera último nó
      lista->fim = paux; //penúltimo nó vira último
      lista->fim->proximo = NULL;
    }

    return 1;
  } else {
    return 0;
  }
}

