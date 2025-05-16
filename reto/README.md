

## RETO

- Este es el último archivo MarkDown del curso, el fin de una historia y de un viaje. Por eso este archivo será un poco diferente a lo acostumbrado.

- NOTA: si bien el reto pide poner la estadísticas en un documento aparte, este programa no solo las pone en un archivo, sino que las imprime en pantalla. Por eso es necesario especificar cuando se quiere imprimir en un documento nuevo.

### Capítulo I: Contexto
---
- Como cúlmen del curso, este reto incluye todos los temas trabajados durante el semestre, desde  el cntrol de versión por medio de repositorios, hasta la gestión de archivos, no sin ignorar el entendimiento del funcionamiento de los computadores, la sintaxis de c, los condicionales, bucles arreglos y memoria dinámica. 

- Heredando el menú y la repetitividad de la calculadora para ingenieros electricistas y electrónicos, una vez más se presenta un menú interactivo basado en cases. Pero, acá no se presenta una calculadora, estamos ante un editor de texto, que lee, hace acciones y permite hacer modificaciones al contenido. Algún día todos soñamos con ser un Bill Gates o un Mark Zuckerberg, que desarrollaban herramientas en la universidad, y acá estamos recogiendo los frutos, teniendo aquí ya un editor de texto, que ha sido llamado `word.c` en honor a la famosa herramienta de Microsoft.

- Ahora sí adentremonos a conocer nuestro progama.


### Capítulo II: Conozcamos el programa
--- 

- Este programa está compuesto por funciones, cada función correpnde a una parte especifica del programa, lo cual facilita, no solo el debugging, sino que permite estudiar independientemente cada función. Cada función es un pograma especial destinado para un fin, y sí mantenemos la función principal lo más despejadamente posible. Así como el cuerpo humano tiene varios sistemas: el digestivo, óseo, linfático, etc; todo confluye en el cerebro, cada función es un sistema y el main donde se adminstra. 

### `main(){}`

- La función main, en este caso, está compuesta de un bucle con un condicional basado en case. Existe una función que le pide al usuario un numero de opción acorde a la necesidad que presente, y con el valor que se retorna, en el main se selecciona el caso. Luego cada caso, segun la necesidad, llama a ejecución a una función que desempeña la tarea solicitada. Cuando el caso corresponde a salir, se suspende el bucle y se da las gracias.

### `menu(){}`

- Acá le presentamos al usuario las opciones de las funciones disponibles, cada una asociada cn un número. El usuario ingresa el numero y le retornamos al main ese número para hacer el análisis al case. 

- Éstas son las opciones:



    1. Ver estadíscsticas
    2. Contar vocales
    3. Buscar y reemplazar
    4. Guardar en nuevo archivo
    5. Imprimir texto
    6. Salir
    


### `abrir_archivo(){}`

- Primero declaramos archivo como puntero y utilizamos variables para calcular el tamaño de memoria a reservar

```c
    char nombre[100];
    FILE *archivo;
    int tamano = 0;
    char *mem_temporal = NULL, *temp;
```


- Desde la consola con `fgets()` tomamos el nombre del archivo, o la ruta del archivo que nuestro usario seleccione. Se utilizó un método más eficiente para la comprobación del puntero y ejecuión de la acción a la vez, pues si no se puede relaizar la función devuelve un NULL, esto a diferencia de los dos pasos, con los que veníamos trabajando.

-   Con una función auxiliar, bastante ejecutada a lo largo del programa, que se llama, `recalcular_mem_temporal()`, podemos calcular el tamaño, para quitarle el enter a la entrada y reemplazarlo por el caracter nulo de las cadenas de texto. Así podemos manejar todo el archivo con memoria dinamica como arreglo de caracteres con punteros y utilizar las funciones propias de la memoria dinámica.

- Posteriormente, una vez tenemos el nombre del archivo, por medio de la función prestablecida `fopen()`, ya tenemos el nombre como cadena de strings, y lo abrimos en modo lecutra de la forma: `archivo = fopen(nombre, "r");`

- Posteriormente con un While, recorremos todo el archivo, hasta encontrar el End Of File (EOF), que si bien no es un caracter ascii, si es una codificación que permite hallar el fin del archivo.

- A partir de este bucle, es posible calcular el tamaño de memoria a reservar, para luego guardar allí la información del archivo como una cadena de caracteres con el espacio preciso para no consumir más almacentamiento.

- Y es el puntero a la memoria temporal lo que le entregamos al main, para que con ese arreglo de datos se realicen todas las operaciones. 

- Nota: Se usa realloc, en vez de malloc, pues el archivo puede modificar su tamaño a lo largo de esta ejecucuión, el realloc, permite que si no cabe, se reasigne el bloque completo junto, en donde quepa.


###  `recalcular_mem_temporal()`

