#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char* curso;
    char nombre_curso[100];

    printf("Ingrese el nombre del curso: ");
    if (fgets(nombre_curso, sizeof(nombre_curso), stdin) == NULL) {
        return 1;
    }

    size_t len = strcspn(nombre_curso, "\n");
    nombre_curso[len] = '\0';

    curso = (char*)malloc(len + 1);
    if (curso == NULL) {
        return 1;
    }
    strcpy(curso, nombre_curso);

    printf("Ingrese el código NRC del curso: ");
    if (fgets(nombre_curso, sizeof(nombre_curso), stdin) == NULL) {
        free(curso);
        return 1;
    }

    size_t len_nrc = strcspn(nombre_curso, "\n");
    nombre_curso[len_nrc] = '\0';

    char* auxiliar = (char*)malloc(len + 1 + len_nrc + 1);
    if (auxiliar == NULL) {
        free(curso);
        return 1;
    }

    strcpy(auxiliar, curso);
    auxiliar[len] = '-';
    strcpy(auxiliar + len + 1, nombre_curso);

    free(curso);
    curso = auxiliar;

    printf("Curso completo: %s\n", curso);

    free(curso);
    return 0;
}