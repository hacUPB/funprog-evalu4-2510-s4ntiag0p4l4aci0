#include <stdio.h>

int main(){


FILE *p_archivo;

p_archivo = fopen("C:\\Users\\B09S113est\\Desktop\\texto_1.txt", "w");

if(p_archivo != NULL){
    printf("¡Enhorabuena! Se creó el archivo");
}

fclose(p_archivo);

}