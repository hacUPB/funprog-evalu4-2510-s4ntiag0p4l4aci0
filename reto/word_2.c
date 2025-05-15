#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Prototipos
void cargando(void);
char* abrir_archivo(void);
void estad_txt(char* texto);
void cont_voc(char* texto);
void reemplazar(char** texto);
void guardar_archivo(char* texto);
void imprimir(char* texto);
int menu(void);
void limpiar_mem_temporal(char* mem_temporal, size_t tamaño);

int main()
{
    char* texto = abrir_archivo();
    if (!texto) return 1;
    
    int opcion;

    opcion = 0; 

    while (opcion != 6){

        opcion = menu();
        switch (opcion) {
            case 1:
                cargando();
                printf("Estadísticas:\n");
                estad_txt(texto);
                break;

            case 2:
                cargando();
                printf("Contador de vocales:\n");
                cont_voc(texto);
                break;

            case 3:
                cargando();
                printf("Buscar y reemplazar:\n");
                reemplazar(&texto);
                break;

            case 4:
                cargando();
                printf("Guardar cambios en un nuevo archivo:\n");
                guardar_archivo(texto);
                break;

            case 5:
                cargando();
                printf("Imprimir texto:\n");
                imprimir(texto);
                break;

            case 6:
                cargando();
                printf("Muchas gracias.\n");
                break;

            default:
                printf("Opción inválida.\n");
                break;
        }
    } 

    free(texto);
    return 0;
}

void cargando(void){
    int i = 0;
    for (i = 0; i <= 100000; i++){
        printf("\rcargando %d %c", i/1000, 37);
        fflush(stdout); //reseta la linea para que imprima en tiempo real
    }
    printf("\n");
}

void limpiar_mem_temporal(char* mem_temporal, size_t tamaño) {
    size_t len = strlen(mem_temporal);
    if (len > 0 && mem_temporal[len - 1] == '\n') {
        mem_temporal[len - 1] = '\0';
    }
}

char* abrir_archivo()
{
    char nombre[100];
    FILE* archivo;
    int tamaño = 0;
    char* mem_temporal = NULL;

    printf("Ingrese el nombre del archivo a abrir: ");
    if (!fgets(nombre, sizeof(nombre), stdin)) return NULL;
    limpiar_mem_temporal(nombre, sizeof(nombre));

    archivo = fopen(nombre, "r");
    if (!archivo) {
        printf("No se pudo abrir el archivo.\n");
        return NULL;
    }

    int c;
    while ((c = fgetc(archivo)) != EOF) {
        char* temp = realloc(mem_temporal, tamaño + 2);
        if (!temp) {
            free(mem_temporal);
            fclose(archivo);
            printf("Error de memoria.\n");
            return NULL;
        }
        mem_temporal = temp;
        mem_temporal[tamaño++] = (char)c;
    }

    if (mem_temporal) {
        mem_temporal[tamaño] = '\0';
    } else {
        mem_temporal = malloc(1);
        if (mem_temporal) mem_temporal[0] = '\0';
    }

    fclose(archivo);
    return mem_temporal;
}

void estad_txt(char* texto)
{
    int caracteres = 0, palabras = 0, espacios = 0, lineas = 0;
    int en_palabra = 0;
    int i = 0;

    while (texto[i] != '\0') {
        if (texto[i] != '\n') caracteres++;
        if (texto[i] == ' ') espacios++;
        if (texto[i] == '\n') lineas++;
        if (!isspace(texto[i]) && !en_palabra) {
            palabras++;
            en_palabra = 1;
        } else if (isspace(texto[i])) {
            en_palabra = 0;
        }
        i++;
    }

    printf("Caracteres (sin saltos de línea): %d\n", caracteres);
    printf("Palabras: %d\n", palabras);
    printf("Espacios: %d\n", espacios);
    printf("Líneas: %d\n", lineas + 1);
}

void cont_voc(char* texto)
{
    int a=0,e=0,i=0,o=0,u=0;
    int j = 0;
    while (texto[j] != '\0') {
        char c = tolower(texto[j]);
        if (c == 'a') a++;
        else if (c == 'e') e++;
        else if (c == 'i') i++;
        else if (c == 'o') o++;
        else if (c == 'u') u++;
        j++;
    }

    printf("a: %d\ne: %d\ni: %d\no: %d\nu: %d\n", a, e, i, o, u);
}

void reemplazar(char** texto)
{
    char buscar[50], reemplazo[50];
    printf("Palabra a buscar: ");
    if (!fgets(buscar, sizeof(buscar), stdin)) return;
    limpiar_mem_temporal(buscar, sizeof(buscar));
    printf("Reemplazar por: ");
    if (!fgets(reemplazo, sizeof(reemplazo), stdin)) return;
    limpiar_mem_temporal(reemplazo, sizeof(reemplazo));

    size_t len_buscar = strlen(buscar);
    size_t len_reemplazo = strlen(reemplazo);
    size_t len_texto = strlen(*texto);

    int count = 0;
    for (size_t i = 0; i < len_texto;) {
        if (strncmp(&(*texto)[i], buscar, len_buscar) == 0) {
            count++;
            i += len_buscar;
        } else {
            i++;
        }
    }

    size_t nuevo_len = len_texto + count * (len_reemplazo - len_buscar);
    char* nuevo = (char*) malloc(nuevo_len + 1);
    if (!nuevo) {
        printf("Error al asignar memoria para reemplazo.\n");
        return;
    }

    size_t i = 0, j = 0;
    while (i < len_texto) {
        if (strncmp(&(*texto)[i], buscar, len_buscar) == 0) {
            strcpy(&nuevo[j], reemplazo);
            j += len_reemplazo;
            i += len_buscar;
        } else {
            nuevo[j++] = (*texto)[i++];
        }
    }
    nuevo[j] = '\0';

    free(*texto);
    *texto = nuevo;
}

void guardar_archivo(char* texto)
{
    char nombre[100];
    FILE* archivo;

    printf("Nombre del archivo de salida: ");
    if (!fgets(nombre, sizeof(nombre), stdin)) return;
    limpiar_mem_temporal(nombre, sizeof(nombre));

    archivo = fopen(nombre, "w");
    if (!archivo) {
        printf("No se pudo crear el archivo.\n");
        return;
    }

    fprintf(archivo, "%s", texto);
    fclose(archivo);
}

void imprimir(char* texto)
{
    printf("\n%s\n", texto);  
}

int menu()
{
    int opcion;
    printf("\nMenú:\n");
    printf("1. Ver estadísticas\n");
    printf("2. Contar vocales\n");
    printf("3. Buscar y reemplazar\n");
    printf("4. Guardar en nuevo archivo\n");
    printf("5. Imprimir texto\n");
    printf("6. Salir\n");
    printf("Ingrese una opción: ");
    scanf("%d", &opcion);
    while (getchar() != '\n');  // limpiar buffer entrada
    return opcion;
}