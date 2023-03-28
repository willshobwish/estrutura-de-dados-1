#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX 20

typedef struct pilha {
    int conteudoPilha[MAX];
    int topo;
} Pilha;

void Inicializao(Pilha *pilha) {
    pilha->topo = 0;
}

bool Vazio(Pilha *pilha) {
    if (pilha->topo == 0) {
        return true;
    } else {
        return false;
    }
}

bool Cheia(Pilha *pilha) {
    if (pilha->topo == MAX) {
        return true;
    } else {
        return false;
    }
}

void Push(Pilha *pilha, int elemento) {
    if (Cheia(pilha)) {
        printf("Nao ha espaco na pilha");
    } else {
        pilha->conteudoPilha[pilha->topo] = elemento;
        pilha->topo++;
        printf("Elemento inserido: %d\nTopo da pilha: %d\n\n", pilha->conteudoPilha[pilha->topo - 1], pilha->topo);
    }
}
void Pop(Pilha *pilha, int *elemento) {

    if (Vazio(pilha)) {
        printf("Pilha vazia\n");
    } else {
        pilha->topo--;
        *elemento = pilha->conteudoPilha[pilha->topo];
    }
    // return elemento;
}

int main(void) {
    Pilha pilha;
    int resultado;
    Inicializao(&pilha);
    for (int i = 0; i < MAX; i++) {
        Push(&pilha, i + 20);
    }
    for (int i = 0; i < MAX + 1; i++) {
        Pop(&pilha,&resultado);
        printf("Remocao da pilha: %d\n", resultado);
    }
}
