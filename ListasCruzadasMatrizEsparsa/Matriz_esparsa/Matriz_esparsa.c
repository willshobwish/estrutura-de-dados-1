#include <stdio.h>
#include <stdlib.h>

#define LINHA 20
#define COLUNA 20

typedef struct no {
    int info, linha, coluna;
    struct no *direita;
    struct no *baixo;

} elemento;

typedef struct {
    elemento *linha[LINHA];
    elemento *coluna[COLUNA];
} MatrizEsparsa;

void inicializarMatriz(MatrizEsparsa *matriz) {
    for (int i = 0; i < LINHA; i++) {
        matriz->linha[i] = NULL;
    }
    for (int i = 0; i < COLUNA; i++) {
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
        matriz->coluna[linha];
    } else {
        anterior = NULL;
        while ((pontocoluna != NULL) && (pontocoluna->linha < linha)) {
            anterior = pontocoluna;
            pontocoluna = pontocoluna->baixo;
        }
        if (pontocoluna != NULL) {
            if (pontocoluna->linha == linha) {
                printf("Ja existe elemento na linha");
            } else if (anterior == NULL) {
                novo->baixo = matriz->coluna[coluna];
                matriz->coluna[coluna] = novo;
            } else {
                novo->baixo = pontocoluna;
                anterior->baixo = novo;
            }
        } else {
            anterior->baixo = novo;
        }
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
                printf("Ja existe um elemento na coluna\n");

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
    printf("Impressao de linha\n");
    while (aux != NULL) {
        printf("%d ", aux->info);
        aux = aux->direita;
    }
}

void imprimirColuna(MatrizEsparsa *matriz, int coluna) {
    elemento *aux;
    aux = matriz->coluna[coluna];
    printf("Impressao da coluna\n");
    while (aux != NULL) {
        printf("%d\n", aux->info);
        aux = aux->baixo;
    }
}

void imprimirLinhaNula(MatrizEsparsa *matriz, int linha) {
    int coluna;
    elemento *aux;
    aux = matriz->linha[linha];
    for (coluna = 0; coluna < COLUNA; coluna++) {
        if ((aux != NULL) && (aux->coluna == coluna)) {
            printf("%d ", aux->info);
            aux = aux->direita;
        } else {
            printf("0 ");
        }
    }
    printf("\n");
}

int main(void) {
    MatrizEsparsa matriz;
    inicializarMatriz(&matriz);

    insercao(&matriz, 0, 0, 10);
    insercao(&matriz, 0, 1, 20);
    // insercao(&matriz,0,2,10);
    // insercao(&matriz,0,3,10);
    imprimirColuna(&matriz, 0);
    imprimirLinha(&matriz, 0);
}