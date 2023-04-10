#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct nodeFila{
    int elemento;
    struct nodeFila *proximo;
};

typedef struct {
    struct nodeFila *inicio;
    struct nodeFila *fim;
}Fila;

void inicializacao(Fila *fila){
    fila->inicio = NULL;
    fila->fim = NULL;
}

bool vazia(Fila *fila){
    if(fila->inicio == NULL) return true;
    else return false;
}

void inserir(Fila *fila, int elemento){
    struct nodeFila *newNode = malloc(sizeof(struct nodeFila));
    if(newNode == NULL) printf("Nao ha memoria\n");
    else{
        newNode->elemento = elemento;
        newNode->proximo = NULL;
        if(vazia(fila)) fila->inicio = newNode;
        else fila->fim->proximo = newNode;
        fila->fim=newNode;
    }
}

void remover(Fila *fila, int *elemento){
    struct nodeFila *auxiliar;
    if(vazia(fila)) printf("Nao ha elementos para remover na fila\n");
    else{
        auxiliar = fila->inicio;
        *elemento = auxiliar->elemento;
        fila->inicio = fila->inicio->proximo;
        free(auxiliar);
    }
}

void obterInicioFila(Fila *fila, int *elemento){
    if(vazia(fila) )printf("Nao ha elementos na fila\n");
    else{
        *elemento = fila->inicio->elemento;
    }
}

int main(void){

}