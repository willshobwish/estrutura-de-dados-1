#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

struct aluno {
    int matricula;
    char nome[80];
    char email[40];
};
typedef struct aluno aluno;

void inicializa_tabela_hash(aluno *tabela) {
    for (int i = 0; i < MAX; i++) {
        tabela[i].matricula = -1;
    }
}
int hash(aluno elemento) {
    return (elemento.matricula % 101) % MAX;
}

void inserir(aluno *tabela, aluno elemento) {
    int chave = hash(elemento);
    tabela[chave] = elemento;
};

void imprimir(aluno *tabela) {
    for (int i = 0; i < MAX; i++) {
        if (tabela[i].matricula != -1) {
            printf("%d %d %s %s\n", i, tabela[i].matricula, tabela[i].email, tabela[i].nome);
        } else {
            printf("%d -- Vazio\n", i);
        }
    }
}

aluno insere_informacoes(int matricula,char email[],char nome[]){
    aluno novo;
    novo.matricula = matricula;
    strcpy(novo.email,email);
    strcpy(novo.nome,nome);
    return novo;
}
int main(void) {
    aluno tabHash[MAX], a;
    inicializa_tabela_hash(&tabHash);
    // a.matricula = 230;
    // strcpy(a.email, "teste@teste");
    // strcpy(a.nome, "teste");
    
    inserir(&tabHash, insere_informacoes(230,"email@teste.com","nome teste"));
    imprimir(&tabHash);
}