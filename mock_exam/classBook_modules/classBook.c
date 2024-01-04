#include "classBook.h"

#include <stdlib.h>
#include <string.h>

struct student *top = NULL;

void addStudent(char firstName[25], char surName[25]) {

    struct student *temp = (struct student *) malloc(sizeof(struct student));
    strcpy(temp->firstName, firstName);
    strcpy(temp->surName, surName);


    if (top == NULL) {
        temp->next = NULL;
        top = temp;
        return;
    }
    temp->next = top;
    top = temp;
}

int isEmpty() {
    return (top == NULL);
}

int getSize() {
    if (top == NULL)
        return 0;

    int size = 1;
    struct student *next = top->next;
    while (1) {
        if (next == NULL)
            return size;
        else {
            size++;
            next = next->next;
        }
    }
}

void *getStudentByIndex(int index) {
    struct student *temp = top;
    for (int i = 0; i < index; i++) {
        if (temp == NULL)
            return NULL;

        temp = temp->next;
    }
    return temp;
}

double getAverageGrade() {
    /* Ich interpretiere die Aufgabenstellung so, dass der
     * Gesamtnotendurchschnitt aller Fächer zusammen
     * errechnet werden soll.
     *
     * Eine eventuelle alternative Lösung wäre die
     * Berechnung des Notendurchschnittes der einzelnen Fächer.
     */

    double sumOfGrades = 0.0;
    int sumOfValidGrades = 0;
    int sizeOfClassBook = getSize();

    for (int i = 0; i < sizeOfClassBook; i++) {
        struct student *temp = getStudentByIndex(i);

        if (temp->gradeMaths != 0.0) {
            sumOfGrades += temp->gradeMaths;
            sumOfValidGrades++;
        }

        if (temp->gradeGerman != 0.0) {
            sumOfGrades += temp->gradeGerman;
            sumOfValidGrades++;
        }

        if (temp->gradeEnglish != 0.0) {
            sumOfGrades += temp->gradeEnglish;
            sumOfValidGrades++;
        }

    }

    return sumOfGrades / sumOfValidGrades;
}