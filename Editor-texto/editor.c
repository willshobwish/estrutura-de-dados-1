#include <stdio.h>
#include <stdlib.h>

struct strdim {
    char elemento;
    struct strdim *proximo;
    struct strdim *anterior;
};

typedef struct strdim strdim;

void insere(strdim *string, char elemento) {
    strdim *inicio = string,*auxiliar=malloc(sizeof(strdim));
    while (inicio != NULL) {
        inicio = inicio->proximo;
    }
    auxiliar->elemento=elemento;
    auxiliar->anterior=inicio;
    inicio->proximo=auxiliar;
}

int main(void) {
}