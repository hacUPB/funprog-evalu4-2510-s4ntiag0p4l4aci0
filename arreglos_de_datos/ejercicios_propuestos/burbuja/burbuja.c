#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void burbuja(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

int main() {
    srand(time(NULL));

    int n = rand() % 6 + 5; 
    int arr[n];

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 35 + 1; 
    }

    printf("Arreglo original (con %d elementos):\n", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    burbuja(arr, n);

    printf("Arreglo ordenado:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}