//HALO MY NAME IS EMU OTO-RI. EMU IS MEANING SMILE!
//4, 8, 15, 16, 23, 42
//4, 8, 15, 16, 23, 42

#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <string.h>

const float PI = 3.1415926;

int interpretPIOutput();
int exploreLimits();
int isEven();
int isPrime();
int getDistance();
int productTable();
int userManagement();

int main () {

    //interpretPIOutput();
    //exploreLimits();
    //isEven();
    //isPrime();
    //getDistance();
    //productTable();
    userManagement();


    return 0;
}

int interpretPIOutput(){
    printf("%f\n", PI); //float
    printf("%d\n", PI); //int
    printf("%c\n", PI); //char
    printf("%ld\n", PI); //longint

    return 0;
}

int exploreLimits(){

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

int isEven(){
    int input;

    printf("AAAAAAAAAAAAAAA! IS THIS NUMBER EVEN?!?!?!?!?!?!\n");
    scanf("%d", &input);

    if (!(input % 2)) {
        printf("OMG YOUR NUMBER IS EVEN!!!!!");
        return 0;
    }

    printf("NNNNNAAAAUUUUURR! YOUR NUMBER IS NOT EVEN ;(((((((((((((((");

    return 0;
}

int isPrime(){
    int input;

    printf("PRIME PRIME PRIME! Is your number a prime?\n");
    scanf("%d", &input);

    if (input == 0 || input == 1){
        printf("Naurr. Better luck next time. Not a prime...");
        return 0;
    }

    for (int i = 2; i < input; i++){
        if (input % i == 0){
            printf("Naurr. Better luck next time. Not a prime...");
            return 0;
        }
    }

    printf("YESSS. YOUR NUMER IS A PRIME!!!!!");

    return 0;
}


struct Position {
    int x;
    int y;
    char name[10];
};

struct Vehicle {
    double hourPerKilometer;
    char name[20];
};

int getDistance(){
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

int productTable(){

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

struct User{
    char username[10];
    char password[20];
};

int userManagement(){

    char loginUsername[10];
    char loginPassword[20];

    int userExists = 0;
    int userIndex;


    struct User userAccounts[5] = {
            {"Markus", "markusStark"},
            {"Helene", "hertha123"},
            {"admin", "passwort123"},
            {"Jakob", "konzert"},
            {"Domenik", "alex1234"},
    };


    printf("Please login to your account!\n");
    printf("Username:");
    scanf("%s", loginUsername);

    for (int i = 0; i < 5; i++){
        if (!(strcmp(loginUsername, userAccounts[i].username))){
            userExists = 1;
            userIndex = i;
            break;
        }
    }

    if (!userExists) {
        printf("This user doesn't exist :( Bye bye...");
        return 0;
    }

    for (int i = 1; i < 4; i++) {

        printf("%s%s%s", "password for ", loginUsername, ":");
        scanf("%s", loginPassword);

        if (((strcmp(loginPassword, userAccounts[userIndex].password)) == 0)) {
            printf("%s%s%s", "Yippie you did it! Welcome ", loginUsername, ".");
            return 0;
        }

        if ((3-i != 0)) {
            printf("NuUh! That's the wrong password :(\n");
            printf("%s%d%s", "You have ", 3 - i, " tries remaining!\n\n");
        }
        else{
            printf("Nope. Seems like you dont know the password! Bye Bye !");
        }

    }

    return 0;
}