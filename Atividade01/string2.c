#include <stdio.h>
#include <stdlib.h>

struct caractere{
    char letra;
    
}



void adicionar(struct strdim *string, char elemento) {
    struct strdim *auxiliar = string, *novo;
    novo = malloc(sizeof(struct strdim));
    novo->c = elemento;
    if (auxiliar == NULL) {
        // auxiliar = malloc(sizeof(struct strdim));
        auxiliar = novo;
    } else {
        while (auxiliar->prox != NULL) {
            auxiliar = auxiliar->prox;
        }
    }
    // auxiliar->prox = malloc(sizeof(struct strdim));
    novo->prox=NULL;
    auxiliar->prox = novo;
}

void imprime(struct strdim *string) {
    struct strdim *auxiliar = string;
    while (auxiliar->prox != NULL) {
        printf("%c", auxiliar->c);
        auxiliar = auxiliar->prox;
    }
}

void adicionarPalavra(struct strdim *string, char palavra[]) {
    for (int i = 0; i < sizeof(*palavra) / sizeof(char); i++) {
        adicionar(string, palavra[i]);
    }
}
void inicializar(struct strdim *string) {
    string = NULL;
}

int main(void) {
    struct strdim string;
    inicializar(&string);
    // printf("%x\n",string);
    adicionarPalavra(&string, "tretse");
    // adicionar(&string, 'a');
    // adicionar(&string, 'a');
    imprime(&string);
}