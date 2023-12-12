#ifndef GEOMETRY_H
#define GEOMETRY_H

struct Cuboid{
    double partialFront;
    double partialGround;
    double partialSide;

    double area;
    double volume;
};

struct Cuboid getCuboid(double a, double b, double c);

#endif //GEOMETRY_H