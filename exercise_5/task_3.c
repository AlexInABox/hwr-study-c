#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node *ptr;
};
struct node *top = NULL;
void push(int data) {
    struct node *temp = (struct node *) malloc(sizeof(struct node));
    temp->ptr = top; // (*temp).ptr = top;
    temp->data = data; // (*temp).data = data;
    top = temp;
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
int getTop(){
    if (isEmpty())
        return -1;
    return top->data;
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


    push(3);
    printf("%d\n", getTop());
    push(2);
    printf("%d\n", getTop());
    printf("%d\n", getSize());
    pop();
    printf("%d\n", getSize());
    pop();
    pop(); //fehler
    pop();
    printf("%d\n", getSize());
    pop();
    isEmpty();

    return 0;
}