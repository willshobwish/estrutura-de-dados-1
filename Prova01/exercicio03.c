#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TEMPO_CHEGADA 5
#define TEMPO_SIMULACAO 200
#define TAMANHO_PERMITIDO 500
#define PESO_PERMITIDO 80
#define TAMANHO_PILHA_ESTATICA 20

typedef struct {
    float largura;
    float altura;
    float profundidade;
} dimensao;

struct encomenda {
    char remetente[100];
    char destinatario[100];
    int cliente;
    float peso;
    dimensao dimensao;
};

typedef struct encomenda encomenda;

// pilha estatica
struct pilha_estatica {
    int elemento_pilha[TAMANHO_PILHA_ESTATICA];
    int topo_pilha;
};

// fila_encadeada dinamicamente encadeada
struct no_fila_encadeada {
    encomenda elemento;
    struct no_fila_encadeada *proximo;
};

struct fila_encadeada {
    struct no_fila_encadeada *inicio;
    struct no_fila_encadeada *fim;
};

// Deque
struct no_deque {
    encomenda elemento;
    struct no_deque *proximo;
};

struct fila_deque {
    struct no_deque *inicio;
    struct no_deque *fim;
};

typedef struct fila_deque fila_deque;
typedef struct pilha_estatica pilha_estatica;
typedef struct no_fila_encadeada no_fila_encadeada;
typedef struct fila_encadeada fila_encadeada;

void inicializacao_pilha_estatica(pilha_estatica *pilha_estatica) {
    pilha_estatica->topo_pilha = 0;
}

bool pilha_vazia(pilha_estatica *pilha_estatica) {
    if (pilha_estatica->topo_pilha == 0) {
        return true;
    } else {
        return false;
    }
}

bool pilha_cheia(pilha_estatica *pilha_estatica) {
    if (pilha_estatica->topo_pilha == TAMANHO_PILHA_ESTATICA) {
        return true;
    } else {
        return false;
    }
}

void push(pilha_estatica *pilha_estatica, int elemento) {
    if (pilha_cheia(pilha_estatica)) {
        printf("Nao ha espaco na pilha estatica");
    } else {
        pilha_estatica->elemento_pilha[pilha_estatica->topo_pilha] = elemento;
        pilha_estatica->topo_pilha++;
    }
}
int pop(pilha_estatica *pilha_estatica) {
    int elemento = 0;
    if (pilha_vazia(pilha_estatica)) {
        printf("Pilha estatica vazia_fila_encadeada\n");
    } else {
        pilha_estatica->topo_pilha--;
        elemento = pilha_estatica->elemento_pilha[pilha_estatica->topo_pilha];
    }
    return elemento;
}

void inicializacao_fila_encadeada(fila_encadeada *fila_encadeada) {
    fila_encadeada->inicio = NULL;
    fila_encadeada->fim = NULL;
}

bool vazia_fila_encadeada(fila_encadeada *fila_encadeada) {
    if (fila_encadeada->inicio == NULL)
        return true;
    else
        return false;
}

void inserir_fila_encadeada(fila_encadeada *fila_encadeada, encomenda elemento) {
    struct no_fila_encadeada *novo_no_encadeado;
    novo_no_encadeado = malloc(sizeof(struct no_fila_encadeada));
    if (novo_no_encadeado == NULL)
        printf("Fila encadeada cheia\n");
    else {
        novo_no_encadeado->elemento = elemento;
        novo_no_encadeado->proximo = NULL;
        if (vazia_fila_encadeada(fila_encadeada))
            fila_encadeada->inicio = novo_no_encadeado;
        else
            fila_encadeada->fim->proximo = novo_no_encadeado;
        fila_encadeada->fim = novo_no_encadeado;
    }
}

encomenda remover_fila_encadeada(fila_encadeada *fila_encadeada) {
    struct no_fila_encadeada *aux;
    encomenda elemento;
    if (vazia_fila_encadeada(fila_encadeada))
        printf("Fila encadeada vazia_fila_encadeada\n");
    else {
        aux = fila_encadeada->inicio;
        elemento = aux->elemento;
        fila_encadeada->inicio = fila_encadeada->inicio->proximo;
        free(aux);
    }
    return elemento;
}

// Funções deque
void inicializacao_deque(fila_deque *fila_deque) {
    fila_deque->inicio = NULL;
    fila_deque->fim = NULL;
}

bool vazia_deque(fila_deque *fila_deque) {
    if (fila_deque->inicio == NULL) {
        return true;
    } else {
        return false;
    }
}

bool cheio_deque(fila_deque *fila_deque) {
    struct no_deque *novo_no_deque;
    novo_no_deque = malloc(sizeof(struct no_deque));
    if (novo_no_deque == NULL)
        return true;
    else
        return false;
}

