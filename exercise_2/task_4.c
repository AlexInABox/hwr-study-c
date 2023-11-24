#include <stdio.h>

int main(){ //isThisALeapYear
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
