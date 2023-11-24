#include <stdio.h>

int main(){ //isPrime
    int input;

    printf("PRIME PRIME PRIME! Is your number a prime?\n");
    scanf("%d", &input);

    if (input == 0 || input == 1){
        printf("Naurr. Better luck next time. Not a prime...");
        return 0;
    }

    for (int i = 2; i < input; i++){
        if (input % i == 0){
            printf("Naurr. Better luck next time. Not a prime...");
            return 0;
        }
    }

    printf("YESSS. YOUR NUMER IS A PRIME!!!!!");

    return 0;
}