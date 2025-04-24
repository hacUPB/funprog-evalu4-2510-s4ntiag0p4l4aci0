#include <stdio.h>
int suma(int *, int *); // se da el prototipo de la función para punteros enteros
int main()
{
    int resultado, a,b;
    a = 100;
    b = 400;
    resultado = suma(&a,&b); // se ejecuta la función con los valores guardados en las posiciones de memoria para a y b.
    printf("%d\n", resultado);
    printf("Los valores nuevos son %d y %d", a, b);

    
    return 0;
}

int suma(int *pnt_a, int *pnt_b) //se utilizan los punteros para trabajar con valores a partir de las posiciones de memoria
{

    int resul_suma;
    resul_suma = (*pnt_a) +(*pnt_b) ; // se utiliza la desreferenciación para operar los valores guardados en las posiciones de memoria.

    (*pnt_a) = 999; // se actualiza el valor guardado en la posición de memoria de a
    (*pnt_b) = 777; // se actualiza el valor guardado en la posición de memoria de b
    
    return resul_suma;


}