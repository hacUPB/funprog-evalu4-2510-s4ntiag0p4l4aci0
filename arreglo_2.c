#include <stdio.h>


int main(){


    int Datos[5] = {0};

    
    for(int i = 0; i <15; i++)
    {

        Datos[0]  ++;

        Datos[1] = Datos[1]+2;

        Datos[2] = Datos[2]+3;
    
        Datos[3] = Datos[3]+4;

        Datos[4] = Datos[4]+5;


        printf("Datos en  iteraci%cn %d = { %d , %d  , %d , %d , %d }\n", 162, i+1, Datos[0], Datos[1], Datos[2], Datos[3], Datos[4] );
 

};
    
for(int j= 0; j < 5; j++)

   { printf("%d - %p\n", Datos[j], &Datos[j]);}


}
