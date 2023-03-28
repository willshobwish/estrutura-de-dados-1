#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX 20

typedef struct
{
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
        printf("%d", pilha->topo);
    }
}
void Pop(Pilha *pilha, int *elemento) {
    if (Vazio(pilha)) {
        printf("Pilha vazia");
    } else {
        pilha->topo--;
        elemento = pilha->conteudoPilha[pilha->topo];
    }
}

int main(void) {
    Pilha pilha;
    Inicializao(&pilha);
    Push(&pilha, 10);
    Push(&pilha, 12);
    Push(&pilha, 13);
    Push(&pilha, 14);
    int resultado;
    Pop(&pilha, &resultado);
    printf("%d\n", resultado);
    Pop(&pilha, &resultado);
    printf("%d\n", resultado);
    Pop(&pilha, &resultado);
    printf("%d\n", resultado);
    Pop(&pilha, &resultado);
    printf("%d\n", resultado);
}
