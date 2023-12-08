#include "palindrome.h"
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

int isPalindrome(char a[]){
    char temp[40];
    strcpy(temp, a);

    return !strcmp(temp, strrev(a));
}
