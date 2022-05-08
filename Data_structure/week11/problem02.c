#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _deque {
    int elem;
    struct _deque *prev;
    struct _deque *next;
} Deque;
Deque *front, *rear;

void init();
void addFront(int elem);
void addRear(int elem);
int deleteFront();
int deleteRear();
void Print();
int underflow();
int number(char *p);

int main() {

    int n, num;
    char cmd[10];
    
    scanf("%d", &n);
    getchar();
    init();
    
    for (int i = 0; i < n; i++) {
        gets(cmd);
        if (strncmp(cmd, "AF", 2) == 0) {
            num = number(cmd);
            addFront(num);
        } else if (strncmp(cmd, "AR", 2) == 0) {
            num = number(cmd);
            addRear(num);
        } else if (strncmp(cmd, "DF", 2) == 0) {
            if (underflow()) {
                return 0;
            }
            deleteFront();
        } else if (strncmp(cmd, "DR", 2) == 0) {
            if (underflow()) {
                return 0;
            }
            deleteRear();
        } else {
            Print();
        }
    }


    return 0;
}

void init() {
    front = (Deque *) malloc(sizeof(Deque));
    rear = (Deque *) malloc(sizeof(Deque));
    front->next = rear;
    rear->prev = front;
}
void addFront(int elem) {
    Deque *newData = (Deque *) malloc(sizeof(Deque));
    newData->elem = elem;
    newData->prev = front;
    newData->next = front->next;
    front->next->prev =newData;
    front->next = newData;
}
void addRear(int elem) {
    Deque *newData = (Deque *) malloc(sizeof(Deque));
    newData->elem = elem;
    newData->next = rear;
    newData->prev = rear->prev;
    rear->prev->next = newData;
    rear->prev = newData;

}
int deleteFront() {
    Deque *temp = front->next;
    int elem = temp->elem;

    front->next = temp->next;
    temp->next->prev = front;
    
    free(temp);
    return elem;
} 
int deleteRear() {
    Deque *temp = rear->prev;
    int elem = temp->elem;

    rear->prev = temp->prev;
    temp->prev->next = rear;
    
    free(temp);
    return elem;
}
void Print() {
    Deque *p;
    for (p = front->next; p != rear; p = p->next) {
        printf(" %d", p->elem);
    }
    printf("\n");
}
int underflow() {
    if (front->next == rear) {
        printf("underflow\n");
        return 1;
    } 
    return 0;
}
int number(char *p) {
    int result = 0;
    for (char *i = p + 3; *i != 0; i++) {
        result *= 10;
        result += *i - '0';
    }
    return result;
}
