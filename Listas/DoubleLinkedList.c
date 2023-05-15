#include <stdio.h>
#include <stdlib.h>

struct Lista {
    int elemento;
    struct Lista *proximo;
    struct Lista *anterior;
};

typedef struct Lista Lista;

void Insere(Lista *lista, int elemento) {
    Lista *aux = lista, *novo = malloc(sizeof(Lista));
    novo->elemento = elemento;
    while (aux->proximo != NULL) {
        aux = aux->proximo;
    }
    if (aux == NULL) {
        printf("Lista vazia\n");
        novo->proximo = NULL;
        novo->anterior = NULL;
        aux = novo;
    } else if (aux != NULL) {
        aux->proximo = novo;
        novo->anterior = aux;
    }
}
void inicializa(Lista *lista) {
    lista->proximo = NULL;
    lista->anterior = NULL;
}
void Imprime(Lista *lista) {
    Lista *aux = lista;
    while (aux != NULL) {
        printf("%d\n", aux->elemento);
        aux = aux->proximo;
    }
}
int main(void) {
    Lista lista;
    inicializa(&lista);
    Insere(&lista, 12);
    Insere(&lista, 13);
    // printf("%d\n", lista.elemento);
    Imprime(&lista);
}