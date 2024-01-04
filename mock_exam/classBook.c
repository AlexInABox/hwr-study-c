#include "classBook_modules/classBook.h"

#include <stdio.h>

//Klassenbuch

int main() {


    printf("%s\n\n", "--- Klassenbuch ---");

    while (1) {
        printf("%s\n", "Was möchtest du machen?");
        printf("%d%s\n", 0, " - Schüler hinzufügen");
        printf("%d%s\n", 1, " - Noten eines Schülers aktualisieren");
        printf("%d%s\n", 2, " - Notendurchschnitt der Klasse ausgeben");
        printf("%d%s\n", 3, " - Beenden");

        int whichMode = 3;

        scanf("%d", &whichMode);

        printf("\n");

        switch (whichMode) {
            case 0:
                printf("%s\n\n", "--- Schüler hinzufügen ---");

                char firstName[25];
                char surName[25];
                printf("%s\n", "Vorname: ");
                scanf("%24s", firstName);

                printf("%s\n", "Nachname: ");
                scanf("%24s", surName);

                printf("\n");

                addStudent(firstName, surName);

                printf("%s\n\n", "Der Schüler wurde erfolgreich hinzugefügt!");
                break;
            case 1:
                printf("%s\n\n", "--- Noten eines Schülers aktualisieren ---");

                printf("%s\n", "Von welchem Schüler möchtest du die Noten aktualisieren?");

                printf("%d - %s\n", 0, "Abbruch");
                for (int i = 0; i < getSize(); i++) {
                    struct student *student = getStudentByIndex(i);

                    printf("%d - %s %s\n", i + 1, student->firstName, student->surName);
                }

                int indexOfStudent;
                scanf("%d", &indexOfStudent);
                printf("\n");

                if (indexOfStudent < 1 || indexOfStudent > getSize())
                    break;
                indexOfStudent--;

                struct student *selectedStudent = getStudentByIndex(indexOfStudent);


                printf("%s\n", "Welche Note möchtest du aktualisieren?");

                while (1) {
                    printf("%d - %s\n", 0, "Abbruch");
                    printf("%d - %s\n", 1, "Mathe");
                    printf("%d - %s\n", 2, "Deutsch");
                    printf("%d - %s\n", 3, "Englisch");

                    int selectedGradeType;
                    scanf("%d", &selectedGradeType);

                    if (selectedGradeType < 1 || selectedGradeType > 3) {
                        printf("\n");
                        break;
                    }

                    printf("\n%s\n", "Welche Note möchtest du vergeben?");

                    double chosenGrade = 0.0;
                    scanf("%lf", &chosenGrade);

                    if (chosenGrade < 0.8 || chosenGrade > 6.0) {
                        printf("%s\n\n", "Solch eine Note kannst du nicht vergeben!");
                        break;
                    }

                    if (selectedGradeType == 1)
                        selectedStudent->gradeMaths = chosenGrade;
                    if (selectedGradeType == 2)
                        selectedStudent->gradeGerman = chosenGrade;
                    if (selectedGradeType == 3)
                        selectedStudent->gradeEnglish = chosenGrade;

                    printf("\n%s\n", "Note wurde erfolgreich aktualisiert!");

                    printf("\n%s\n", "Welche weiteren Noten möchtest du aktualisieren?");
                }
                break;
            case 2:
                printf("%s%lf\n\n", "Der Notendurchschnitt dieser Klasse ist: ", getAverageGrade());
                break;
            case 3:
                return 0;
            default:
                printf("%s\n\n", "--- Fehlerhafte eingabe! ---");
                break;
        }
    }
}