void inserir_final(fila_deque *fila_deque, encomenda elemento) {
    struct no_deque *novo_no_deque;
    novo_no_deque = malloc(sizeof(struct no_deque));
    
    if (novo_no_deque == NULL)
        printf("Deque cheio\n");
    else {
        novo_no_deque->elemento = elemento;
        novo_no_deque->proximo = NULL;
        if (vazia_deque(fila_deque)) {
            fila_deque->inicio = novo_no_deque;
        } else {
            fila_deque->fim->proximo = novo_no_deque;
        }
        fila_deque->fim = novo_no_deque;
    }
}

void inserir_comeco(fila_deque *fila_deque, encomenda elemento) {
    struct no_deque *novo_no_deque, *auxiliar;
    novo_no_deque = malloc(sizeof(struct no_deque));
    if (novo_no_deque == NULL)
        printf("Deque cheio\n");
    else {
        novo_no_deque->elemento = elemento;
        if (vazia_deque(fila_deque)) {
            fila_deque->inicio = novo_no_deque;
        } else {
            fila_deque->fim->proximo = novo_no_deque;
        }
        fila_deque->fim = novo_no_deque;
        
    }
}

void remover_comeco(fila_deque *fila_deque, encomenda *elemento) {
    struct no_deque *auxiliar;
    if (vazia_deque(fila_deque))
        printf("Deque vazio\n");
    else {
        auxiliar = fila_deque->inicio;
        *elemento = auxiliar->elemento;
        fila_deque->inicio = fila_deque->inicio->proximo;
        free(auxiliar);
    }
}

void remover_final(fila_deque *fila_deque, encomenda *elemento) {
    struct no_deque *auxiliar, *anterior;
    if (vazia_deque(fila_deque))
        printf("Deque vazio\n");
    else {
        auxiliar = fila_deque->inicio;
        while (auxiliar->proximo != NULL) {
            anterior = auxiliar;
            auxiliar = auxiliar->proximo;
        }
        *elemento = auxiliar->elemento;
        fila_deque->fim = anterior;
        free(auxiliar);
    }
}

// Funções do exercicio
bool tamanho_permitido(encomenda encomenda) {
    float tamanho_metro_cubico = encomenda.dimensao.altura * encomenda.dimensao.largura * encomenda.dimensao.profundidade;
    if (tamanho_metro_cubico > TAMANHO_PERMITIDO) {
        printf("Tamanho nao permitido\n");
        return false;
    } else {
        printf("Tamanho permitido\n");
        return true;
    }
}

bool peso_permitido(encomenda encomenda) {
    if (encomenda.peso > PESO_PERMITIDO) {
        printf("Peso nao permitido\n");
        return false;
    } else {
        printf("Peso permitido\n");
        return true;
    }
}

bool cliente_prioritario(encomenda encomenda) {
    if (encomenda.cliente == 0) {
        printf("Cliente prioritario\n");
        return false;
    }
    if (encomenda.cliente == 1) {
        printf("Cliente normal\n");
        return true;
    }
}
int random_number(int intervalo) {
    int numero = rand() % intervalo;
    // printf("Numero aleatorio: %d\n",numero);s
    return numero;
}

encomenda gerar_encomenda() {
    encomenda encomenda;
    strcpy(encomenda.remetente, "remetente teste");
    strcpy(encomenda.destinatario, "destinatario teste");
    encomenda.cliente = random_number(2);
    encomenda.peso = random_number(100);
    encomenda.dimensao.altura = random_number(10);
    encomenda.dimensao.largura = random_number(10);
    encomenda.dimensao.profundidade = random_number(10);
    return encomenda;
}

int main(void) {
    fila_encadeada filaEncadeada;
    inicializacao_fila_encadeada(&filaEncadeada);
    pilha_estatica pilhaEstatica;
    inicializacao_pilha_estatica(&pilhaEstatica);
    fila_deque filaDeque;
    inicializacao_deque(&filaDeque);
    int tempo_execucao = 0, permanencia_fila = 0;
    while (tempo_execucao < TEMPO_SIMULACAO) {
        printf("Tempo de execucao: %d\n", tempo_execucao);
        if (tempo_execucao % 5 == 0) {
            printf("Chegada de encomenda\n");
            encomenda encomenda = gerar_encomenda();
            inserir_fila_encadeada(&filaEncadeada, encomenda);
        }
        if (permanencia_fila <= 0) {
            printf("Encomenda em analise\n");
            encomenda encomenda = remover_fila_encadeada(&filaEncadeada);
            if (tamanho_permitido(encomenda)) {
                if (peso_permitido(encomenda)) {
                    if (cliente_prioritario(encomenda)) {
                        inserir_comeco(&filaDeque, encomenda);
                    } else {
                        inserir_final(&filaDeque, encomenda);
                    }
                }
            }
            permanencia_fila = random_number(10);
        } else {
            permanencia_fila--;
        }
        tempo_execucao++;
        printf("\n");
    }
    return 0;
}