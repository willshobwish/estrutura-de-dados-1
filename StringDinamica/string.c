#include <stdio.h>
#include <stdlib.h>

struct strdim {
    char c;
    struct strdim *prox;
};

void adicionar(struct strdim *string, char elemento) {
    struct strdim *auxiliar = string,*novo=malloc(sizeof(struct strdim));
    while (auxiliar->prox != NULL) {
        auxiliar = auxiliar->prox;
    }
    novo->c = elemento;
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

void adicionarPalavra(struct strdim *string, char palavra[]){
    for(int i=0;i<sizeof(palavra)/sizeof(char);i++){
        adicionar(string,palavra[i]);
    }
}

int main(void) {
    struct strdim string;
    // adicionarPalavra(&string,"tretse");
    adicionar(&string,'a');
    imprime(&string);
}