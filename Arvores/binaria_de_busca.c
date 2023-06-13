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

void insere(no *raiz, int elemento) {
    no *atual = raiz, *anterior = NULL, *novo = (no*)cria_no(elemento);
    if (raiz == NULL) {
        // Caso a raiz seja nula
        raiz = novo;
    }
    while (atual != NULL) {
        // Percorre ate o pai da folha pra ser inserido
        anterior = atual;
        if (elemento == atual->elemento) {
            printf("Elemento repetido\n");
            free(novo);
            return;
        }
        if (elemento > atual->elemento) {
            // Caso o elemento a ser inserido seja maior que o no atual, percorre a esquerda
            atual = atual->direita;
        } else {
            // Caso contrario ele eh percorrido a esquerda, que eh menor
            atual = atual->esquerda;
        }
    }
    // Aqui eh inserido o elemento na folha
    if (elemento > anterior->elemento) {
        // Caso o elemento seja maior que o pai, eh inserido na direita
        anterior->direita = novo;
    } else {
        // Caso contrario ele eh menor que o pai, eh inserido na esquerda
        anterior->esquerda = novo;
    }
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
        // printf("Nao ha no\n");
        return;
    }
    if (no != NULL) {
        libera(no->esquerda);
        libera(no->direita);
        printf("O no com elemento %d foi liberado\n",no->elemento);
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
// no* cria_ArvBin(){
//     no* raiz = (no*) malloc(sizeof(no));
//     if(raiz != NULL)
//         *raiz = NULL;
//     return raiz;
// }

int main(void) {
    no *arvore;
    // arvore->direita=NULL;
    // arvore->esquerda=NULL;
    // arvore->elemento=NULL;
    // arvore = cria_no(1);
    insere(arvore, 10);
    insere(arvore, 20);
    insere(arvore, 30);
    insere(arvore, 40);
    insere(arvore, 50);
    // insere(arvore, 50);
    // arvore->elemento = 1;
    // arvore->esquerda = cria_no(2);
    // arvore->direita = cria_no(4);
    // arvore->esquerda->elemento = 2;
    // arvore->direita->elemento = 3;
    // arvore->esquerda->esquerda = cria_no(3);
    // printf("%d",arvore->elemento);
    printf("Pre ordem\n");
    pre_ordem(arvore);
    // printf("Em ordem\n");
    // em_ordem(arvore);
    // printf("Pos ordem\n");
    // pos_ordem(arvore);
    printf("Altura da arvore: %d\n", altura(arvore));
    printf("Total de nos: %d\n", total_no(arvore));
    libera(arvore);
    return 0;
}