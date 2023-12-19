#include <stdio.h>

int main(){ //whatMonth

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