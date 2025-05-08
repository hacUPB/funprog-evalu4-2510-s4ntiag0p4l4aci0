
#include <stdio.h>
#include <string.h>
#include <ctype.h>


void invertir(const char *derecho, char *reves) {
    int num_caract = strlen(derecho);

    for (int i = 0; i < num_caract; i++) {
        reves[i] = derecho[num_caract - 1 - i];
    }
    reves[num_caract] = '\0';
}

int main() {
    char frase[70];
    char esarf[70];

    printf("Ingresa una frase:\n");
    fgets(frase, sizeof(frase), stdin);

    invertir(frase, esarf);

    printf("Tu frase: %s\n", frase);
    printf("La frase volteada: %s\n", esarf);

    return 0;
}