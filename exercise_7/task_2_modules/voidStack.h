#ifndef VOIDSTACK_H
#define VOIDSTACK_H
void add(void *data);
int isEmpty();
void *get(int index);
int getSize();
int contains(void *element);
void removeIndex(int index);

#endif //VOIDSTACK_H