#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int elemento;
    struct nodePilha *prox;
} nodePilha;

typedef struct {
    nodePilha *topo;
} Pilha;

void Inicializacao(Pilha *pilha) {
    pilha->topo = NULL;
}

bool Vazia(Pilha *pilha) {
    if (pilha->topo == NULL) {
        return true;
    } else {
        return false;
    }
}

bool Cheia(Pilha *pilha) {
    nodePilha *newNode = malloc(sizeof(pilha));
    if (newNode == NULL) {
        printf("Nao foi possivel alocar memoria");
        return true;
    } else {
        return false;
    }
}

void Push(Pilha *pilha, int elemento) {
    nodePilha *newNode = malloc(sizeof(nodePilha));
    if (newNode == NULL) {
        printf("Pilha cheia");
    } else {
        // Atribuicao do valor do novo elemento
        newNode->elemento = elemento;
        // Atribuicao do proximo elemento 
        newNode->prox = pilha->topo;
        // O descritor aponta para o novo elemento
        pilha->topo = newNode;
    }
}

void Pop(Pilha *pilha, int *elemento) {
    nodePilha *auxiliar;
    if (Vazia(pilha)) {
        printf("Nao ha elementos na pilha");
    } else {
        auxiliar = pilha->topo;
        *elemento = auxiliar->elemento;
        pilha->topo = pilha->topo->prox;
        free(auxiliar);
    }
}

void ObterTopo(Pilha *pilha, int *elemento) {
    if (Vazia(pilha)) {
        printf("Nao ha elementos na pilha");
    } else {
        *elemento = pilha->topo->elemento;
    }
}

int main(void) {
    Pilha pilha;
    int resultado;
    Inicializacao(&pilha);
    Push(&pilha, 10);
    Push(&pilha, 20);
    ObterTopo(&pilha, &resultado);
    printf("Elemento no topo: %d", resultado);
}