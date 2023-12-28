#include "ancestry.h"

#include <stdlib.h>
#include <string.h>
#include <time.h> //Device time

struct person *top = NULL;

void addPerson(char firstName[25], char surName[25], void *father, void *mother) {


    struct person *temp = (struct person *) malloc(sizeof(struct person));
    strcpy(temp->firstName, firstName);
    strcpy(temp->surName, surName);
    strcpy(temp->surName, surName);

    temp->father = father;
    temp->mother = mother;

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
    struct person *next = top->next;
    while (1) {
        if (next == NULL)
            return size;
        else {
            size++;
            next = next->next;
        }
    }
}

void *findPersonByName(char firstName[25], char surName[25]) {
    if (top == NULL)
        return NULL;

    int sizeOfList = getSize();

    struct person *temp = top;
    for (int i = 0; i <= sizeOfList; i++) {
        if (temp == NULL)
            return NULL;

        if (!strcmp(temp->firstName, firstName) && !strcmp(temp->surName, surName))
            return temp;
        else
            temp = temp->next;
    }
    return NULL;
}

void *getPersonByIndex(int index) {
    if (top == NULL)
        return NULL;

    struct person *temp = top;
    for (int i = 0; i <= index; i++) {
        if (temp == NULL) {
            return NULL;
        } else if (i == index) {
            return temp;
        } else {
            temp = temp->next;
        }
    }
    return NULL;
}