#include <stdio.h>
#include <limits.h>
#include <time.h>


struct veryBIG {
    int hugeNumber;
    long veryLongNumber;
    float veryFloatyNumber;
    long double veryLongDouble;
    unsigned long veryLongLong;
};

void dummyWhole(struct veryBIG huge){
    unsigned long importantValueNeeded = huge.veryLongLong;
}
void dummyPointer(struct veryBIG *huge){
    unsigned long importantValueNeeded = huge->veryLongLong;
}


int main() {

    clock_t begin_whole = clock();

    for (int i = 0; i <= 1000000000; i++){
        struct veryBIG newBigStruct;
        newBigStruct.hugeNumber = INT_MAX;
        newBigStruct.veryLongNumber = LONG_MAX;
        newBigStruct.veryFloatyNumber = 3.14159;
        newBigStruct.veryLongDouble = LONG_MAX;
        newBigStruct.veryLongLong = ULONG_MAX;

        dummyWhole(newBigStruct);
    }

    clock_t stop_whole = clock();
    double time_spent_for_whole = (double)(stop_whole - begin_whole) / CLOCKS_PER_SEC;

    clock_t begin_pointer = clock();


    for (int i = 0; i <= 1000000000; i++){
        struct veryBIG newBigStruct;
        newBigStruct.hugeNumber = INT_MAX;
        newBigStruct.veryLongNumber = LONG_MAX;
        newBigStruct.veryFloatyNumber = 3.14159;
        newBigStruct.veryLongDouble = LONG_MAX;
        newBigStruct.veryLongLong = ULONG_MAX;

        dummyPointer(&newBigStruct);
    }

    clock_t stop_pointer = clock();
    double time_spent_for_pointer = (double)(stop_pointer - begin_pointer) / CLOCKS_PER_SEC;

    printf("%s%f%s\n", "Time spent for whole: ", time_spent_for_whole, "s");
    printf("%s%f%s\n", "Time spent for pointer: ", time_spent_for_pointer, "s");

    return 0;
}