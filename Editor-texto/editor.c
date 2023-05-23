#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct strdim {
    char elemento;
    struct strdim *proximo;
    struct strdim *anterior;
};

typedef struct strdim strdim;

void inicializa(strdim *string) {
    string->elemento = NULL;
    string->proximo = NULL;
    string->anterior = NULL;
}

void insere(strdim *string, char elemento) {
    strdim *auxiliar = string, *novo = malloc(sizeof(strdim));
    novo->proximo = NULL;
    novo->elemento = elemento;
    while (auxiliar->proximo != NULL) {
        auxiliar = auxiliar->proximo;
    }
    novo->anterior = auxiliar;
    auxiliar->proximo = novo;
}

void insere_palavra(strdim *string, char palavra[]) {
    int i = 0;
    while (palavra[i] != '\0') {
        insere(string, palavra[i]);
        i++;
    }
}

void imprime(strdim *string) {
    strdim *auxiliar = string;
    while (auxiliar != NULL) {
        printf("%c", auxiliar->elemento);
        auxiliar = auxiliar->proximo;
    }
    printf("\n");
}

bool string_igual(strdim *string1, strdim *string2) {
    bool resultado = false;
    strdim *aux1 = string1, *aux2 = string2;
    while (aux1 != NULL) {
        if (aux1->elemento == aux2->elemento) {
            resultado = true;
        } else {
            resultado = false;
            break;
        }
        aux1 = aux1->proximo;
        aux2 = aux2->proximo;
    }
    return resultado;
}

int main(void) {
    strdim string;
    inicializa(&string);
    insere_palavra(&string, "abelha");
    imprime(&string);
    return 0;
}