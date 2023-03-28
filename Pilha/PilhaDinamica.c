#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct
{
    int elemento;
    struct nodePilha *prox;
}nodePilha;

typedef struct 
{
    nodePilha *topo;
}Pilha;

void Inicializacao(Pilha *pilha){
    pilha->topo = NULL;
}

bool Vazia(Pilha *pilha){
    if(pilha->topo == NULL){
        return true;
    }else{
        return false;
    }
}

bool Cheia(Pilha *pilha){
    nodePilha *newNode = malloc(sizeof(pilha));
    if(newNode == NULL){
        printf("Nao foi possivel alocar memoria");
        return true;
    }else{
return false;
    }
}
void Push();
int main(void){

}