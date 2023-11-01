#include <stdlib.h>
#include <time.h> //Device time
#include <stdio.h>
#include <string.h>


int calcQuadToTwenty();
int guessRandomNumber();
int whatMonth();
int isThisALeapYear();
int isThisAVowel();
int whichQuadrant();
int isThisAPalindrom();
int drawGeo();

int main() {
    //calcQuadToTwenty();
    //guessRandomNumber();
    //whatMonth();
    //isThisALeapYear();
    //isThisAVowel();
    //whichQuadrant();
    //isThisAPalindrom();
    drawGeo();

    return 0;
}

int calcQuadToTwenty(){
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

int guessRandomNumber(){
    srand(time(NULL));
    int randomNumber = rand() % 15;
    int guessedNumber;
    int guessAmount = 0;
    int guessed = 0;


    do {
        guessAmount++;
        printf("Type a(nother) number: \n");
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

int whatMonth(){

    int inputMonthIndex;

    printf("What months index do you want to convert? \n");
    scanf("%d", &inputMonthIndex);

    switch(inputMonthIndex) {
        case (1):
            printf("January!\n\n");
            return 0;
        case (2):
            printf("February!\n\n");
            return 0;
        case (3):
            printf("March!\n\n");
            return 0;
        case (4):
            printf("April!\n\n");
            return 0;
        case (5):
            printf("May!\n\n");
            return 0;
        case (6):
            printf("June!\n\n");
            return 0;
        case (7):
            printf("July!\n\n");
            return 0;
        case (8):
            printf("August!\n\n");
            return 0;
        case (9):
            printf("September!\n\n");
            return 0;
        case (10):
            printf("October!\n\n");
            return 0;
        case (11):
            printf("November!\n\n");
            return 0;
        case (12):
            printf("December!\n\n");
            return 0;
        default:
            printf("what is bro bluffin about???\n\n");
    }
}

int isThisALeapYear(){
    int yearOfChoice;

    printf("Type the year you want to check for being a leap year: ");
    scanf("%d", &yearOfChoice);

    if(!(yearOfChoice % 4)){
        if (yearOfChoice % 1000){
            printf("Yeah dude that's a leap year!!\n\n");
            return 0;
        } else(!(yearOfChoice % 400)); {
            printf("Yeah dude that's a leap year!!\n\n");
            return 0;
        }
    }
    printf("No dude that's obviously not a leap year...\n\n");
    return 0;
}

int isThisAVowel(){

    char listOfVowels[5] = {'a', 'e', 'i', 'o', 'u'};
    char charToCheck;

    printf("Give me a character and I'll tell you if it's a vowel!\n");
    scanf(" %c", &charToCheck);

    for(int i = 0; i < sizeof(listOfVowels); i++){
        if (listOfVowels[i] == charToCheck){
            printf("Yippie! You character is in fact a vowel!! Nice <3\n\n");
            return 0;
        }
    }

    printf(":( Seems like your character is not a vowel... Sorri~\n\n");
}

int whichQuadrant(){
    int x, y;

    printf("Give me some coordinates an I will tell you in which quadrant they lie!\n");
    printf("x-coordinate pwease <3\n");
    scanf("%d", &x);
    printf("\ny-coordinate pwease <3\n");
    scanf("%d", &y);

    if (x == 0 && y == 0) {
        printf("You trickster hehe. The coordiantes you provided are [0, 0] and are in neither of the four quadrants >.<\n\n");
        return 0;
    }

    if (x > 0){
        if (y > 0){
            printf("Your coordinates are lying in the first quadrant!\n\n");
            return 0;
        } else if (y < 0){
            printf("Your coordinates are lying in the fourth quadrant!\n\n");
            return 0;
        }
    } else if (x < 0){
        //x < 0
        if (y > 0){
            printf("Your coordinates are lying in the second quadrant!\n\n");
            return 0;
        } else if (y < 0){
            printf("Your coordinates are lying in the third quadrant!\n\n");
            return 0;
        }
    }
    printf("You trickster hehe. The coordinates you provided are lying in neither of the four quadrants >.<\n\n");
}

char *strrev(char *str) //needs to be implemented manually on unix
{
    char *p1, *p2;

    if (! str || ! *str)
        return str;
    for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
    {
        *p1 ^= *p2;
        *p2 ^= *p1;
        *p1 ^= *p2;
    }
    return str;
}

int isThisAPalindrom(){
    char str[40]; // declare the size of character string
    char strCopy[40];
    printf ("Welcome to: \"Is this word a palindrome?!\". Please enter your string to start: \n");
    scanf ("%s", str);

    strcpy(strCopy, str); //copy string to backup so strrev doesnt overwrite our only source

    if (!(strcmp(strCopy, strrev(str)))){
        printf("\nYippie that word is a palindrome!\n\n");
    } else{
        printf("\nNu-Uh! Not a palindrome!\n\n");
    }
}

int drawGeo(){
    int shapeType;
    int size;


    printf("Here you can draw a geometrical shape inside of the terminal!\n");
    printf("You can choose between a triangle(1) or a square(2)!\n");
    printf("What shape do you want to draw? (press 1 or 2):\n");

    scanf("%d", &shapeType);

    printf("Perfect! Now pwease tell me the size you want your shape to be:\n");

    scanf("%d", &size);

    printf("Good choice! Here's your shape:\n\n");


    if (shapeType == 1) {
        for (int i = 1; i <= size; i++){
            for (int j = 0; j < i; ++j) {
                printf("* ");
            }
            printf("\n");
        }
        return 0;
    } else if (shapeType == 2){
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                printf("* ");
            }
            printf("\n");
        }
        return 0;
    }
    printf("You have provided me with a shape that isn't supported yet! Please restart and pick either 1 (triangle) or 2 (square)! O.o\n");
}