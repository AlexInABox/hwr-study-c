#include <stdio.h>

int main(){ //productTable

    int multiplier = 1;
    for (int o = 1; o <= 12; o++) {
        for (int i = 1; i <= 12; i++){
            printf("%-6d", i*multiplier);
        }
        multiplier += 1;
        printf("\n");
    }
    return 0;
}