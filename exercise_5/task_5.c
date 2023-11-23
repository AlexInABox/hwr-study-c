#include <stdio.h>
#include <stdlib.h>
#include <time.h> //Device time

struct node {
    void *data;
    struct node *ptr;
};

struct node *top = NULL;
void add(void *data) {

    struct node *temp = (struct node *) malloc(sizeof(struct node));
    temp->data = data;

    if (top == NULL) {
        temp->ptr = NULL;
        top = temp;
        return;
    }

    temp->ptr = top;
    top = temp;

}
int isEmpty(){
    return (top == NULL);
}
void *get(int index){
    if (top == NULL)
        return NULL;

    struct node *temp = top;
    for(int i = 0; i <= index; i++){
        if (temp == NULL){
            return NULL;
        }
        else if (i == index){
            return temp->data;
        } else {
            temp = temp->ptr;
        }
    }
    return NULL;
}
int getSize(){
    if (top == NULL)
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
int contains(void *element){
    if (top == NULL) {
        return -1;
    }

    struct node *temp = top;
    for(int i = 0; i <= getSize(); i++){
        if (temp == NULL){
            return -1;
        }
        else if (element == temp->data)
            return i;
        else
        temp = temp->ptr;
    }
    return -1;
}
void removeIndex(int index){
    if (top == NULL)
        return;

    struct node *temp = top->ptr;
    struct node *above = top;

    if (index == 0) {
        free(top);
        top = temp;
        return;
    }

    for(int i = 1; i <= index; i++){
        if (temp == NULL)
            return;
        else if (i == index){
            above->ptr = temp->ptr;
            free(temp);
            return;
        } else
            above = temp;
            temp = temp->ptr;
    }
}

int main(){
    int a = 15;
    int b = 14;
    int c = 13;

    add(&a);
    add(&b);
    add(&c);

    printf("%s%d\n","Index 2: ", *(int*)get(2));
    printf("%s%d\n","Index 1: ", *(int*)get(1));
    printf("%s%d\n\n","Index 0: ", *(int*)get(0));

    printf("%s%d\n\n", "getSize() = ", getSize());

    printf("%s\n\n", "Removing index 1...");

    removeIndex(1);

    printf("%s%d\n","Index 1: ", *(int*)get(1));
    printf("%s%d\n\n","Index 0: ", *(int*)get(0));

    printf("%s%d\n\n", "getSize() = ", getSize());


    printf("%s%d\n\n", "isEmpty() = ", isEmpty());

    printf("%s\n", "Removing index 0...");
    printf("%s\n\n", "Removing index 0...");

    removeIndex(0);
    removeIndex(0);

    printf("%s%d\n\n", "isEmpty() = ", isEmpty());

    printf("%s%d\n\n", "getSize() = ", getSize());

}