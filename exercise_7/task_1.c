#include <stdio.h>
#include "task_1_modules/palindrome.h"

int main() { //isThisAPalindrom
    char str[40]; // declare the size of character string

    printf("Welcome to: \"Is this word a palindrome?!\". Please enter your string to start: \n");
    scanf("%s", str);


    if (isPalindrome(str)) {
        printf("\nYippie that word is a palindrome!\n\n");
    } else {
        printf("\nNu-Uh! Not a palindrome!\n\n");
    }

    return 0;
}