#include <stdio.h>

int main(void){

    int cant_registros;
    double peso, estatura, imc;

//1. Declarar punteros
FILE *p_datos, *p_imc;

//2. Abrir el archivo

p_datos = fopen("datos.txt", "r");

//3. Verificar si sepudo abrir el archivo

if(!p_datos)
{
perror("No se pudo abrir el archivo\n");
return 1;
}

fscanf(p_datos, "%d", &cant_registros);
printf("cantidad de registros  = %d\n", cant_registros);

fscanf(p_datos, "%lf", &peso);
printf("peso  = %lf\n", peso);

fscanf(p_datos, "%lf", &estatura);
printf("estatura  = %lf\n", estatura);


imc = peso/(estatura*estatura);

printf("IMC = %lf", imc);

fclose(p_datos);


return 0;




}