- Esta función por medio de `strlen()` nos permite contar la cantidad de caracteres del texto ingresado, y posteriormente, cambiamos el caracter enter `'\n'` por el de caracter nulo `'\0'` para indicar el fin de la cadena de caracteres, así usamos el espacio preciso, sea para nombres, o en los requerimientos posteriores del programa.

### `estad_txt(){}`

- En comparación con la función anterior esta es mucho más simple, debido a que en `c` hay formas de identificar caracteres de espacio y salto de linea, lo que nos ayuda con las estadísticas.

- Para cada valor a contar se crea una variable con su nombre

- Con un while, que analiza caracter por caracter hasta que el carater sea \0, identificamos los carcteres bajo los siguientes criterios:

    - si no es slato de linea, cuenta como caracter.

    - Si es espacio, cuenta como caracter, y añade 1 al recuento de palabras, esto es posible gracias a la librería `<ctype.c>`, pues así como hay funciones que identifican caracteres como mayuscula o minúscula, también existe `isspace()` para los espacios.

- Usa `printf()` para imprimir en pantalla y `fprintf()` para añadirlos posteriormente al archivo nuevo si el usuario lo desea.


### `cont_voc(){}`

- Resutla qua acá si me tuve que contener, como la idea es conservar el texto, nos e pueden usar los métodos demoledores que solía sugerir en clase.

- Primero tenemos que dejar claro que las vocales serán vocales, sea en mayúescula o minúscula. Entonces tenemos que tener en mente ambas para la contabilización de vocales. 

Cuenta la cantidad de cada vocal (a, e, i, o, u), sin distinguir entre mayúsculas y minúsculas. Convierte cada carácter con tolower antes de la comparación.

- Nuevamente gracias a las funciones de `C` es posible ahorrarnos gran parte del trabajo, y es así que con la función `tolower()` podemos minuscúlizar todas las vocales. Y por medio de un bucle, comparar los caracteres con la 'a', 'e', 'i' 'o' y 'u'. Y depende de la consición aumentar el contador en una, en otra o en ninguna hasta que el caracter sea  `'\0'`.

-- Usa `printf()` para imprimir en pantalla y `fprintf()` para añadirlos posteriormente al archivo nuevo si el usuario lo desea.


### `reemplazar(){}`
- Ésta es una de las fucniones más interesantes ya auq incluye cun puntero doble, también conocido como un puntero a puntero. Pero realmente es muy simple.

- Cuando el usuario ingresa una palabra para buscar, y otra de reemplazo, el programa primero recorre el texto original. LUego contruye una nueva versión del mismo con los cambions hechos, y recalcula el tamaño. Es decir, si la palabra original tenía 5 letras, y la nueva 3, entonces recalcula con 2 letras menos en cada palabra reemplazada, de igual forma si es más, recalcula con mayor espacio. Este programa se caracteriza por usar la memoria lo más justa posible, por eso se le presta tanta atención. Acá también se usa usamos `recalcular_mem_temporal()` por eso es una función auxiliar muy útil.

- El doble puntero juega un papel crucial. Pues, un puntero apunta a una dirección de memoria, entonces acabamos de crear una nueva dirección de memoria con los nuevos datos. Ahora necesitamos que la variable original contenga esos datos, como es un arreglo de datos, esta está denotada por un puntero.  El doble puntero hace que el puntero del array apunte a donde apunta este puntero, es decir, la nueva dirección de memoria de los datos nuevos. 

- Posteriormente se liberan las posiciones de memoria que ya no se piensan utilizar.



### `guardar_archivo(){}`

- Como creamos un nuevo archivo, hay que preguntarle al usuario como quiere que se llame.

- Para esto usamos la misma estructura que abriendo el archivo porprimera vez, lo único que cambia es la forma de abrir el archivo, como en este caso queremos editar y no leer, ponemos el nombre del nevo archivo y lo abrumos como `archivo = fopen(nombre, "w");` que nos permite editarlo.

- Luego se escribe en el archivo vacío, desde el inicio, lo que está en la memoria temporal.

### `imprimir(){}`

- Es la más simple de todas, solamente imprime la cadena de caracteres almacenada en la memoria temporal. 

### `cargando(){}`

- Se tien un bucle `for()` de 1 a  100000. Luego la i se divide entre 1000, dando así como resultado los números del 1 al 100, pero el tiempo de procesamiento es mayor y alcanza a ser visible para el usuario. Con `'\r'` se permite reiniciar la linea del `printf()`, cada vez que se ejecuta, viene de el retorno de carro en las máquinas de escribir. 37 es el código ascii del signo de porcentaje (%).

### NOTA

- Se cerraron los archivos y se cerraron las memorias cada vez que se dejaron de usar.

### Capítulo III: Agradecimientos
---

- Se le agradece a Henry por todo lo enseado durante el semestre y se le deséan éxitos.

- Y a Diego Cuartas cuyas actividades de informes de laboratorio, sirvieron para obtener las ecuaciones para algunos retos.

### Capítulo IV: Despedida
---

- Siendo ésta la útima bítacora es momento de decir adiós.
