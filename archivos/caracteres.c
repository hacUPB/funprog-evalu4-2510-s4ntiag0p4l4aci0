#include <stdio.h>

int main(){

    int letra = '1';

    char caracter;



FILE *pfile;

pfile = fopen("texto2.txt", "a");

if(pfile)
{
while(letra!='?'){

caracter = fgetsc(stdin);

letra = fputc(caracter, pfile);

}

}

fclose(pfile);
return 0;

}