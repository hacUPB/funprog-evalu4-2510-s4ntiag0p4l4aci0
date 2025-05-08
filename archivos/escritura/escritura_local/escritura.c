#include <stdio.h>
#include <string.h>


int main(){
int edad; 
char Nombre[30];
FILE *p_archivo;

p_archivo = fopen("texto_1.txt", "w");

fprintf(stdout, "Ingrese el nombre");
fgets(Nombre, sizeof(Nombre), stdin);
Nombre[strlen(Nombre) - 1] = '\0';


fprintf(stdout, "Ingrese la edad");
scanf("%d", &edad);

if(p_archivo != NULL){
    printf("¡Enhorabuena! Se creó el archivo");


fprintf(p_archivo, "parangaricutirimicuaro quiere desparangaricutirimicuarse");

fprintf(p_archivo, "Hola %s bienvenido al curso", Nombre);
fprintf(p_archivo, "Edad: %d", edad);
}
fclose(p_archivo);
return 0;

}