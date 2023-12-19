#include <stdio.h>
#include <time.h> //Device time
#include <stdlib.h>


int main(){ //guessRandomNumber

    srand(time(NULL));
    int randomNumber = rand() % 15;
    int guessedNumber;
    int guessAmount = 0;
    int guessed = 0;


    do {
        guessAmount++;
        printf("Type a(nother) number between 0 - 15: \n");
        scanf("%d", &guessedNumber);

        if (guessedNumber == randomNumber){
            guessed = 1;
        } else {
            if (guessedNumber < randomNumber){
                printf("~higher~ \n");
            } else {
                printf("~lower~ \n");
            }
        }

    } while (!guessed);

    printf("You have successfully guessed the random number in the following amount of tries: %d", guessAmount);
    printf("\n\n");

}