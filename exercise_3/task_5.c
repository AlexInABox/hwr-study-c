#include <stdio.h>
#include <math.h>

struct Position {
    int x;
    int y;
    char name[10];
};

struct Vehicle {
    double hourPerKilometer;
    char name[20];
};

int main(){ //getDistance
    double distance;
    int xDiff;
    int yDiff;

    int userInputPosA;
    int userInputPosB;

    int preferredVehicle;
    double timeToDestination;

    struct Position orte[5] = {
            {0, 0, "Berlin"},
            {1, 0, "Potsdam"},
            {1, -5, "Saarland"},
            {3, 15, "Magdeburg"},
            {10, -5, "Moskau"}
    };

    struct Vehicle vehicles[5] = {
            {0.1, "Car"},
            {0.5, "Public Transport"},
            {1, "Ship"},
            {3, "Bicycle"},
            {10, "Walking"},
    };

    printf("From where to where do you want to travel?\n\n");
    for (int i = 0; i < 5; i++){
        printf("%s%d%s%s\n", "Type \"", i, "\" for: ", orte[i].name);
    }

    printf("\nI want to go from:");
    scanf("%d", &userInputPosA);
    printf("to here:");
    scanf("%d", &userInputPosB);

    struct Position pointA = orte[userInputPosA];
    struct Position pointB = orte[userInputPosB];

    //calculate distance form here on:

    if (pointA.x >= pointB.x)
        xDiff = pointA.x - pointB.x;
    else
        xDiff = pointB.x - pointA.x;

    if (pointA.y >= pointB.y)
        yDiff = pointA.y - pointB.y;
    else
        yDiff = pointB.y - pointA.y;


    distance = sqrt((xDiff*xDiff) + (yDiff*yDiff));

    //output:
    printf("%s%s%s%s%s%f", "\nThe distance between ", pointA.name, " and ", pointB.name,  " in km is: ", distance);


    printf("\n\nNow tell me: What vehicle do you plan to take on your trip:\n\n");
    for (int i = 0; i < 5; i++){
        printf("%s%d%s%s\n", "Type \"", i, "\" for: ", vehicles[i].name);
    }

    scanf("%d", &preferredVehicle);
    struct Vehicle vehicle = vehicles[preferredVehicle];

    timeToDestination = vehicle.hourPerKilometer * distance;

    printf("%s%s%s%s%s%s%s%f%s", "\nBy ", vehicle.name, " you get from ", pointA.name, " to ", pointB.name, " in ", timeToDestination, " hours!");

    return 0;
}