#include <stdio.h>

int main(){ //whichQuadrant
    int x, y;

    printf("Give me some coordinates an I will tell you in which quadrant they lie!\n");
    printf("x-coordinate pwease <3\n");
    scanf("%d", &x);
    printf("\ny-coordinate pwease <3\n");
    scanf("%d", &y);

    if (x == 0 && y == 0) {
        printf("You trickster hehe. The coordiantes you provided are [0, 0] and are in neither of the four quadrants >.<\n\n");
        return 0;
    }

    if (x > 0){
        if (y > 0){
            printf("Your coordinates are lying in the first quadrant!\n\n");
            return 0;
        } else if (y < 0){
            printf("Your coordinates are lying in the fourth quadrant!\n\n");
            return 0;
        }
    } else if (x < 0){
        //x < 0
        if (y > 0){
            printf("Your coordinates are lying in the second quadrant!\n\n");
            return 0;
        } else if (y < 0){
            printf("Your coordinates are lying in the third quadrant!\n\n");
            return 0;
        }
    }
    printf("You trickster hehe. The coordinates you provided are lying in neither of the four quadrants >.<\n\n");

    return 0;
}