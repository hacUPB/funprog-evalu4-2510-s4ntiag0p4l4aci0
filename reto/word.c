#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int menu(void);

int main(){

    int x;
    
    x = 0;
    
    
    while(x != 5){
    
        abrir_archivo();
    
    x = menu();

    switch(x){
    
        case 1: cargando();
            printf("Estadísticas");
            estad_txt();
                break;
    
        case 2: cargando();
            printf("Contador de vocales");
            cont_vov();
                break;
                    
        case 3: cargando();
            printf("Buscar y Reemplazar");
            cntrl_f();
                break;
    
        case 4: cargando();
            printf("Guardar cambios en un nuevo archivo");
            nuevo_archivo();
                break;

        case 5: cargando();
            printf("Imprimir");
            imprimir();
                break;
    
        case 6: cargando();
                printf("muchas gracias");
                break;
    
        default: printf("Opción inválida.");
                break;
    
        return 0;
    
    }
    return 0;
    }
}

int menu(void) {
	int opcion;
	printf("Menú: \n \
            \t1. Estadísticas.\n\
            \t2. Contador de Vocales.\n\
            \t3. Buscar y Reemplazar.\n\n\
            \t3. Buscar y Reemplazar.\n\n\
            \t4. Guardar cambios en archivo nuevo.\n\n\
            \t5. Imprimir.\n\n\
            \t6. Salir.\n\n\
    Ingrese el n%cmero de la opci%cn\n", 162, 163, 162);
	scanf("%d", &opcion);
	return opcion;
}

FILE* abrir_archivo(){
    char nombre_archivo[100];
    fgets(nombre_archivo, sizeof(nombre), stdin);

    FILE *archivo;

    *archivo = fopen();

}