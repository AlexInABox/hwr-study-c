#include <stdio.h>




int main() {

    int number = 123;
    double weirdNumber = 1.23;
    char letter = 'A';


    int *pointerNumber = &number;
    double *pointerWeirdNumber = &weirdNumber;
    char *pointerLetter = &letter;


    printf("%d\n", number);
    printf("%p\n", pointerNumber);      //00000059813ffc74
    printf("%f\n", weirdNumber);
                                               //<size of double>
    printf("%p\n", pointerWeirdNumber); //00000059813ffc68
    printf("%c\n", letter);
    printf("%p\n", pointerLetter); //00000059813ffc67


    return 0;
}