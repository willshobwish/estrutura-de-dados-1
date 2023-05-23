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
        matriz->coluna[linha] = novo;
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
        matriz->linha[coluna] = novo;
    } else {
        anterior = NULL;
        while ((pontolinha != NULL) && (pontolinha->coluna < coluna)) {
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

// int remocao(MatrizEsparsa *matriz, int linha, int coluna) {
//     elemento *auxiliar, *pontolinha, *pontocoluna, *anterior;

//     pontocoluna = matriz->coluna[coluna];
//     pontolinha = matriz->linha[linha];
//     // Caso não tenha nenhum elemento, não tem como remover nada
//     if (pontocoluna == NULL) {
//         printf("Nao ha elemento para ser removido\n");
//     } else {
//         anterior = NULL;
//         // Enquanto ponto coluna não for nulo e for menor que a linha
//         while ((pontocoluna != NULL) && (pontocoluna->linha < linha)) {
//             // Aponta para o anterior
//             anterior = pontocoluna;
//             // Aponta para o próximo
//             pontocoluna = pontocoluna->baixo;
//         }
//         // Caso não seja nulo, isso significa que existe um elemento
//         if (pontocoluna != NULL) {
//             // Condição de encontrar o elemento
//             if (pontocoluna->linha == linha) {
//                 // printf("Ja existe elemento na linha");
//                 auxiliar = pontocoluna->info;
//                 anterior->baixo = pontocoluna->baixo;
//                 free(pontocoluna);
//             }
//         }
//     }
//     if (pontolinha == NULL) {
//         // matriz->linha[coluna] = novo;
//         printf("Nao ha elemento para ser removido\n");
//     } else {
//         anterior = NULL;
//         while ((pontolinha != NULL) && (pontolinha->coluna < coluna)) {
//             anterior = pontolinha;
//             pontolinha = pontolinha->direita;
//         }
//         if (pontolinha != NULL) {
//             if (pontolinha->coluna == coluna) {
//                 //
//                 anterior->direita = pontolinha->direita;
//                 free(pontolinha);
//             }
//         }
//     }
// }

void imprimirLinha(MatrizEsparsa *matriz, int linha) {
    elemento *aux;
    aux = matriz->linha[linha];
    printf("Impressao de linha\n");
    while (aux != NULL) {
        printf("%d ", aux->info);
        aux = aux->direita;
    }
    printf("\n");
}

void imprimirColuna(MatrizEsparsa *matriz, int coluna) {
    elemento *aux;
    aux = matriz->coluna[coluna];
    printf("Impressao da coluna\n");
    while (aux != NULL) {
        printf("%d\n", aux->info);
        aux = aux->baixo;
    }
    printf("\n");
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

void somark(MatrizEsparsa *matriz, int linha, int valor) {
    int coluna;
    elemento *aux;
    aux = matriz->linha[linha];
    for (coluna = 0; coluna < COLUNA; coluna++) {
        if ((aux != NULL) && (aux->coluna == coluna)) {
            aux->info = aux->info + valor;
            aux = aux->direita;
        } else {
            insercao(matriz, linha, coluna, valor);
        }
    }
}

int main(void) {
    MatrizEsparsa matriz;
    inicializarMatriz(&matriz);
    insercao(&matriz, 0, 0, 10);
    insercao(&matriz, 0, 1, 20);
    insercao(&matriz, 0, 2, 30);
    insercao(&matriz, 0, 4, 40);
    imprimirLinha(&matriz, 0);
    somark(&matriz, 0, 2);
    imprimirLinha(&matriz, 0);
    somark(&matriz, 0, -2);
    imprimirLinha(&matriz, 0);
}