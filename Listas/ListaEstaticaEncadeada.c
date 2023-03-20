#include <stdio.h>
#define MAX 15

struct registro {
    int elemento;
    int proximo;
};
struct lista {
    int info;
    int disponivel;
    int primeiro;
    struct registro A[MAX];
};

void InicializarLista(struct lista *lista) {
    int i = 0;
    lista->disponivel = 0;
    lista->primeiro = -1;
    lista->info = 0;
    for (i = 0; i < MAX - 1; i++) {
        lista->A[i].proximo = i + 1;
    }
    lista->A[i].proximo = -1;
}

void InsereElemento(struct lista *lista, int elemento) {
    if (lista->info < MAX) {
        if (lista->primeiro = -1) {
            lista->primeiro = lista->disponivel;
            lista->disponivel = lista->disponivel + 1;
            lista->A[lista->primeiro].elemento = elemento;
        }
        lista->A[lista->disponivel].elemento = elemento;
        lista->A[lista->disponivel].proximo = lista->disponivel + 1;
        lista->info++;
    } else {
        printf("Lista cheia");
    }
}

void Print(struct lista *lista) {
    int index = lista->primeiro;
    if (lista->primeiro == -1) {
        printf("Nao ha elementos na lista");
    } else {
        while (lista->A[index].proximo != -1) {
            printf("Elemento: %d\n", lista->A[index].elemento);
            index = lista->A[index].proximo;
        }
    }
}
int main(void) {
    struct lista listaTeste;
    InicializarLista(&listaTeste);
    for (int i = 0; i <= MAX; i++) {
        InsereElemento(&listaTeste, i + 10);
    }
    for (int i = 0; i < MAX; i++) {
        printf("\nElemento %d\nProximo %d\n", listaTeste.A[i].elemento, listaTeste.A[i].proximo);
    }
}