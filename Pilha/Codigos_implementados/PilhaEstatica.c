#include <stdio.h>
#define MAX 10

typedef struct
{
    int vPilha[MAX];
    int topo;
} Pilha;

int inicializacao(Pilha *pilha) {
    // Define a pilha vazia
    pilha->topo = 0;
}

short vazia(Pilha *pilha){
    // Verifica se a pilha esta vazia
    if (pilha->topo == 0)
        return 1;
    else
        return 0;
}

short cheia(Pilha *pilha){
    // Verifica se a pilha esta cheia
    if (pilha->topo == MAX)
        return 1;
    else
        return 0;
}

void push(Pilha *pilha, int elemento) {
    // Envia o elemento para a pilha
    if (cheia(pilha)) {
        printf("Pilha Cheia!!!");
    } else {
        pilha->vPilha[pilha->topo] = elemento;
        pilha->topo++;
    }
}
// A variável topo sendo inicializada com o valor 0, primeiro insere o elemento no topo e depois incrementa o valor do topo

void pop(Pilha *pilha, int *elemento) {
    // Remove o elemento do topo da pilha
    if (vazia(pilha)) {
        printf("Pilha Vazia - Não há elementos para desempilhar!!!");
    } else {
        pilha->topo--;
        *elemento = pilha->vPilha[pilha->topo];
    }
}

void obterTopo(Pilha *pilha, int *elemento) {
    // Obtem o topo da pilha
    if (vazia(pilha))
        printf("Pilha Vazia - Não há elementos para desempilhar!!!");
    else
        *elemento = pilha->vPilha[pilha->topo - 1];
}

int main(void) {
    Pilha P1;
    int var;
    inicializacao(&P1);
    push(&P1, 10);
    push(&P1, 20);
    push(&P1, 30);
    printf("Topo: %d \n", P1.topo);
    for (int i = 0; i < MAX; i++)
        printf("%d ", P1.vPilha[i]);

    pop(&P1, &var);
    printf("\n %d \n", var);
    printf("Topo: %d \n", P1.topo);
    for (int i = 0; i < MAX; i++)
        printf("%d ", P1.vPilha[i]);
}