#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define CAIXA
#define CLIENTES 20
#define TEMPO_SIMULACAO

struct nodeFila {
    int elemento;
    struct nodeFila *proximo;
};

typedef struct {
    struct nodeFila *inicio;
    struct nodeFila *fim;
} Fila;

void inicializacao(Fila *fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
}

bool vazia(Fila *fila) {
    if (fila->inicio == NULL)
        return true;
    else
        return false;
}

void inserir(Fila *fila, int elemento) {
    struct nodeFila *newNode = malloc(sizeof(struct nodeFila));
    if (newNode == NULL)
        printf("Nao ha memoria\n");
    else {
        newNode->elemento = elemento;
        newNode->proximo = NULL;
        if (vazia(fila))
            fila->inicio = newNode;
        else
            fila->fim->proximo = newNode;
        fila->fim = newNode;
    }
}

void remover(Fila *fila, int *elemento) {
    struct nodeFila *auxiliar;
    if (vazia(fila))
        printf("Nao ha elementos para remover na fila\n");
    else {
        auxiliar = fila->inicio;
        *elemento = auxiliar->elemento;
        fila->inicio = fila->inicio->proximo;
        free(auxiliar);
    }
}

void obter_inicio_fila(Fila *fila, int *elemento) {
    if (vazia(fila))
        printf("Nao ha elementos na fila\n");
    else {
        *elemento = fila->inicio->elemento;
    }
}

void verifica_chegada() {
}

void delay(int number_of_seconds) {
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
}

int random_number(int intervalo) {
    return rand() % intervalo;
}

void operacao(Fila *fila) {
    switch (random_number(3)) {
        case 0:
            // Saque
            inserir(fila, 5);
            break;
        case 1:
            // Deposito
            inserir(fila, 7);

            break;
        case 2:
            // Transacao
            inserir(fila, 10);
            break;

        default:
            break;
    }
}

void tipo_operacao(int operacao, char *string) {
    switch (operacao) {
        case 5:
            // Saque
            strcpy(string,"saque"); 
            break;
        case 7:
            // Deposito
            strcpy(string,"deposito"); 
            break;
        case 10:
            // Transacao
            strcpy(string,"transacao"); 
            break;

        default:
            break;
    }
}

int main(void) {
    // setlocale(LC_ALL,"Portuguese");
    srand(time(NULL));
    Fila fila[4];
    Fila fila_teste;
    inicializacao(&fila_teste);
    int tempo_de_simulacao = 100, tempo_atual = 0, intervalo = 10, elemento = 0, cliente_atual = 0, clientes_atendidos = -1;
    float tempo_medio = 0;
    char nome_operacao[50];
    // for (int i = 0; i < 4; i++) {
    //     inicializacao(&fila[i]);
    // }
    // for (int i = 0; i < 4; i++) {
    //     for (int i = 0; i < 10; i++) {
    //         operacao(&fila[i]);
    //     }
    // }

    // for (int i = 0; i < 10; i++) {
    //     remover(&fila, &elemento);
    //     printf("Operacao: %d\n", elemento);
    // }
    for (int i = 0; i < CLIENTES; i++) {
        operacao(&fila_teste);
    }
    while (tempo_atual <= tempo_de_simulacao) {
        printf("\nTempo atual: %d\n", tempo_atual);

        if (!vazia(&fila_teste)) {
            if (elemento <= 0) {
                remover(&fila_teste, &elemento);
                tipo_operacao(elemento,nome_operacao);
                tempo_medio += elemento;
                cliente_atual++;
                clientes_atendidos++;
            } else {
                printf("Cliente atual: %d\nOperacao: %s\nTempo restante da operacao: %d\n", cliente_atual, nome_operacao,elemento);
                elemento--;
                // delay(1);
            }
        }
        tempo_atual++;
    }
    printf("\nQuantidade de clientes atendidos: %d\nQuantidade de clientes nao atendidos: %d\nTempo de simulacao: %d\nTempo medio de espera: %.2f", clientes_atendidos, CLIENTES - clientes_atendidos, tempo_de_simulacao, tempo_medio / CLIENTES);
}