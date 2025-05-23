#include <stdio.h>
#include <string.h>

int main() {
    char nombre[20];

    printf("Ingresa tu nombre:\n");
    fgets(nombre, sizeof(nombre), stdin);

    nombre[strlen(nombre)-1] = '\0';

    char mensaje[30] = "Hola, ";
    strncat(mensaje, nombre, sizeof(mensaje) - strlen(mensaje) - 1);

    printf("%s\n", mensaje);
    printf("Tu nombre tiene %d letras.\n", strlen(nombre));

    return 0;
}