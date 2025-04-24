
#include <stdio.h>

int main(){
int array_de_10[10];

for(int i = 11; i <= 20; i++)

{
    array_de_10[i -11] = i;
    printf("%d\n", array_de_10[i-11]);


}

}