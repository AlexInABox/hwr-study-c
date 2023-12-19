#include <stdio.h>
#include "task_3_modules/geometry.h"

void calculateCuboid() {
    double height;
    double width;
    double depth;
    printf("Hoehe: ");
    scanf("%lf", &height);
    printf("Breite: ");
    scanf("%lf", &width);
    printf("Tiefe: ");
    scanf("%lf", &depth);

    struct Cuboid temp = getCuboid(height, width, depth);
    printf("Flaeche (vorne, hinten): %lf\n", temp.partialFront);
    printf("Flaeche (links, rechts): %lf\n", temp.partialSide);
    printf("Flaeche (oben, unten): %lf\n", temp.partialGround);
    printf("Flaeche (gesamt): %lf\n", temp.area);
    printf("Volumen (gesamt): %lf\n", temp.volume);
}
/*void calculatePyramid() {
    double height;
    double width;
    printf("Hoehe: ");
    scanf("%lf", &height);
    printf("Breite: ");
    scanf("%lf", &width);
    struct Pyramid pyramid = calculatePyramidValues(height, width);
    printf("Flaeche (Grund): %lf\n", pyramid.bottomSurface);
    printf("Flaeche (Seite): %lf\n", pyramid.sideSurface);
    printf("Flaeche (gesamt): %lf\n", pyramid.totalSurface);
    printf("Volumen (gesamt): %lf\n", pyramid.totalVolume);
}
 */
/*void calculateBall() {
    double radius;
    printf("Radius: ");
    scanf("%lf", &radius);
    struct Ball ball = calculateBallValues(radius);
    printf("Flaeche (gesamt): %lf\n", ball.totalSurface);
    printf("Volumen (gesamt): %lf\n", ball.totalVolume);
}
 */
/*void calculateCone() {
    double radius;
    double height;
    printf("Radius: ");
    scanf("%lf", &radius);
    printf("Hoehe: ");
    scanf("%lf", &height);
    struct Cone cone = calculateConeValues(radius, height);
    printf("Flaeche (Grund): %lf\n", cone.bottomSurface);
    printf("Flaeche (Seite): %lf\n", cone.sideSurface);
    printf("Flaeche (gesamt): %lf\n", cone.totalSurface);
    printf("Volumen (gesamt): %lf\n", cone.totalVolume);
}
 */

int main() {
    int selection;
    do {
        printf("0 - Programm beenden\n");
        printf("1 - Quader berechnen\n");
        printf("2 - Pyramide berechnen\n");
        printf("3 - Kugel berechnen\n");
        printf("4 - Kegel berechnen\n");
        printf("Befehl: ");
        scanf("%d", &selection);
        int n = 0;
        switch (selection) {
            case 0:
                return 0;
            case 1:
                calculateCuboid();
                break;
            /*case 2:
                calculatePyramid();
                break;
            case 3:
                calculateBall();
                break;
            case 4:
                calculateCone();
                break;
                */
            default:
                printf("Ungueltiger Befehl!\n");
        }
        printf("----------------\n");
    } while (selection);
    return 1;
}