#include <stdio.h>

int main(void){

int cant_registros;
double peso[3], estatura[3], imc[3];

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


for(int i = 0; i < cant_registros; i++)
{
fscanf(p_datos, "%lf", &peso[i]);
printf("peso  = %lf\n", peso[i]);

fscanf(p_datos, "%lf", &estatura[i]);
printf("estatura  = %lf\n", estatura[i]);
imc[i] = peso[i]/(estatura[i]*estatura[i]);

printf("IMC = %lf\n", imc);

}


fclose(p_datos);




return 0;




}