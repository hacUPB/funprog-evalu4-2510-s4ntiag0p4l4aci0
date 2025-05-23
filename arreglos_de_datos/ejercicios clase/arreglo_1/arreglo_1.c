#include <stdio.h>


int main(){


    int Datos[5] = {45, 32 , 89, 11, 9};

    printf("%d\n\n", Datos[2]); // corresponde al 89

    for(int i = 0; i <5; i++)
    {
    printf("%d\n - %p\n", Datos[i], &Datos[i]);};
    


    printf(" _______________________________________________________\n");
    printf("|                                                      |\n");
    printf("|    %d    |    %d    |    %d    |    %d    |    0%d    |\n", Datos[0], Datos[1], Datos[2], Datos[3], Datos[4]);
    printf("| %p | %p | %p | %p | %p |\n", &Datos[0], &Datos[1], &Datos[2], &Datos[3], &Datos[4]);
    printf("|______________________________________________________|\n");
    return 0;
}