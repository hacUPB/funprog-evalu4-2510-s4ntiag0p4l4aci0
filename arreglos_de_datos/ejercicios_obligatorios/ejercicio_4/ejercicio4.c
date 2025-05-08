#include <stdio.h>
int main(){

float array_primeros_5[5];
float array_segundos_5[5];
float array_todos[10];

for(int i = 0; i < 9; i++)


if(i <= 5){

    scanf("%f", &array_primeros_5[i]);

    array_todos[i] = array_primeros_5[i];


    printf("%f\n", array_primeros_5[i]);
}


else
{
    scanf("%f", &array_segundos_5[i]);
    array_todos[i] = array_segundos_5[i];
    printf("%f\n", array_segundos_5[i]);
    
}
printf("%f\n", array_todos[i]);

}