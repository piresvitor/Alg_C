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

/* --- EXERCICIOS --- */
void imprimir_invertida(NO *inicio); /* EXERCICIO 1 */
int tamanho(LISTA_LIGADA *lista); /* EXERCICIO 2 */
void apagar_lista(LISTA_LIGADA *lista); /* EXERCICIO 3 */
int remover_posicao(LISTA_LIGADA *lista, int pos); /* EXERCICIO 4 */
int inserir_posicao(LISTA_LIGADA *lista, ITEM *item, int pos); /* EXERCICIO 5 */



int main() {
  int i;

  //criar a lista
  LISTA_LIGADA lista;
  criar(&lista);

  //inserir itens na lista
  for (i = 0; i < 10; i++) {
    ITEM item;
    item.chave = i;
    item.valor = rand();
    inserir(&lista, &item);
  }

  printf("--- Lista --- \n");
  imprimir(&lista);
  printf("\nTamanho: %d\n", tamanho(&lista));

  ITEM item1;
  item1.chave = 100;
  item1.valor = 0;
  inserir_posicao(&lista, &item1, 0);

  printf("\n--- Lista invertida ---\n");
  imprimir_invertida(lista.inicio);
  printf("\nTamanho: %d\n", tamanho(&lista));

  ITEM item;
  if (buscar(&lista, 5, &item)){
    printf("\nEncontrado: %d - %d\n", item.chave, item.valor);
  }

  remover_posicao(&lista, 5);

  for (i = 0; i < 10; i++) {
    remover_fim(&lista);
  }

  printf("\n--- Lista --- \n");
  imprimir(&lista);
  printf("\nTamanho: %d\n", tamanho(&lista));

  apagar_lista(&lista);

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


// EXERCICIO 01
void imprimir_invertida(NO *inicio) {

  // caso base
  if (inicio == NULL) 
    return;

  imprimir_invertida(inicio->proximo);

  printf("%d - %d\n", inicio->item.chave, inicio->item.valor);
}


// EXERCICIO 02
int tamanho(LISTA_LIGADA *lista) {
  NO *paux = lista->inicio;
  int contador = 0;

  while (paux != NULL) {
    paux = paux->proximo;
    contador++;
  }

  return (contador);
}


// EXERCICIO 03
void apagar_lista(LISTA_LIGADA *lista) {
  if (!vazia(lista)) {
    NO *paux = lista->inicio;

    while (paux != NULL) {
      NO *prem = paux;
      paux = paux->proximo;
      free(prem);
    }
  }

  lista->inicio = NULL;
  lista->fim = NULL;
}


// EXERCICIO 04
int remover_posicao(LISTA_LIGADA *lista, int pos) {
  int i;

  if (!vazia(lista)) { //verifica se a lista está vazia
    if (pos == 0) { //removendo o primeiro nó
      if (lista->inicio == lista->fim) { //se a lista tem um nó
        lista->fim = NULL;
      }

      NO *paux = lista->inicio;
      lista->inicio = lista->inicio->proximo;
      free(paux);
    } else { //removendo do segundo nó para frente
      //aponta para o nó anterior a ser retirado
      NO *paux = lista->inicio;
      for (i = 0; i < pos-1; i++) {
        if (paux->proximo != lista->fim) {
          paux = paux->proximo;
        } else {
          return 0;
        }
      }

      NO *pos = paux->proximo;
      paux->proximo = paux->proximo->proximo;

      if (pos->proximo == NULL) { //último nó retirado
        lista->fim = paux;
      }

      free(pos);
    }
    return 1;
  } else {
    return 0;
  }
}


// EXERCICIO 05
int inserir_posicao(LISTA_LIGADA *lista, ITEM *item, int pos) {
  int i;

  //cria um novo nó
  NO *pnovo = (NO *)malloc(sizeof(NO));

  if (pnovo != NULL) { //verifica se a memória foi alocada
    pnovo->item = *item; //preenche os dados
    pnovo->proximo = NULL; //define que o próximo é nulo

    if (vazia(lista)) { //se a lista estiver vazia
      if (pos == 0) { // unica posicao valida
        lista->inicio = lista->fim = pnovo; //inicio e fim apontam para novo nó
        return 1; // deu tudo certo
      }
      else {
        return 0;
      }
    }
    else { // se a lista não está vazia
      if (pos == 0) { // colocar na primeira posicao
        pnovo->proximo = lista->inicio; // novo nó aponta para inicio da lista
        lista->inicio = pnovo; // inicio da lista passa a apontar para novo nó
        return 1;
      }
      else if (pos == tamanho(lista)){ // se for na última posição após o último nó
        lista->fim->proximo = pnovo; // ultimo nó corrente aponta para novo nó
        lista->fim = pnovo; //atualiza o fim da lista
        return 1;
      }
      else if (pos < tamanho(lista)){ // posicao valida no meio da lista
        //aponta para o nó anterior a ser inserido
        NO *paux = lista->inicio;
        for (i = 0; i < pos-1; i++) {
          paux = paux->proximo;
        }
        pnovo->proximo = paux->proximo; // o novo nó aponta para o próximo de paux
        paux->proximo = pnovo; // paux aponta para o novo nó
        return 1;
      }
      else {
        return 0;
      }
    }
  }
  return 0;
}

