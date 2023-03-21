#include <stdio.h>
#define MAX 15

struct registro {
    int elemento;
    int proximo;
};
struct lista {
    // tamanho representa a quantidade de elementos ja na lista
    int tamanho;
    int disponivel;
    int primeiro;
    struct registro A[MAX];
};

void InicializarLista(struct lista *lista) {
    int i = 0;
    lista->disponivel = 0;
    lista->primeiro = -1;
    lista->tamanho = 0;
    for (i = 0; i < MAX - 1; i++) {
        lista->A[i].proximo = i + 1;
    }
    lista->A[i].proximo = -1;
}

void InsereElemento(struct lista *lista, int elemento) {
    if (lista->tamanho < MAX) {
        if (lista->primeiro = -1) {
            lista->primeiro = lista->disponivel;
            lista->disponivel = lista->disponivel + 1;
            lista->A[lista->primeiro].elemento = elemento;
        }
        lista->disponivel++;
        lista->A[lista->disponivel].elemento = elemento;
        lista->A[lista->disponivel].proximo = -1;
        lista->tamanho++;
    } else {
        printf("Lista cheia\n");
    }
}

void InsereElementoCorreto(struct lista *lista, int elemento) {
    lista->A[lista->disponivel].elemento = elemento;
    int auxiliar = lista->A[lista->disponivel].proximo;
    lista->A[lista->disponivel].proximo = -1;
    lista->tamanho= lista->tamanho +1;
    // Se prim != -1 entao
    if (lista->primeiro = -1) {
        int i, anterior = -1;
        i = lista->primeiro;
        while (i != -1 && lista->A[i].elemento < elemento) {
            anterior = i;
            i = lista->A[i].proximo;
        }
        if (anterior != -1) {
            lista->A[lista->disponivel].proximo = lista->primeiro;
            lista->primeiro = lista->disponivel;
        } else {
            if (i != -1) {
                lista->A[lista->disponivel].proximo = lista->A[anterior].proximo;
            }
            lista->A[anterior].proximo = lista->disponivel;
        }
    } else {
        lista->primeiro = lista->disponivel;
    }
    lista->disponivel = auxiliar;
}

void PrintLista(struct lista *lista) {
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
    for(int i=0;i<MAX;i++){
        InsereElementoCorreto(&listaTeste,i+10);
    }
    printf("Primeiro elemento: %d\nDisponivel: %d", listaTeste.primeiro, listaTeste.disponivel);
    for (int i = 0; i < MAX; i++) {
        printf("\nElemento %d\nProximo %d\n", listaTeste.A[i].elemento, listaTeste.A[i].proximo);
    }
    PrintLista(&listaTeste);
}