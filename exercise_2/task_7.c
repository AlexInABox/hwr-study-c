#include <stdio.h>
#include <string.h>

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

int main(){ //isThisAPalindrom
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

    return 0;
}