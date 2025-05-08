#include <stdio.h>

int main()
{
    int num[10];
    int sum = 0;
    int rest = 0;
    int mult = 1;

    printf("Ingrese 10 numeros:\n");

    for (int i = 0; i < 10; i++) 
    {
        scanf("%d", &num[i]);

        sum = sum + num[i];
        if (i == 0)
         {
            rest = num[i];
        } 
        else {
            rest = rest - num[i];
        }
        mult = mult * num[i];
    }

    printf("Total: %d\n", sum);
    printf("Diferencia: %d\n", rest);
    printf("Producto: %d\n", mult);

    return 0;
}
