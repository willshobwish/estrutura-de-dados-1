#include<stdio.h>
#include<stdlib.h>

struct no{
    int elemento;
    struct no *direita;
    struct no *esquerda;
};


// typedef struct no* arvore;
typedef struct no no;

void percorre(no *raiz){
    if(raiz==NULL){
        return 0;
        }
    if(raiz!=NULL){
        printf("%d\n",raiz->elemento);
        percorre(raiz->esquerda);
        percorre(raiz->direita);
    }
}

int main(void){
    no *arvore;
    arvore = malloc(sizeof(no));
    arvore->elemento = 1;
    arvore->direita = malloc(sizeof(no));
    arvore->esquerda = malloc(sizeof(no));
    arvore->direita->elemento=2;
    arvore->esquerda->elemento=3;
    // printf("%d",arvore->elemento);
    percorre(arvore);
    return 0;
}