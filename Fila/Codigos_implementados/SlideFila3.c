#include <stdio.h>
#include <stdlib.h>

// tipoelem = int
struct noFila {
    int elemento;
    int prioridade;
    struct noFila *prox;
};

// Descritor
typedef struct {
    struct noFila *inicio;
    struct noFila *fim;
} FilaP;

void inicializacao(FilaP *fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
}

short vazia(FilaP *fila) {  // verifica se a fila está vazia
    if (fila->inicio == NULL)
        return 1;
    else
        return 0;
}

// a código da função fila cheia pode ser inserido na função inserir
short cheia(FilaP *fila) {  // a fila estará cheia quando não houver memória para ser alocada
    struct noFila *novoNo;
    novoNo = malloc(sizeof(struct noFila));
    // malloc retorna null quando não houver memória disponível para alocação ou quando ocorrer algum erro durante a alocação - execução do malloc
    if (novoNo == NULL)
        return 1;
    else
        return 0;
}

void inserir(FilaP *fila, int elemento, int prioridade) {  // inserção ordenada
    struct noFila *novoNo, *aux, *anterior;
    novoNo = malloc(sizeof(struct noFila));
    if (novoNo == NULL)
        printf("Fila Cheia!!!");
    else {
        novoNo->prox = NULL;
        novoNo->prioridade = prioridade;
        novoNo->elemento = elemento;
        aux = fila->inicio;
        anterior = NULL;
        while ((aux != NULL) && (aux->prioridade >= prioridade)) {
            anterior = aux;
            aux = aux->prox;
        }
        if (aux != NULL) {
            if (anterior == NULL) {
                novoNo->prox = fila->inicio;
                fila->inicio = novoNo;
            } else {
                novoNo->prox = aux;
                anterior->prox = novoNo;
            }
        } else {
            if (anterior == NULL)  // fila vazia
                fila->inicio = novoNo;
            else  // inserção no final da fila
                fila->fim->prox = novoNo;
            fila->fim = novoNo;
        }
    }
}

void remover(FilaP *fila, int *elemento, int *prioridade) {
    struct noFila *aux;
    if (vazia(fila))
        printf("Fila Vazia - Não há elementos para remover!!!");
    else {
        aux = fila->inicio;
        *elemento = aux->elemento;
        *prioridade = aux->prioridade;
        fila->inicio = fila->inicio->prox;
        free(aux);
    }
}

void selecao(FilaP *fila, int *elemento) {
    if (vazia(fila))
        printf("Fila Vazia - Não há elementos na fila!!!");
    else
        *elemento = fila->inicio->elemento;
}
// Retorna o elemento que está no inicio da fila

int main(void) {
    int elemIni, elemRem, prioRem;
    struct noFila *i = NULL;
    FilaP F1;
    inicializacao(&F1);
    if (vazia(&F1))
        printf("\nFila vazia!");

    // Inserindo valores na fila
    inserir(&F1, 1, 4);
    inserir(&F1, 1, 6);
    inserir(&F1, 2, 3);
    inserir(&F1, 3, 5);
    inserir(&F1, 5, 5);
    printf("\nInseri 5 elementos!");

    // Imprimindo a fila
    printf("\nInicio (valor elem): %d", F1.inicio->elemento);
    printf("\nFim (valor elem): %d\n", F1.fim->elemento);
    for (i = F1.inicio; i != NULL; i = i->prox)
        printf("%d ", i->elemento);

    selecao(&F1, &elemIni);
    printf("\nElemento do inicio: %d", elemIni);

    remover(&F1, &elemRem, &prioRem);
    printf("\nRemovi o elemento: %d com prioridade %d", elemRem, prioRem);
    remover(&F1, &elemRem, &prioRem);
    printf("\nRemovi o elemento: %d com prioridade %d", elemRem, prioRem);

    inserir(&F1, 89, 1);

    // Imprimindo a fila
    printf("\nInicio (valor elem): %d", F1.inicio->elemento);
    printf("\nFim (valor elem): %d\n", F1.fim->elemento);
    for (i = F1.inicio; i != NULL; i = i->prox)
        printf("%d ", i->elemento);

    return (0);
}