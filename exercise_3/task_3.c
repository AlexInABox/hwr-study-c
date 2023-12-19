#include <stdio.h>


int main(){ //isEven
    int input;

    printf("AAAAAAAAAAAAAAA! IS THIS NUMBER EVEN?!?!?!?!?!?!\n");
    scanf("%d", &input);

    if (!(input % 2)) {
        printf("OMG YOUR NUMBER IS EVEN!!!!!");
        return 0;
    }

    printf("NNNNNAAAAUUUUURR! YOUR NUMBER IS NOT EVEN ;(((((((((((((((");

    return 0;
}