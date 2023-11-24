#include <stdio.h>

int main() { //drawGeo
    int shapeType;
    int size;


    printf("Here you can draw a geometrical shape inside of the terminal!\n");
    printf("You can choose between a triangle(1) or a square(2)!\n");
    printf("What shape do you want to draw? (press 1 or 2):\n");

    scanf("%d", &shapeType);

    printf("Perfect! Now pwease tell me the size you want your shape to be:\n");

    scanf("%d", &size);

    printf("Good choice! Here's your shape:\n\n");


    if (shapeType == 1) {
        for (int i = 1; i <= size; i++) {
            for (int j = 0; j < i; ++j) {
                printf("* ");
            }
            printf("\n");
        }
        return 0;
    } else if (shapeType == 2) {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                printf("* ");
            }
            printf("\n");
        }
        return 0;
    }
    printf("You have provided me with a shape that isn't supported yet! (kys) Please restart and pick either 1 (triangle) or 2 (square)! O.o\n");
    return 0;
}