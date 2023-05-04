#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct noFila{
    int elemento;
    int prioridade;
    struct noFila *prox;
};

typedef struct {
    struct noFila *inicio;
    struct nofila *fim;
}FilaP;

void inicializacao(FilaP *fila){
    fila->inicio=NULL;
    fila->fim = NULL;    
}

bool vazia(FilaP *fila){
    if(fila->inicio==NULL){
        return true;
    }else{
        return false;
    }
}
bool cheia(FilaP *fila){
    struct noFila *novoNo;
    novoNo = malloc(sizeof(struct noFila));
    if(novoNo == NULL){
        return true;
    }else{
        return false;
    }
}

void inserir(FilaP *fila, int elemento, int prioridade){
    struct noFila *novoNo, *aux, *anterior;
    novoNo = malloc(sizeof(struct noFila));
    if(novoNo == NULL){
        printf("Fila cheia");
    }else{
        novoNo->prox = NULL;
        novoNo->prioridade=prioridade;
        novoNo->elemento=elemento;
        aux = fila->inicio;
        anterior=NULL;
        while((aux!=NULL)&&(aux->prox>=prioridade)){
anterior=aux;
aux=aux->prox;

        }
    }
}

int main(void){

}