#include <stdio.h>
#include <stdlib.h>

struct no {
    int elemento;
    struct no *direita;
    struct no *esquerda;
};

// typedef struct no* arvore;
typedef struct no no;

no *cria_no(int elemento) {
    no *newno = (no *)malloc(sizeof(no));
    newno->esquerda = NULL;
    newno->direita = NULL;
    newno->elemento = elemento;
    return newno;
}

void pre_ordem(no *raiz) {
    // Executa o tratamento na raiz, visita o filho na esquerda e depois visita o filho na direita
    if (raiz == NULL) {
        return;
    }
    if (raiz != NULL) {
        printf("%d\n", raiz->elemento);
        pre_ordem(raiz->esquerda);
        pre_ordem(raiz->direita);
    }
}

void em_ordem(no *raiz) {
    // Executa o visita o filho na esquerda, faz tratamento na raiz e depois visita o filho na direita
    if (raiz == NULL) {
        return;
    }
    if (raiz != NULL) {
        em_ordem(raiz->esquerda);
        printf("%d\n", raiz->elemento);

        em_ordem(raiz->direita);
    }
}

void pos_ordem(no *raiz) {
    // Executa a visita o filho na esquerda, depois visita o filho na direita e faz tratamento na raiz
    if (raiz == NULL) {
        return;
    }
    if (raiz != NULL) {
        pos_ordem(raiz->esquerda);
        pos_ordem(raiz->direita);
        printf("%d\n", raiz->elemento);
    }
}

void libera(no *no) {
    if (no == NULL) {
        printf("Nao ha no\n");
    }
    if (no != NULL) {
        libera(no->esquerda);
        libera(no->direita);
        free(no);
        no = NULL;
    }
}

int altura(no *node) {
    if (node == NULL) {
        return 0;
    }
    int altura_esquerda = altura(node->esquerda);
    int altura_direita = altura(node->direita);
    if (altura_esquerda > altura_direita) {
        return (altura_esquerda + 1);
    } else {
        return (altura_direita + 1);
    }
}

int total_no(no *node) {
    if (node == NULL) {
        return 0;
    }
    int altura_esquerda = total_no(node->esquerda);
    int altura_direita = total_no(node->direita);
    return (altura_esquerda + altura_direita + 1);
}
int main(void) {
    no *arvore;
    arvore = cria_no(1);
    // arvore->elemento = 1;
    arvore->esquerda = cria_no(2);
    arvore->direita = cria_no(4);
    // arvore->esquerda->elemento = 2;
    // arvore->direita->elemento = 3;
    arvore->esquerda->esquerda = cria_no(3);
    // printf("%d",arvore->elemento);
    printf("Pre ordem\n");
    pre_ordem(arvore);
    printf("Em ordem\n");
    em_ordem(arvore);
    printf("Pos ordem\n");
    pos_ordem(arvore);
    printf("Altura da arvore: %d\n",altura(arvore));
    printf("Total de nos: %d\n", total_no(arvore));
    libera(arvore);
    return 0;
}