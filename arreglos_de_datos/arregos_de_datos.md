

### Preguntas de control

1. ¿Qué valor contiene el siguiente dato: `dato[5]`, si el arreglo se inicializa de la siguiente manera: `int datos[6] = {5, 82, 41};`?

- Cuando un arreglo tiene un tamaño determinado, y hay posiciones sin llenar, estas toman 0 como valor por defecto, por ende `dato[5]` es 0.

2. ¿Cómo determinar el número de elementos en un arreglo cuando su tamaño no se especifica explícitamente?

- se utiliza 
```c
"tipo de dato (int, float, etc)" n = sizeof(arreglo) / sizeof(arreglo[0]);
```

En la cual obtenemos el tamaño de bytes del arreglo, y lo dividimos por el tamaño en bytes de un solo elemento. Así obtenemos el número de elementos para cualquier tipo de dato.

### Preguntas de comprensión

1. ¿Qué se pasa realmente a la función cuando enviamos un arreglo como parámetro?

- Cuando hacemos esto lo que realmente sucede es que pasamos la dirección del primer elemento del arreglo, esto por medio de un puntero, permitiendo así modificar de manera directa el contenido del arreglo.


2. ¿Qué diferencia hay entre declarar el parámetro como `int arr[]` y `int *arr`?

- Ya que ambos representan un puntero a un mismo elemento, no hay ningunadiferencia y se pueden utilizar ambos.

3. ¿Qué implicaciones tiene esto sobre la modificación del arreglo dentro de la función?

- Significa que los cambios que se hagan al arreglo dentro de la función, se verán directamente reflejados en los valores de los datos del arreglo. Es decir las modificaciones en cualquier función reemplazan los valores originales del arreglo.


---

### Preguntas finales para reforzar el aprendizaje

1. ¿Cuál es exactamente la diferencia entre un arreglo y un puntero?

- Un arreglo es una estructura de datos mientras que el puntero es una variable que apunta a una dirección de memoria,en este caso la del primer elemento de la estructura de array.

2. ¿Cómo están almacenados en la memoria los elementos de una matriz?

- En las matrices se almacenan primero todos los elementos de una fila, y luego lo de las siguientes.

si por ejemlo fuera

```c

int array[3][4] = {
    { 1,  2,  3,  4},   // fila 0
    { 5,  6,  7,  8},   // fila 1
    { 9, 10, 11, 12}    // fila 2
};

| 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 |
^                         ^                       ^
fila 0                  fila 1                 fila 2

array[0][0] hasta array[0][3] → primera fila

array[1][0] hasta array[1][3] → segunda fila

array[2][0] hasta array[2][3] → tercera fila
```


3. ¿Qué precauciones se deben tomar al usar punteros para recorrer arreglos?

- Evitar tratar de ir a espacios de memoria que no son del arreglo. Por ejemplo si el arreglo es 

```c
int array = {1,2,3,4,5,7,8}
```
es posible que nos confundamos y tratemos de ir a la posición de memoria `array[8]`para el valor  de 8, pero debemos acordarnos que los arrays empiezan en la posición `array[0]`, entonces la posición de memoria de 8 es `array[7]`.

- Para las unciones es importante dar el tamaño del arreglo, pues el parametro para el array es un puntero, que solo apunta a una posición de memoria y no da el numero de elementos del arreglo.

- Adicionalmente hay que verificar que el puntero si esté asociado a la dirección de memoria de el arreglo que queremos modificar, para no ir a modificar otro o arroje error si es NULL.