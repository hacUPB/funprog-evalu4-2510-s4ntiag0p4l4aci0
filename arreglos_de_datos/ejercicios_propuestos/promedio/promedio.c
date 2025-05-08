#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float calcprom(int arr[], int n) {
    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum / n;
}

int main() {
    srand(time(NULL));

    int n = rand() % 6 + 5;
    int numeros[n];

    for (int i = 0; i < n; i++) {
        numeros[i] = rand() % 35 + 1;
    }

    float prom = calcprom(numeros, n);

    printf("El arreglo tiene: %d\n elementos", n);
    printf("Este es el arreglo: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\nEl promedio es: %.2f\n", prom);

    return 0;
}