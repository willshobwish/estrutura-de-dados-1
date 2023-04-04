#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    while (1) {
        if (kbhit()) {
            printf("Pressionado: %c\nNumero: %d\n\n", getch(), getch());
        }
    }
}