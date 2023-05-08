#include <stdio.h>
#include<stdlib.h>

struct nodePilha{
    int elemento;
    struct nodePilha *proximo;
};

typedef struct Pilha{
    struct nodePilha *topo;
}Pilha;

void inicializa(Pilha *pilha){
    pilha=NULL;
}

void push(Pilha *pilha, int elemento){
    struct nodePilha *novo;
    novo = malloc(sizeof(struct nodePilha));
    if(novo==NULL){
        printf("Erro na alocacao");
    }else{
        novo->elemento = elemento;
        novo->proximo = pilha->topo;
        pilha->topo = novo;
    }
}

void imprime(Pilha *pilha){
    struct nodePilha *aux = pilha->topo;
    while (aux!=NULL)
    {
        printf("Elemento: %d\n",aux->elemento);
        aux = aux->proximo;
    }
}

int pop(Pilha *pilha){
    int elemento;
    struct nodePilha *aux=pilha->topo;
    if(aux == NULL){
        printf("Nao ha elementos");
    }else{
        elemento = aux->elemento;
        pilha->topo = aux->proximo;
        free(aux);
    }
    return elemento;
}

int main(void){
    Pilha pilha;
    inicializa(&pilha);
    push(&pilha,10);
    push(&pilha,20);
    push(&pilha,30);
    imprime(&pilha);
    printf("Removido: %d\n",pop(&pilha));
    imprime(&pilha);

}