#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct nodeFila{
    int elemento;
    struct nodeFila *proximo;
};

typedef struct {
    struct nodeFila *inicio;
    struct nodeFila *fim;
}Fila;

void inicializacao(Fila *fila){
    fila->inicio = NULL;
    fila->fim = NULL;
}

bool vazia(Fila *fila){
    if(fila->inicio == NULL) return true;
    else return false;
}

void inserir(Fila *fila, int elemento){
    struct nodeFila *newNode = malloc(sizeof(struct nodeFila));
    if(newNode == NULL) printf("Nao ha memoria\n");
    else{
        newNode->elemento = elemento;
        newNode->proximo = NULL;
        if(vazia(fila)) fila->inicio = newNode;
        else fila->fim->proximo = newNode;
        fila->fim=newNode;
    }
}

void remover(Fila *fila, int *elemento){
    struct nodeFila *auxiliar;
    if(vazia(fila)) printf("Nao ha elementos para remover na fila\n");
    else{
        auxiliar = fila->inicio;
        *elemento = auxiliar->elemento;
        fila->inicio = fila->inicio->proximo;
        free(auxiliar);
    }
}

void obter_inicio_fila(Fila *fila, int *elemento){
    if(vazia(fila) )printf("Nao ha elementos na fila\n");
    else{
        *elemento = fila->inicio->elemento;
    }
}

void verifica_chegada(){

}

void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;
 
    // Storing start time
    clock_t start_time = clock();
 
    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds);
}

int main(void){
    int tempo_de_simulacao = 500, tempo_atual=0, atendimento_caixa[4];
    while(tempo_atual<=tempo_de_simulacao){
        printf("Tempo atual: %d\n",tempo_atual);
        tempo_atual++;
        delay(1);
    }

}