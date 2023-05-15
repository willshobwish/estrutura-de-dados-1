#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct caractere {
    char elemento;
    struct caractere *proximo;
};

typedef struct {
    struct caractere *inicio;
    struct caractere *fim;
} string;

void inicializacao(string *palavra) {
    palavra->inicio = NULL;
    palavra->fim = NULL;
}

bool vazia(string *palavra) {
    if (palavra->inicio == NULL)
        return true;
    else
        return false;
}

void inserir(string *palavra, char elemento) {
    struct caractere *newNode = malloc(sizeof(struct caractere));
    if (newNode == NULL)
        printf("Nao ha memoria\n");
    else {
        newNode->elemento = elemento;
        newNode->proximo = NULL;
        if (vazia(palavra))
            palavra->inicio = newNode;
        else
            palavra->fim->proximo = newNode;
        palavra->fim = newNode;
    }
}

void remover(string *palavra, char *elemento) {
    struct caractere *auxiliar;
    if (vazia(palavra))
        printf("Nao ha elementos para remover na palavra\n");
    else {
        auxiliar = palavra->inicio;
        *elemento = auxiliar->elemento;
        palavra->inicio = palavra->inicio->proximo;
        free(auxiliar);
    }
}

void obterInicioFila(string *palavra, char *elemento) {
    if (vazia(palavra))
        printf("Nao ha elementos na palavra\n");
    else {
        *elemento = palavra->inicio->elemento;
    }
}

void imprimir(string *palavra) {
    struct caractere *aux = palavra->inicio;
    while (aux != NULL) {
        printf("%c", aux->elemento);
        aux = aux->proximo;
    }
    printf("\n");
}

int main(void) {
    string palavra;
    inicializacao(&palavra);
    inserir(&palavra,'a');
    inserir(&palavra,'b');
    inserir(&palavra,'c');
    imprimir(&palavra);
    return 0;
}