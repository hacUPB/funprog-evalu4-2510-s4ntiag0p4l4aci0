## calloc (C Alloc) 
- Asignación y Cero
- Prototipo: `void *calloc(size_t num, size_t size)`

- Funcionalidad: Asigna un bloque de memoria contiguo para una matriz de num elementos, donde cada elemento tiene un tamaño de size bytes.

- Inicialización: Inicializa todos los bits del bloque asignado a cero.

- Retorna: Un puntero al inicio del bloque asignado, o NULL si falla la asignación.

- Uso: Ideal para reservar memoria que se espera ser utilizada con datos de tipo numérico, como enteros o flotantes, donde la inicialización a cero puede ser crucial.

--- 

## realloc (Reasignación) 
- Cambiar el Tamaño
- Prototipo:
void `*realloc(void *ptr, size_t newsize)`
- Funcionalidad: Modifica el tamaño de un bloque de memoria previamente asignado al que apunta ptr.
- Copia: Si el nuevo tamaño es mayor, intenta mantener el contenido del bloque antiguo (hasta el menor de los tamaños).

- Reasignación:
Si no hay suficiente memoria contigua para redimensionar el bloque en su lugar, realloc puede mover el bloque a una nueva ubicación en la memoria.

- Retorna:
Un puntero al bloque redimensionado, o NULL si falla la reasignación o si newsize es cero.
Uso:
Permite ajustar el tamaño de la memoria asignada dinámicamente, por ejemplo, para una matriz que necesita crecer o contraerse durante la ejecución del programa.

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
  int *arr;
  int i;

  // Asignar memoria para 5 enteros con calloc (inicializados a 0)
  arr = (int *)calloc(5, sizeof(int));
  if (arr == NULL) {
    printf("Error: no se pudo asignar memoria con calloc\n");
    return 1;
  }

  // Modificar algunos elementos
  for (i = 0; i < 5; i++) {
    arr[i] = i * 2;
  }

  // Redimensionar la matriz con realloc (a 8 elementos)
  arr = (int *)realloc(arr, 8 * sizeof(int));
  if (arr == NULL) {
    printf("Error: no se pudo redimensionar memoria con realloc\n");
    return 1;
  }

  // Modificar los nuevos elementos
  for (i = 5; i < 8; i++) {
    arr[i] = i * 3;
  }

  // Imprimir los elementos
  for (i = 0; i < 8; i++) {
    printf("arr[%d] = %d\n", i, arr[i]);
  }

  // Liberar la memoria
  free(arr);

  return 0;
}
```