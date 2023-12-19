#include <stdio.h>

int main(){ //calcQuadToTwenty
    int i = 0;

    printf("for loop: \n\n");
    for (i = 1; i <= 20; i++){
        int quad = i*i;

        printf("Quad(");
        printf("%d", i);
        printf("): ");
        printf("%d", quad);
        printf("\n");
    }

    printf("\nwhile loop: \n\n");
    i = 1;
    while(i <= 20){
        int quad = i*i;

        printf("Quad(");
        printf("%d", i);
        printf("): ");
        printf("%d", quad);
        printf("\n");

        i++;
    }

    i = 1;
    printf("\ndowhile loop: \n\n");
    do{
        int quad = i*i;

        printf("Quad(");
        printf("%d", i);
        printf("): ");
        printf("%d", quad);
        printf("\n");

        i++;
    } while (i <= 20);
}