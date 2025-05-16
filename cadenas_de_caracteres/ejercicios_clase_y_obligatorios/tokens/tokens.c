#include <stdio.h>
#include <string.h>

void tokenizador(char *frase, const char *partidores, char tokens[][100], int *num_tokens) {
    int i = 0;
    int j = 0;
    char *inicio_token = frase;

    while (frase[i] != '\0') {
        int es_partidor = 0;

        for (int k = 0; partidores[k] != '\0'; k++) {
            if (frase[i] == partidores[k]) {
                es_partidor = 1;
                break;
            }
        }

        if (es_partidor) {
            if (i > 0 && inicio_token != &frase[i]) {
                strncpy(tokens[j], inicio_token, i - (inicio_token - frase));
                tokens[j][i - (inicio_token - frase)] = '\0';
                j++;
            }
            inicio_token = &frase[i + 1];
        }
        i++;
    }

    if (inicio_token < &frase[i]) {
        strcpy(tokens[j], inicio_token);
        j++;
    }

    *num_tokens = j;
}

int main() {
    char frase[200];
    const char partidores[] = " ,;";
    char tokens[20][100];
    int num_tokens = 0;

    printf("Ingrese una frase: ");
    fgets(frase, sizeof(frase), stdin);

    frase[strcspn(frase, "\n")] = '\0';

    tokenizador(frase, partidores, tokens, &num_tokens);

    printf("Tokens:\n");
    for (int i = 0; i < num_tokens; i++) {
        printf("Token %d: '%s'\n", i + 1, tokens[i]);
    }

    return 0;
}