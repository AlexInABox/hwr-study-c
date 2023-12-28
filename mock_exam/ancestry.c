#include "ancestry_modules/ancestry.h"

#include <stdio.h>

//Biologischer Stammbaum

int main() {

    // Test Personen (fiktiv):
    addPerson("Alex", "Mannheim", NULL, NULL);
    addPerson("Markus", "Rühl", NULL, NULL);
    addPerson("Theo", "Neumann", getPersonByIndex(0), getPersonByIndex(1));

    addPerson("Anna", "Schmidt", getPersonByIndex(2), NULL);
    addPerson("Peter", "Müller", NULL, getPersonByIndex(2));
    addPerson("Sophie", "Hansen", getPersonByIndex(3), getPersonByIndex(4));

    addPerson("Klaus", "Becker", getPersonByIndex(2), getPersonByIndex(3));
    addPerson("Maria", "Schulz", getPersonByIndex(5), getPersonByIndex(6));


    printf("%s\n\n", "--- Biologischer Stammbaum ---");

    while (1) {
        printf("%s\n", "Was möchtest du machen?");
        printf("%d%s\n", 0, " - Person hinzufügen");
        printf("%d%s\n", 1, " - Stammbaum einer Person ausgeben");
        printf("%d%s\n", 2, " - Beenden");

        int whichMode = 2;

        scanf("%d", &whichMode);

        switch (whichMode) {
            case 0:
                printf("%s\n\n", "--- Person hinzufügen ---");

                char firstName[25];
                char surName[25];
                printf("%s\n", "Vorname: ");
                scanf("%24s", firstName);

                printf("%s\n", "Nachname: ");
                scanf("%24s", surName);


                if (findPersonByName(firstName, surName) != NULL) {
                    printf("%s\n\n", "Warum bist du so gemein?? Diese Person existiert bereits...");
                    break;
                }
                if (getSize() == 0) {
                    printf("%s\n\n",
                           "Die Person wurde ohne Eltern hinzugefügt, da sich bisher keine anderen Personen in der Liste befinden!");
                    addPerson(firstName, surName, NULL, NULL);
                    break;
                }

                int addParents = 0;
                printf("%s\n", "Möchtest du zu dieser Person auch Eltern hinzufügen?");
                printf("%d - %s\n", 0, "Nein");
                printf("%d - %s\n", 1, "Ja");
                scanf("%d", &addParents);

                if (addParents) {
                    printf("%s\n\n", "--- Mögliche Eltern ---");


                    printf("%d - %s\n", 0, "keine Angabe");
                    for (int i = 0; i < getSize(); i++) {
                        struct person *possibleParent = getPersonByIndex(i);

                        printf("%d - %s %s\n", i + 1, possibleParent->firstName, possibleParent->surName);
                    }

                    int parentA;
                    struct person *parentAPtr = NULL;
                    int parentB;
                    struct person *parentBPtr = NULL;

                    printf("%s\n", "Vater: ");
                    scanf("%d", &parentA);
                    printf("%s\n", "Mutter: ");
                    scanf("%d", &parentB);

                    if (parentA) {
                        parentAPtr = getPersonByIndex(parentA - 1);
                    }
                    if (parentB) {
                        parentBPtr = getPersonByIndex(parentB - 1);
                    }

                    addPerson(firstName, surName, parentAPtr, parentBPtr);

                    printf("%s\n\n", "Die Person wurde erfolgreich mit Elternteilen hinzugefügt!");
                    break;
                } else {
                    addPerson(firstName, surName, NULL, NULL);
                    printf("%s\n\n", "Die Person wurde erfolgreich hinzugefügt!");
                }
                break;
            case 1:
                printf("%s\n", "Von welcher Person möchtest du den Stammbaum lesen?");
                printf("%d - %s\n", 0, "Abbruch");
                for (int i = 0; i < getSize(); i++) {
                    struct person *human = getPersonByIndex(i);

                    printf("%d - %s %s\n", i + 1, human->firstName, human->surName);
                }
                int indexOfPerson;
                scanf("%d", &indexOfPerson);

                if (!indexOfPerson)
                    break;
                indexOfPerson--;

                struct person *tempPerson = getPersonByIndex(indexOfPerson);

                printf("%s%s %s    ", "Person: ", tempPerson->firstName, tempPerson->surName);

                if (tempPerson->father != NULL) {
                    printf("%s%s %s, ", "Vater: ", tempPerson->father->firstName, tempPerson->father->surName);
                    if (tempPerson->father->father != NULL)
                        printf("%s%s %s, ", "Großvater: ", tempPerson->father->father->firstName,
                               tempPerson->father->father->surName);
                    if (tempPerson->father->mother != NULL)
                        printf("%s%s %s, ", "Großmutter: ", tempPerson->father->mother->firstName,
                               tempPerson->father->mother->surName);
                    printf("\n");
                }

                if (tempPerson->mother != NULL) {
                    printf("%s%s %s\n", "Mutter: ", tempPerson->mother->firstName, tempPerson->mother->surName);
                    if (tempPerson->mother->father != NULL)
                        printf("%s%s %s\n", "Großvater: ", tempPerson->mother->father->firstName,
                               tempPerson->mother->father->surName);
                    if (tempPerson->mother->mother != NULL)
                        printf("%s%s %s\n", "Großmutter: ", tempPerson->mother->mother->firstName,
                               tempPerson->mother->mother->surName);
                }
                printf("\n");
                break;
            case 2:
                return 0;
            default:
                printf("%s\n\n", "--- Fehlerhafte eingabe! ---");
                break;
        }
    }
}