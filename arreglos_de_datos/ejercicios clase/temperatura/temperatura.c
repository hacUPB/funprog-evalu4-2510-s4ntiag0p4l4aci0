#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
int main(){

srand(time(NULL)); // generamo0s una semilla 

     int temp[24]; /* Con esto ya tenemos declaradas las 24 variables */
     float media = 0;
     int hora;
     /* Ahora tenemos que dar el valor de cada una */
     for( hora=0; hora<24; hora++ )
          {
          temp[hora] = (rand() % ((35-14)+1))+14;
          media += temp[hora];
          printf("%d\n", temp[hora]);
          }
     media = media / 24;
     printf("\nLa temperatura media es %f \n", media );

     float mayor = temp[0];
     float menor = temp[0];
          for(int i =0; i<24; i++)
         {

          if(temp[i] > mayor)
          {mayor = temp[i];}

          else
          {menor = temp[i];}



          

          }

          printf("El mayor es %f y el menor es %f\n", mayor, menor);

          float promedio_limites = (mayor + menor)/2;
          printf("el promedi por limites es %f\n", promedio_limites);

          float dif_promedios = media - promedio_limites;

          printf("la diferencia de promedios es %f\n", abs(dif_promedios));


     

     return 0;}

     // {}