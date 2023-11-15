#include <stdio.h>

void sort(int *a, int *b, int *c){
    int h;
    if (*a > *b){
        h = *a;
        *a = *b;
        *b = h;
    }
    if (*b > *c){
        h = *b;
        *b = *c;
        *c = h;
    }
    if (*a > *b){
        h = *a;
        *a = *b;
        *b = h;
    }
}

int main(){

    int a = 5;
    int b = 1;
    int c = 3;

    printf("%d ", a);
    printf("%d ", b);
    printf("%d\n", c);

    sort(&a, &b, &c);

    printf("%d ", a);
    printf("%d ", b);
    printf("%d\n", c);
    return 0;
}

