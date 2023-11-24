#include <stdio.h>

int main(){ //isThisAVowel

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
    return 0;
}