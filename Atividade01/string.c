#include <stdio.h>
#include <stdlib.h>
struct strdim {
    char c;
    struct strdim *proximo;
    struct strdim *anterior;
};

struct strdim *Inicializa() {
    struct strdim *string = malloc(sizeof(struct strdim));
    string->anterior = NULL;
    string->proximo = malloc(sizeof(struct strdim));
    return string;
}

void Insere(struct strdim *string, char elemento) {
    struct strdim *anterior, *proximo,**auxiliar=&string,*novo=malloc(sizeof(struct strdim));
    while (auxiliar->proximo!=NULL){
        anterior = auxiliar->anterior;
        auxiliar = auxiliar->proximo;
        proximo = auxiliar->proximo;
        printf("Anterior: %p\nAtual: %p\nProximo: %p\n\n",anterior,auxiliar,proximo);
    }proximo = novo;
    proximo->proximo=NULL;
    auxiliar->c = elemento;
}

void Imprime(struct strdim *string) {
    struct strdim *anterior, *proximo, *atual = string;
    while (atual->proximo != NULL) {
        anterior = string->anterior;
        atual = string->proximo;
        proximo = atual->proximo;
        printf("Caractere armazenado: %c\n", atual->c);
    }
}
int main(void) {
    struct strdim *string = Inicializa();
    Insere(string, 'a');
    Insere(string, 'b');
    Imprime(string);
}