#ifndef ANCESTRY_H
#define ANCESTRY_H
struct person {
    char firstName[25];
    char surName[25];

    struct person *father;
    struct person *mother;

    struct person *next;
};

void addPerson(char firstName[25], char surName[25], void *father, void *mother);

int getSize();

void *findPersonByName(char firstName[25], char surName[25]);

void *getPersonByIndex(int index);


#endif //ANCESTRY_H