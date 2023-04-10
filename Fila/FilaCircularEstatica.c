#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


#define MAX 10

typedef struct {
    int ElementosFila[MAX];
    int inicio;
    int fim;
} Fila;

void inicializacao(Fila *fila) {
    fila->inicio = 0;
    fila->fim = 0;
}

bool vazia(Fila *fila) {
    if (fila->inicio == fila->fim) {
        return true;
    } else {
        return false;
    }
}

bool cheio(Fila *fila) {
    if (fila->fim == MAX) {
        return true;
    } else {
        return false;
    }
}

void inserir(Fila *fila, int elemento) {
    if (cheio(fila)) {
        printf("Lista cheia\n");
    } else {
        fila->ElementosFila[fila->fim] = elemento;
        fila->fim++;
    }
}

void remover(Fila *fila, int *elemento) {
    if (vazia(fila)) {
        printf("Lista vazia");
    } else {
        *elemento = fila->ElementosFila[fila->inicio];
        fila->inicio++;
    }
}

void obterInicioFila(Fila *fila, int *elemento) {
    if (vazia(fila)) {
        printf("Lista vazia");
    } else {
        *elemento = fila->ElementosFila[fila->inicio];
    }
}

int main(void){

}