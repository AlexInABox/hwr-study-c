#ifndef CLASSBOOK_H
#define CLASSBOOK_H
struct student {
    char firstName[25];
    char surName[25];

    double gradeMaths;
    double gradeGerman;
    double gradeEnglish;

    struct student *next;
};

int getSize();

void addStudent(char firstName[25], char surName[25]);

void *getStudentByIndex(int index);

double getAverageGrade();


#endif //CLASSBOOK_H