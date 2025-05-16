#include <stdio.h>

int main() {
    int estudiantes, actividades;

    printf("Ingrese la cantidad de estudiantes: ");
    scanf("%d", &estudiantes);

    printf("Ingrese la cantidad de actividades: ");
    scanf("%d", &actividades);

    float notas[estudiantes][actividades + 1];
    float porcentajes[actividades];

    int sum_porc;
    do {
        sum_porc = 0;
        for (int j = 0; j < actividades; j++) {
            printf("Porcentaje de la actividad %d: ", j + 1);
            scanf("%f", &porcentajes[j]);
            sum_porc += porcentajes[j];
        }
        if (sum_porc != 100) {
            printf("\nError: La suma de los porcentajes debe ser 100, por favor intente de nuevo\n\n");
        }
    } while (sum_porc != 100);

    for (int i = 0; i < estudiantes; i++) {
        printf("\nNotas del estudiante %d:\n", i + 1);
        for (int j = 0; j < actividades; j++) {
            float nota;
            do {
                printf("Actividad %d: ", j + 1);
                scanf("%f", &nota);
                if (nota < 0 || nota > 5) {
                    printf("Error, por favor ingrese un valor entre 0 y 5.\n");
                }
            } while (nota < 0 || nota > 5);
            notas[i][j] = nota;
        }
    }

    // Calcular definitivas
    for (int i = 0; i < estudiantes; i++) {
        float definitiva = 0;
        for (int j = 0; j < actividades; j++) {
            definitiva += notas[i][j] * (porcentajes[j] / 100);
        }
        notas[i][actividades] = definitiva;
    }

    // titulos
    printf("               ");
    for (int j = 0; j < actividades; j++) {
        printf("Actividad %-3d ", j + 1);
    }
    printf("Definitiva\n");

    // valores porcentuales
    printf("Porcentajes     ");
    for (int j = 0; j < actividades; j++) {
        printf("%10.0f ", porcentajes[j]);
    }
    printf("\n");

    // notas
    for (int i = 0; i < estudiantes; i++) {
        printf("Estudiante %d: ", i + 1);
        for (int j = 0; j <= actividades; j++) {
            if (j == actividades) {
                printf("%10.2f\n", notas[i][j]);
            } else {
                printf("%10.2f ", notas[i][j]);
            }
        }
    }

    return 0;
}
