#include <stdio.h>

int main()
{
    int y;

    int *x = NULL; 
    
    y = 35;

    x = &y;
    
    printf("Dirección de moemoria de y %p\n", &y);
    printf("Contenido de x %p\n", x);
    printf("Contenido de y %d\n", y);
    (*x )= 699;
    printf("Contenido de y %d\n", (*x));
    (*x) = 100;
    printf("Contenido de y %d\n", (*x));
    y = (*x)*2;
    printf("Contenido de y %d\n", (*x));
    
    return 0;
}
