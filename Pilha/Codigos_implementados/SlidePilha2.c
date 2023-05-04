#include <stdio.h>
#include <stdlib.h>

struct noPilha {
    int elemento;
    struct noPilha *prox;
};

// Descritor
typedef struct Pilha {
    struct noPilha *topo;
} Pilha;

int inicializacao(Pilha *pilha) {
    pilha->topo = NULL;  // pilha vazia
}

short vazia(Pilha *pilha)  // verifica se a pilha está vazia
{
    if (pilha->topo == NULL)
        return 1;
    else
        return 0;
}

// a código da função pilha cheia pode ser inserido na função push
short cheia(Pilha *pilha)  // a pilha estará cheia quando não houver memória para ser alocada
{
    struct noPilha *novo;
    novo = malloc(sizeof(struct noPilha));
    // malloc retorna null quando não houver memória disponível para alocação ou quando ocorrer algum erro durante a alocação - execução do malloc
    if (novo == NULL)
        return 1;
    else
        return 0;
}

void push(Pilha *pilha, int elemento) {
    struct noPilha *novoNo;
    novoNo = malloc(sizeof(struct noPilha));
    // malloc retorna null quando não houver memória disponível para alocação ou quando ocorrer algum erro durante a alocação - execução do malloc
    if (novoNo == NULL)
        printf("Pilha Cheia!!!");
    else {
        novoNo->elemento = elemento;
        novoNo->prox = pilha->topo;
        pilha->topo = novoNo;
    }
}
// O ponteiro topo aponta para o endereço de memória do novo elemento

void pop(Pilha *pilha, int *elemento) {
    struct noPilha *aux;
    if (vazia(pilha))
        printf("Pilha Vazia - Não há elementos para desempilhar!!!");
    else {
        aux = pilha->topo;
        *elemento = aux->elemento;  // conteúdo do elemento topo da pilha
        pilha->topo = pilha->topo->prox;
        free(aux);
    }
}

void obterTopo(Pilha *pilha, int *elemento) {
    if (vazia(pilha))
        printf("Pilha Vazia - Não há elementos para desempilhar!!!");
    else
        *elemento = pilha->topo->elemento;
}
// Retorna o conteúdo do elemento que está no topo da pilha

int main(void) {
    Pilha P1;
    int var;
    inicializacao(&P1);
    push(&P1, 10);
    push(&P1, 20);
    push(&P1, 30);
    printf("Topo: %d \n", P1.topo->elemento);  // valor que o topo ta apontando
    for (struct noPilha *aux = P1.topo; aux != NULL; aux = aux->prox)
        printf("%d ", aux->elemento);

    pop(&P1, &var);
    printf("\n %d \n", var);
    printf("Topo: %d \n", P1.topo->elemento);  // valor que o topo ta apontando
    for (struct noPilha *aux = P1.topo; aux != NULL; aux = aux->prox)
        printf("%d ", aux->elemento);
}