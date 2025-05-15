#include <stdio.h>
#include <stdlib.h>

int main(void){

int cant_resist;
float *resistencias, erres, denominador, resultado;

printf("Ingrese la cantidad de resistencias\n");
scanf("%d", &cant_resist);
resistencias = (float*)calloc(cant_resist, sizeof(float));

for(int i = 0; i < cant_resist; i++){
printf("ingrese la resistencia %d\n", i + 1);
scanf("%f", &resistencias[i]);
}

for(int i = 0; i < cant_resist; i++){

    erres = 1/resistencias[i];

    denominador = denominador + erres;


}


resultado = 1/denominador;

printf("La resistencia del circuito es: %f", resultado);

}