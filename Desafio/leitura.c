#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 256
#define MAXALOCACAO 10
typedef struct {
    char ID[50];
    char rodata[50];
    char data[50];
    char hora[50];
    char mandante[50];
    char visitante[50];
    char formacao_mandante[50];
    char formacao_visitante[50];
    char tecnico_mandante[50];
    char tecnico_visitante[50];
    char vencedor[50];
    char arena[50];
    char mandante_Placar[50];
    char visitante_Placar[50];
    char mandante_Estado[50];
    char visitante_Estado[50];
} dados;

int main() {
    FILE *arquivobinario = fopen("testestruct.bin", "rb");
    dados b;
    for (int i = 0; i < 10; i++) {
        fseek(arquivobinario, sizeof(dados) * i, SEEK_SET);
        fread(&b, sizeof(dados), 1, arquivobinario);
        printf("\n ID: %s\n rodata: %s\n data: %s\n hora: %s\n mandante: %s\n visitante: %s\n formacao_mandante: %s\n formacao_visitante: %s\n tecnico_mandante: %s\n tecnico_visitante: %s\n vencedor: %s\n arena: %s\n mandante_Placar: %s\n visitante_Placar: %s\n mandante_Estado: %s\n visitante_Estado: %s", b.ID, b.rodata, b.data, b.hora, b.mandante, b.visitante, b.formacao_mandante, b.formacao_visitante, b.tecnico_mandante, b.tecnico_visitante, b.vencedor, b.arena, b.mandante_Placar, b.visitante_Placar, b.mandante_Estado, b.visitante_Estado);
        printf("\n--------------------------------------");
    }

    return 0;
}