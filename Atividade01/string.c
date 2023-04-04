#include <stdio.h>
#include <stdlib.h>

struct strdim {
    char c;
    struct strdim *prox;
};

void adicionar(struct strdim *string, char elemento) {
    struct strdim *auxiliar = string;
    while (auxiliar->prox != NULL) {
        auxiliar = auxiliar->prox;
    }
    auxiliar->c = elemento;
    auxiliar->prox = malloc(sizeof(struct strdim));
    auxiliar = auxiliar->prox;
    auxiliar->prox = NULL;
}

void imprime(struct strdim *string) {
    struct strdim *auxiliar = string;

    while (auxiliar->prox != NULL) {
        printf("%c", auxiliar->c);
        auxiliar = auxiliar->prox;
    }
}

int main(void) {
    struct strdim string;

    adicionar(&string, 'a');
    adicionar(&string, 'b');
    adicionar(&string, 'c');
    adicionar(&string, 'd');
    adicionar(&string, 'e');
    imprime(&string);
}