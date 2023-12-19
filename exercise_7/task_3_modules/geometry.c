#include "geometry.h"




struct Cuboid getCuboid(double a, double b, double c){

    struct Cuboid temp;

    temp.volume = a*b*c;

    temp.partialGround = a*b;
    temp.partialFront = a*c;
    temp.partialSide = b*c;

    temp.area = temp.partialGround*2 + temp.partialFront*c + temp.partialSide*2;

    return temp;
}