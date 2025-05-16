#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // 0. Declaración de variables
    int cant_registros;
    double *peso, *estatura, *imc; // Punteros para memoria dinámica con double
    // 1. Declarar los punteros para los archivos
    FILE *p_datos, *p_datos_organizados;

    // 2. Abrir el archivo de entrada
    p_datos = fopen("datos.txt", "r");
    if (!p_datos)
    {
        perror("No se pudo abrir el archivo de entrada.\n");
        return 1;
    }

    // 3. Abrir el archivo de salida (para guardar los datos organizados)
    p_datos_organizados = fopen("datos_organizados.txt", "w");
    if (!p_datos_organizados)
    {
        perror("No se pudo abrir el archivo de salida.\n");
        fclose(p_datos); // Cerrar archivo de entrada antes de salir
        return 1;
    }

    // 4. Leer la cantidad de registros
    fscanf(p_datos, "%d", &cant_registros);
    printf("Cantidad de registros: %d\n", cant_registros);

    // Reservamos la memoria de forma dinámica
    peso = (double *)malloc(cant_registros * sizeof(double));
    estatura = (double *)malloc(cant_registros * sizeof(double));
    imc = (double *)malloc(cant_registros * sizeof(double));

    // Leer los datos de peso y estatura, calcular el IMC y escribir los resultados
    for (int i = 0; i < cant_registros; i++)
    {
        fscanf(p_datos, "%lf", &peso[i]);  // Usar %lf para leer double
        fscanf(p_datos, "%lf", &estatura[i]);  // Usar %lf para leer double

        // Calcular el IMC
        imc[i] = peso[i] / (estatura[i] * estatura[i]);

        // Escribir los datos organizados en el archivo de salida
        fprintf(p_datos_organizados, "Registro %d: Peso = %lf, Estatura = %lf, IMC = %lf\n", 
                i + 1, peso[i], estatura[i], imc[i]);
    }

    // Liberar la memoria dinámica
    free(peso);
    free(estatura);
    free(imc);

    // Cerrar los archivos
    fclose(p_datos);
    fclose(p_datos_organizados);

    printf("Los datos organizados han sido guardados en 'datos_organizados.txt'.\n");

    return 0;
}