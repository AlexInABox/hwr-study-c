#include <stdio.h>
#include <stdlib.h>
#include <time.h> //Device time

struct node {
    int data;
    struct node *ptr;
};
struct node *top = NULL;
void push(int data) {

    struct node *temp = (struct node *) malloc(sizeof(struct node));
    temp->data = data; // (*temp).data = data;

    if (top == NULL) {
        temp->ptr = NULL;
        top = temp;
        return;
    }

    if (data >= top->data){
        temp->ptr = top; // (*temp).ptr = top;
        top = temp;
        return;
    }

    struct node *above = top;
    struct node *next = top->ptr;


    while(1){

        if (next == NULL){
            temp->ptr = NULL;
            above->ptr = temp;
            return;
        }

        if (data >= next->data){ //JACKPOT platzieren!
            temp->ptr = next;
            above->ptr = temp;
            return;
        }
        else{ //never give up
            above = next;
            next = next->ptr;
        }
    }
}
int isEmpty(){
    return (top == NULL);
}
void pop(){
    if (isEmpty())
        return;

    struct node *temp = top->ptr;
    free(top);
    top = temp;
}
int get(int a){
    if (isEmpty())
        return 0;

    struct node *temp = top;
    for(int i = 0; i <= a; i++){
        if (temp == NULL){
            return -1;
        }
        else if (i == a){
            return temp->data;
        } else {
            temp = temp->ptr;
        }
    }
}
int getSize(){
    if (isEmpty())
        return 0;

    int size = 1;
    struct node *next = top->ptr;
    while(1){
        if (next == NULL)
            return size;
        else {
            size++;
            next = next->ptr;
        }
    }
}






int main(){

    printf("%s\n\n", "Hi welcome to my sorted stack <3");
    printf("%s\n", "Press 1 to push().");
    printf("%s\n", "Press 2 to pop().");
    printf("%s\n", "Press 3 to getSize().");
    printf("%s\n", "Press 4 to get() a specific index.");
    printf("%s\n", "Press 5 to QUIT.");
    printf("%s\n\n", "Press 6 to RANDOM PARTY.");

    int userStaysInLoop = 1;
    int userInputOption = 5;
    int userInputValue = 0;

    while (userStaysInLoop){

        scanf("%d", &userInputOption);

        switch (userInputOption) {

            case 1:
                printf("%s\n", "Value: ");
                scanf("%d", &userInputValue);

                push(userInputValue);

                printf("%s%d\n", "Successfully pushed ", userInputValue);
                break;
            case 2:
                pop();
                printf("%s\n", "Popped >.<");
                break;
            case 3:
                printf("%s%d\n", "Size of stack: ", getSize());
                break;
            case 4:
                printf("%s\n", "Index: ");
                scanf("%d", &userInputValue);

                printf("%s%d%s%d\n", "get(", userInputValue, ") = ", get(userInputValue));
                break;
            case 5:
                printf("%s\n", "Bye bye <3");
                userStaysInLoop = 0;
                break;
            case 6:
                printf("%s\n", "Currently filling the stack with 1000 random values.");

                int randomNumber;
                srand(time(NULL));
                for (int i = 0; i < 1000; i++){
                    randomNumber = rand() % 5000;

                    push(randomNumber);
                }

                printf("[");
                for (int i = 0; i < getSize(); i++){
                    printf("%d%-1s", get(i), ", ");
                }
                printf("]");
                break;
            default:
                userStaysInLoop = 0;
                break;
        }
    }

    return 0;
}