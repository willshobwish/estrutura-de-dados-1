#include <stdio.h>
#include <stdlib.h>

#define N 20
#define M 20

typedef struct no {
    int info, linha, coluna;
    struct no *direita;
    struct no *baixo;

} elemento;

typedef struct {
    elemento *linha[N];
    elemento *coluna[M];
} MatrizEsparsa;

void inicializarMatriz(MatrizEsparsa *matriz) {
    for (int i = 0; i < N; i++) {
        matriz->linha[i] = NULL;
    }
    for (int i = 0; i < M; i++) {
        matriz->coluna[i] = NULL;
    }
}

void insercao(MatrizEsparsa *matriz, int linha, int coluna, int informacao) {
    elemento *novo, *pontolinha, *pontocoluna, *anterior;
    novo = (elemento *)malloc(sizeof(elemento));
    novo->info = informacao;
    novo->linha = linha;
    novo->coluna = coluna;
    novo->direita = NULL;
    novo->baixo = NULL;
    pontocoluna = matriz->coluna[coluna];
    pontolinha = matriz->linha[linha];
    if (pontocoluna == NULL) {
        matriz->coluna[coluna] = novo;
    }
    if (pontolinha == NULL) {
        matriz->linha[linha] = novo;
    } else {
        anterior = NULL;
        while ((pontolinha->coluna < coluna) && (pontolinha != NULL)) {
            anterior = pontolinha;
            pontolinha = pontolinha->direita;
        }
        if (pontolinha != NULL) {
            if (pontolinha->coluna == coluna) {
                printf("Ja existe elemento na coluna");
            } else if (anterior == NULL) {
                novo->direita = matriz->linha[linha];
                matriz->linha[linha] = novo;
            } else {
                novo->direita = pontolinha;
                anterior->direita = novo;
            }
        } else {
            anterior->direita = novo;
        }
    }
}

void imprimirLinha(MatrizEsparsa *matriz, int linha) {
    elemento *aux;
    aux = matriz->linha[linha];
    while (aux != NULL) {
        printf("%d\n", aux->info);
    }
}

int main(void) {
}