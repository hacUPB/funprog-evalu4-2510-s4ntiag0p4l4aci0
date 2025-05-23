
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){

char frase[100];

int contador_vocales = 0;
char letra;


printf("Ingrese una frase:");

fgets(frase, sizeof(frase), stdin);

printf("%s\n", frase);

for(int i = 0; i < strlen(frase); i++){

    letra = tolower(frase[i]);

    if(letra == 'a' || letra == 'e' ||letra == 'i' ||letra == 'o' || letra == 'u'){
        contador_vocales++;
    }
}

printf("Hay %d vocales en la frase", contador_vocales);

}