#include <stdio.h>

int main()
{
    int pares[5];
    int n = 0;

    for (int i = 2; i <= 10; i++) {
        if (i % 2 == 0) {
            pares[n] = i;
            n++;
        }
    }

    for (int i = 0; i < 5; i++) {
        printf("%d\n", pares[i]);
    }



    return 0;
}
