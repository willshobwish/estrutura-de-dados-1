#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct noFila {
    int elemento;
    int prioridade;
    struct noFila *prox;
};

typedef struct {
    struct noFila *inicio;
    struct nofila *fim;
} FilaPrioridade;

void inicializacao(FilaPrioridade *fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
}

bool vazia(FilaPrioridade *fila) {
    if (fila->inicio == NULL) {
        return true;
    } else {
        return false;
    }
}
bool cheia(FilaPrioridade *fila) {
    struct noFila *novoNo;
    novoNo = malloc(sizeof(struct noFila));
    if (novoNo == NULL) {
        return true;
    } else {
        return false;
    }
}

void inserir(FilaPrioridade *fila, int elemento, int prioridade) {
    struct noFila *novoNo, *aux, *anterior;
    novoNo = malloc(sizeof(struct noFila));
    if (novoNo == NULL) {
        printf("Fila cheia");
    } else {
        novoNo->prox = NULL;
        novoNo->prioridade = prioridade;
        novoNo->elemento = elemento;
        aux = fila->inicio;
        anterior = NULL;
        while ((aux != NULL) && (aux->prox >= prioridade)) {
            anterior = aux;
            aux = aux->prox;
        }
    }
}

void imprimir(FilaPrioridade *fila) {
    struct noFila *aux = fila->inicio;
    while (aux!=NULL)
    {
        printf("Prioridade:%d Elemento:%d",aux->prioridade,aux->elemento);
        aux=aux->prox;
    }
    
}

int main(void) {
    FilaPrioridade fila;
    inicializacao(&fila);
    for (int i = 0; i < 20; i++) {
        inserir(&fila, i * 10 + 5, i);
    }
    imprimir(&fila);
}