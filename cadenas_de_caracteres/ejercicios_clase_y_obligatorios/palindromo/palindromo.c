#include <stdio.h>
#include <string.h>
#include <ctype.h>

void volteador(const char *derecho, char *reves) {
    int num_caract = strlen(derecho);
    for (int i = 0; i < num_caract; i++) {
        reves[i] = derecho[num_caract - 1 - i];
    }
    reves[num_caract] = '\0';
}

void minusculizador(const char *con_mayus_y_num, char *en_minus) {
    int j = 0;
    for (int i = 0; con_mayus_y_num[i] != '\0'; i++) {
        if (isalnum(con_mayus_y_num[i])) { // también funciona para números
            en_minus[j++] = tolower(con_mayus_y_num[i]);
        }
    }
    en_minus[j] = '\0'; 
}

int main() {
    char frase[100];
    char solo_minus[100];
    char esarf[100];

    printf("Ingrese una frase:\n");
    fgets(frase, sizeof(frase), stdin);


    minusculizador(frase, solo_minus);


    volteador(solo_minus, esarf);


    if (strcmp(solo_minus, esarf) == 0) {
        printf("Si es pal%cndromo =)\n",161);
    } else {
        printf("NO es pal%cndromo.\n",161);
    }

    return 0;
}