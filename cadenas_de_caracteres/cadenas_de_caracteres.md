## Preguntas de control

Responde estas preguntas para asegurarte de que has comprendido bien el tema:

1. ¿Por qué `sizeof("Hola")` devuelve 5, pero `strlen("Hola")` devuelve 4?

- Porque 
2. ¿Cuál es la diferencia práctica entre declarar una cadena como arreglo (`char saludo[]`) y como puntero (`char *saludo`)?

- Cuando se declara como arreglo se puede editar el contenido, cuando se declara como puntero char *saludo, se guarda en una posición de solo lectura, por ende no se puededitar.


3. ¿Cómo evitas un "buffer overflow" al copiar o concatenar cadenas?
 - Principalmente podemos evitarlo al no utilizar `scanf()`, que si bien funciona no pone un limite de caracteres volviendola así insegura. Es mejor utilizar `fgets(cadena, sizeof(array). stdin)` en esta si se pone un limite de caracteres.



4. ¿Qué hace exactamente la función `strcspn()` y por qué es útil usarla junto con `fgets()`?


![imagen](./images/tabla_memoria.png)

## Actividad 2: Mapa visual de cadenas

Realiza un diagrama a mano del siguiente arreglo:

```c
char str[6] = "Hello";
```

- Indica claramente cada dirección de memoria, cada carácter almacenado, incluyendo el terminador nulo (`'\0'`).
- Responde:
    - ¿Qué pasa si asignas `str[5] = '!'`?
        - Acá se reemplaza el caracter nulo por !, eerntoces se produce un Buffer overflow

    - ¿Qué pasa si asignas `str[6] = 'X'`?

        - Esta posición no existe, es una violación de acceso a memoria.