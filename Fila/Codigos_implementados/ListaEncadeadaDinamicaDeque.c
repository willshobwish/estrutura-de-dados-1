#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct no_deque {
    int elemento;
    struct no_deque *proximo;
};

 struct fila_deque
{
    struct no_deque *inicio;
    struct no_deque *fim;
};

typedef struct fila_deque fila_deque;

void inicializacao_deque(fila_deque *fila_deque) {
    fila_deque->inicio = NULL;
    fila_deque->fim = NULL;
}

bool vazia_deque(fila_deque *fila_deque) { 
    if (fila_deque->inicio == NULL)
        return true;
    else
        return false;
}

bool cheio_deque(fila_deque *fila_deque) {
    struct no_deque *novo_no_deque;
    novo_no_deque = malloc(sizeof(struct no_deque));
    if (novo_no_deque == NULL)
        return true;
    else
        return false;
}

void inserir_final(fila_deque *fila_deque, int elemento) {
    struct no_deque *novo_no_deque;
    novo_no_deque = malloc(sizeof(struct no_deque));
    if (novo_no_deque == NULL)
        printf("Deque cheio\n");
    else {
        novo_no_deque->elemento = elemento;
        novo_no_deque->proximo = NULL;
        if (vazia_deque(fila_deque))
            fila_deque->inicio = novo_no_deque;
        else
            fila_deque->fim->proximo = novo_no_deque;
        fila_deque->fim = novo_no_deque;
    }
}

void inserir_comeco(fila_deque *fila_deque, int elemento) {
    struct no_deque *novo_no_deque;
    novo_no_deque = malloc(sizeof(struct no_deque));
    if (novo_no_deque == NULL)
        printf("Deque cheio\n");
    else {
        novo_no_deque->elemento = elemento;
        if (vazia_deque(fila_deque)){
            fila_deque->inicio = novo_no_deque;
        }
        else{
            novo_no_deque->proximo = fila_deque->inicio;
        }
            fila_deque->inicio = novo_no_deque;
    }
}

void remover_comeco(fila_deque *fila_deque, int *elemento) {
    struct no_deque *auxiliar;
    if (vazia_deque(fila_deque))
        printf("Deque vazio\n");
    else {
        auxiliar = fila_deque->inicio;
        *elemento = auxiliar->elemento;
        fila_deque->inicio = fila_deque->inicio->proximo;
        free(auxiliar);
    }
}

void remover_final(fila_deque *fila_deque, int *elemento) {
    struct no_deque *auxiliar,*anterior;
    if (vazia_deque(fila_deque))
        printf("Deque vazio\n");
    else {
        auxiliar = fila_deque->inicio;
        while(auxiliar->proximo!=NULL){
            anterior=auxiliar;
            auxiliar=auxiliar->proximo;
        }
        *elemento = auxiliar->elemento;
        fila_deque->fim = anterior;
        free(auxiliar);
    }
}

// Retorna o elemento que está no inicio da fila_deque
void obter_inicio_deque(fila_deque *fila_deque, int *elemento) {
    if (vazia_deque(fila_deque))
        printf("Deque vazio\n");
    else
        *elemento = fila_deque->inicio->elemento;
}

int main(void) {
    int elemIni, elemRem;
    struct no_deque *i = NULL;
    fila_deque F1;
    inicializacao_deque(&F1);
    // Inserindo valores na fila_deque
    inserir_comeco(&F1, 10);

    inserir_final(&F1, 1);
    inserir_final(&F1, 1);
    inserir_final(&F1, 2);
    inserir_final(&F1, 3);
    inserir_final(&F1, 5);
    inserir_final(&F1, 8);
    inserir_final(&F1, 13);
    inserir_final(&F1, 21);
    inserir_final(&F1, 34);
    inserir_final(&F1, 55);
    // Imprimindo a fila
    printf("\nInicio (valor elem): %d", F1.inicio->elemento);
    printf("\nFim (valor elem): %d\n", F1.fim->elemento);
    for (i = F1.inicio; i != NULL; i = i->proximo)
        printf("%d ", i->elemento);

    return (0);
}