#include <stdio.h>
#include <string.h>

struct User{
    char username[10];
    char password[20];
};

int main(){ //userManagement

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