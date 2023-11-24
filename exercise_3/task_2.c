#include <stdio.h>
#include <limits.h>

int main(){ //exploreLimits

    int maxInt = INT_MAX;
    unsigned int maxUnsignedInt = UINT_MAX;

    int maxIntPlus1 = maxInt + 1;
    unsigned int maxUnsignedIntPlus1 = maxUnsignedInt + 1;

    printf("%s%d\n", "MAX INT: ", maxInt);
    printf("%s%d\n\n", "MAX INT PLUS 1: ", maxIntPlus1);

    printf("%s%d\n", "MAX UNSIGNED INT: ", maxUnsignedInt);
    printf("%s%d\n", "MAX UNSIGNED INT PLUS 1: ", maxUnsignedIntPlus1);

    return 0;
}