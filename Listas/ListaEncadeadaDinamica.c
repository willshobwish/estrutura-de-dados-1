#include <stdio.h>
#include <stdlib.h>

#define MAX 15

struct lista {
    // tamanho representa a quantidade de elementos ja na lista
    int elemento;
    struct lista *proximo;
};

void insereElemento(struct lista *lista,int elemento){
    while(lista->proximo!=NULL){
        insereElemento(lista,elemento);
    }
}

int main(void){
    struct lista *listaTeste = malloc(sizeof(struct lista));
    if(listaTeste == NULL){
        printf("Nao foi possivel alocar");

    }else{
        printf("Alocado em: %p\n",*listaTeste);
    }
    listaTeste->elemento = 50;
    listaTeste->proximo = NULL;
    printf("Elemento: %d\nProximo elemento: %p\n",listaTeste->elemento,listaTeste->proximo);
    listaTeste->proximo = malloc(sizeof(struct lista));
    listaTeste->proximo->elemento=60;
    printf("Elemento: %d",listaTeste->proximo->elemento);

}