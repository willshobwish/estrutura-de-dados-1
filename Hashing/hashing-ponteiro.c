#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 15

struct aluno {
    int matricula;
    char nome[80];
    char email[80];
};

typedef struct aluno aluno;

int hash(int matricula) {
    return (matricula % 101) % MAX;
}

void inicializar(aluno *tabela[]) {
    for (int i = 0; i < MAX; i++) {
        tabela[i] = NULL;
    }
}

void inserir(aluno *tabela[], int matricula, char email[], char nome[]) {
    int chave = hash(matricula);
    aluno *auxiliar;
    auxiliar = malloc(sizeof(aluno));
    auxiliar->matricula = matricula;
    strcpy(auxiliar->email, email);
    strcpy(auxiliar->nome, nome);
    tabela[chave] = auxiliar;
}
void remocao(aluno *tabela[], int matricula) {
    int chave = hash(matricula);
    aluno *auxiliar = tabela[chave];
    if (auxiliar->matricula == matricula) {
        free(auxiliar);
        tabela[chave] = NULL;
    } else {
        printf("Matricula nao existente\n");
    }
}

void busca(aluno *aluno[], int matricula) {
    int chave = hash(matricula);
    if (aluno[chave]->matricula == matricula) {
        printf("%d %s %s\n", aluno[chave]->matricula, aluno[chave]->email, aluno[chave]->nome);
    }
}

void imprimir(aluno *tabela[]) {
    for (int i = 0; i < MAX; i++) {
        if (tabela[i] != NULL) {
            printf("%d %d %s %s\n", i, tabela[i]->matricula, tabela[i]->email, tabela[i]->nome);
        } else {
            printf("%d --- Vazio\n", i);
        }
    }
    printf("\n");
}
int main(void) {
    aluno tabela[MAX];
    inicializar(&tabela);
    inserir(&tabela, 10, "teste@", "teste");
    imprimir(&tabela);
    remocao(&tabela, 10);
    imprimir(&tabela);
    return 0;
}