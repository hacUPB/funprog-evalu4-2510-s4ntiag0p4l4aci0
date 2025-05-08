#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int mayor(int arr[], int n) {
    int mayor = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > mayor) {
            mayor = arr[i];
        }
    }
    return mayor;
}

int main() {
    srand(time(NULL));

    int n = rand() % 6 + 5;
    int arr[n];

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 35 + 1;
    }

    printf("Arreglo:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int maximo = mayor(arr, n);
    printf("El mayor valor es: %d\n", maximo);

    return 0;
}