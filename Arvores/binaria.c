#include <stdio.h>
#include <stdlib.h>

struct no {
    int elemento;
    struct no *direita;
    struct no *esquerda;
};

// typedef struct no* arvore;
typedef struct no no;

no *criano() {
    no *newno = (no *)malloc(sizeof(no));
    newno->esquerda = NULL;
    newno->direita = NULL;
    return newno;
}

void preordem(no *raiz) {
    if (raiz == NULL) {
        return 0;
    }
    if (raiz != NULL) {
        printf("%d\n", raiz->elemento);
        preordem(raiz->esquerda);
        preordem(raiz->direita);
    }
}

void emordem(no *raiz) {
    if (raiz == NULL) {
        return 0;
    }
    if (raiz != NULL) {
        emordem(raiz->esquerda);
        printf("%d\n", raiz->elemento);

        emordem(raiz->direita);
    }
}

void posordem(no *raiz) {
    if (raiz == NULL) {
        return 0;
    }
    if (raiz != NULL) {
        posordem(raiz->esquerda);
        posordem(raiz->direita);
        printf("%d\n", raiz->elemento);
    }
}
int main(void) {
    no *arvore;
    arvore = criano();
    arvore->elemento = 1;
    arvore->direita = criano();
    arvore->esquerda = criano();
    arvore->esquerda->elemento = 2;
    arvore->direita->elemento = 3;
    // printf("%d",arvore->elemento);
    printf("Pre ordem\n");
    preordem(arvore);
    printf("Em ordem\n");
    emordem(arvore);
    printf("Pos ordem\n");
    posordem(arvore);
    return 0;
}