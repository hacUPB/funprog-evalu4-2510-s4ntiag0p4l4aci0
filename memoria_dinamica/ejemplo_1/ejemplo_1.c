#include <stdio.h>

void func(void);
void func_stat(void);

int main(void) {
    func();
    func();
    func();
    func();
printf("---------------\n");
    func_stat();
    func_stat();
    func_stat();
    func_stat();

    return 0;
}

void func(void) {
    int contador = 0;
    contador++;
    printf("Contador es: %d\n", contador);
}

void func_stat(void) {
    static int contador = 0;
    contador++;
    printf("Contador (en static) es: %d\n", contador);
}