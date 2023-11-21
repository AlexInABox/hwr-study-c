#include <stdio.h>
#include <stdlib.h>

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
    push(5);
    push(4);
    printf("%d\n", get(3));
    return 0;
}