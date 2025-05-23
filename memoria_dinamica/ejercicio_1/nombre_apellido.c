#include <stdio.h>
#include <stdlib.h>
 
int main(void){
    char *puntero;
    int tamano;
    printf("Ingrese la cantidad de letras de sun nombre y apellido:");
    scanf("%d",&tamano);
    printf("\n");
    puntero = (char *) malloc((tamano+2)*sizeof(char));
    fflush(stdin);
    fgets(puntero, tamano+2, stdin);

    printf("Hola %s =)", puntero);
    free(puntero);
}

