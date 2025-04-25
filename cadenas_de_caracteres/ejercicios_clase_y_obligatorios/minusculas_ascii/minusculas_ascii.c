#include <stdio.h>
#include <string.h>

/*En el código ascii, 
las letras mayúsculas están codificadas en orden desde 65 y 90. 
Las minúsculas empiezan desde 95 hasta 122.
Si hacemos la resta, sabemos que cada minuscula está 32 posiciones más adelante 
en la codificación, por esto sumamos 32*/

void minusculizador_ascii_32(char *cadena) {
    for (int i = 0; cadena[i] != '\0'; i++) {
       
        if (cadena[i] >= 'A' && cadena[i] <= 'Z') {
          
            cadena[i] = cadena[i] + 32;
        }
    }
}

int main() {
    char frase[100];

    printf("Ingresa una frase:\n");
    fgets(frase, sizeof(frase), stdin);


    frase[strcspn(frase, "\n")] = '\0';

 
    minusculizador_ascii_32(frase);

  
    printf("Frase minusculizada: %s\n", frase);

    return 0;
}