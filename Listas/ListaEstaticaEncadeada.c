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

void Remove(struct lista *lista, int elemento) {
    // Caso a lista nao seja vazia
    if (lista->primeiro != -1) {
        int auxiliar = lista->primeiro;
        int anterior;
        while (lista->A[auxiliar].elemento < elemento && lista->A[auxiliar].proximo != -1) {
            anterior = auxiliar;
            auxiliar = lista->A[auxiliar].proximo;
        }
        if (lista->A[auxiliar].elemento == elemento) {
            lista->primeiro = auxiliar;

        } else {
            lista->A[anterior].proximo = lista->A[auxiliar].proximo;
        }
        int disponivel = lista->disponivel;
        lista->disponivel = auxiliar;
        lista->A[auxiliar].proximo = disponivel;
    }
}

void Insere(struct lista *lista, int elemento) {
    // Verificacao de disponibilidade na lista
    if (lista->disponivel != -1) {
        // Armazena o indice disponivel
        int auxiliar = lista->disponivel;
        // Insere o elemento no indice disponivel
        lista->A[auxiliar].elemento = elemento;
        // Modifica o indice disponivel para o indice apontado pelo proximo
        lista->disponivel = lista->A[auxiliar].proximo;
        int i = lista->primeiro;
        int anterior;
        if (lista->primeiro != -1) {
            // Enquanto nao encontrar o elemento na lista que seja maior que o elemento que esta inserindo, continuara
            while (lista->A[i].elemento < elemento) {
                // Necessita saber qual que eh o elemento anterior e qual sera o proximo elemento
                anterior = i;
                i = lista->A[i].proximo;
            }
        }
        // Caso o elemento inserido seja menor que o primeiro. Se o i for igual ao primeiro, isso quer dizer que o while nao foi executado
        if (i == lista->primeiro) {
            // Troca
            lista->A[auxiliar].proximo = lista->primeiro;
            lista->primeiro = auxiliar;
        } else {
            lista->A[anterior].proximo = lista->primeiro;
            lista->A[auxiliar].proximo = i;
        }
    } else {
        printf("Lista cheia");
    }
}

void InsereCorreto(struct lista *lista, int elemento) {
    int auxiliar, i, anterior;
    if (lista->disponivel != -1) {
        if (lista->tamanho < MAX) {
            lista->tamanho = lista->tamanho + 1;
            auxiliar = lista->disponivel;
            lista->A[auxiliar].elemento = elemento;
            lista->disponivel = lista->A[auxiliar].proximo;
            i = lista->primeiro;
            // Caso seja 
            if (lista->primeiro != -1) {
                while (lista->A[i].elemento < elemento) {
                    anterior = i;
                    i = lista->A[i].proximo;
                }
            }else{
                lista->primeiro=lista->disponivel;
            }
        } else {
            lista->disponivel = -1;
        }

    } else {
        printf("Lista cheia\n");
    }
}

void Impressao(struct lista *lista) {
    int auxiliar = lista->primeiro;
    if (lista->primeiro == -1) {
        printf("Nao ha elementos na lista");
    } else {
        while (lista->A[auxiliar].proximo != -1) {
            printf("Elemento: %d\n", lista->A[auxiliar].elemento);
            auxiliar = lista->A[auxiliar].proximo;
        }
    }
}
int main(void) {
    struct lista listaTeste;
    InicializarLista(&listaTeste);
    for (int i = 0; i < MAX - 1; i++) {
        InsereCorreto(&listaTeste, i + 10);
    }
    printf("Primeiro elemento: %d\nDisponivel: %d", listaTeste.primeiro, listaTeste.disponivel);
    for (int i = 0; i < MAX; i++) {
        printf("\nElemento %d\nProximo %d\n", listaTeste.A[i].elemento, listaTeste.A[i].proximo);
    }
    Impressao(&listaTeste);
}