//HALO MY NAME IS EMU OTO-RI. EMU IS MEANING SMILE!
//4, 8, 15, 16, 23, 42
//4, 8, 15, 16, 23, 42
#include <stdio.h>

int fibRec(int);
int fibIte(int);
int sumToRec(int);
int sumToIte(int);

int main () {
    int input;

    printf("Input number pwease:\n");
    scanf("%d", &input);

    int sumTo = sumToRec(input);
    printf("%d", sumTo);

    return 0;
}

int fibRec(int n){
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    return fibRec(n - 1) + fibRec(n - 2);
}

int fibIte(int n){
    int prev = 0;
    int fib = 1;

    for (int i = 1; i < n; i++){
        int temp = fib;
        fib = prev + fib;
        prev = temp;
    }
    return fib;
}

int sumToRec(int n) {

    if (n == 0)
        return 0;

    return n + sumToRec(n - 1);
}



int sumToIte(int n){

    int sum = 0;
    for (int i = 1; i <= n; i++){
        sum += i;
    }
    return sum;
}