#include <stdio.h>
#include "task_2_modules/voidStack.h"

int main(){
    int a = 15;
    int b = 14;
    int c = 13;

    add(&a);
    add(&b);
    add(&c);

    printf("%s%d\n","Index 2: ", *(int*)get(2));
    printf("%s%d\n","Index 1: ", *(int*)get(1));
    printf("%s%d\n\n","Index 0: ", *(int*)get(0));

    printf("%s%d\n\n", "getSize() = ", getSize());

    printf("%s\n\n", "Removing index 1...");

    removeIndex(1);

    printf("%s%d\n","Index 1: ", *(int*)get(1));
    printf("%s%d\n\n","Index 0: ", *(int*)get(0));

    printf("%s%d\n\n", "getSize() = ", getSize());


    printf("%s%d\n\n", "isEmpty() = ", isEmpty());

    printf("%s\n", "Removing index 0...");
    printf("%s\n\n", "Removing index 0...");

    removeIndex(0);
    removeIndex(0);

    printf("%s%d\n\n", "isEmpty() = ", isEmpty());

    printf("%s%d\n\n", "getSize() = ", getSize());

}