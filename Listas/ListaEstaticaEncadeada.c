#include <stdio.h>
#define MAX 15

struct registro {
    int elemento;
    int proximo;
};
struct lista {
    int disponivel;
    int primeiro;
    struct registro A[MAX];
};

void InicializarLista(struct lista *lista) {
    int i = 0;
    lista->disponivel = 0;
    lista->primeiro = -1;
    for (i = 0; i < MAX - 1; i++) {
        lista->A[i].proximo = i + 1;
    }
    lista->A[i].proximo = -1;
}

void InsereElemento(struct lista *lista, int elemento) {
    if (lista->disponivel != -1) {
        if (lista->primeiro == -1) {
            lista->primeiro = 0;
        }
        lista->A[lista->disponivel].proximo = lista->disponivel;
        lista->A[lista->disponivel].elemento = elemento;
        lista->A[lista->disponivel + 1].proximo = -1;
    }
}

void Print(struct lista *lista) {
    int index = lista->primeiro;
    if (lista->primeiro == -1) {
        printf("Nao ha elementos na lista");
    } else {
        while (lista->A[index].proximo != -1) {
            printf("Elemento: %d\n", lista->A[index].elemento);
            index=lista->A[index].proximo;
        }
    }
}
int main(void) {
    struct lista listaTeste;
    InicializarLista(&listaTeste);
    // printf("Disponivel: %d", listaTeste.disponivel);
    // printf("\nPrimeiro: %d", listaTeste.primeiro);
    InsereElemento(&listaTeste, 10);
    InsereElemento(&listaTeste, 20);
    Print(&listaTeste);
}