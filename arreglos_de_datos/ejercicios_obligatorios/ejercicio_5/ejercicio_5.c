#include <stdio.h>

int main() {
    float notas[24];
    float prom, sum = 0;
    int ganan = 0, pierden = 0, mejores = 0;

    printf("Ingrese las notas de los 24 estudiantes:\n");

    for (int i = 0; i < 24; i++) 
    {
        do {
            printf("Nota del estudiante %d: ", i + 1);
            scanf("%f", &notas[i]);

            if (notas[i] < 0 || notas[i] > 5) {
                printf("Error: La nota debe estar entre 0 y 5. Intente nuevamente.\n");
            }
        } while (notas[i] < 0 || notas[i] > 5);
    }

    for (int i = 0; i < 24; i++) {
        sum += notas[i];

        if (notas[i] >= 3) {
            ganan++;
        } else {
            pierden++;
        }

        if (notas[i] >= 4) {
            mejores++;
        }
    }

    prom = sum / 24;

    printf("Promedio general: %.2f\n", prom);
    printf("Estudiantes que ganan (nota sobre 3): %d\n", ganan);
    printf("Estudiantes que pierden (menor a 3): %d\n", pierden);
    printf("Estudiantes con mejor nota (4 o mayor): %d\n", mejores);
    return 0;
}