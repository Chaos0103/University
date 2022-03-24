#include <stdio.h>
#include <stdlib.h>

int q;
int *queue;
int front = 0, rear = 0;

void insert(int num);
void delete();
void Print();
int overflow();
int underflow();

int main() {
    int n, num;
    char ch;

    scanf("%d", &q);

    queue = (int *) malloc(sizeof(int) * q);
    for (int i = 0; i < q; i++) {
        queue[i] = 0;
    }
    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++) {
        scanf("%c", &ch);
        getchar();
        if (ch == 'I') {
            scanf("%d", &num);
            getchar();
            if (overflow()) {
                printf("overflow");
                Print();
                return 0;
            } else {
                insert(num);
            }
        } else if (ch == 'D') {
            if (underflow()) {
                printf("underflow\n");
                return 0;
            } else {
                delete();
            }
        } else if (ch == 'P') {
            Print();
        }
    }
    return 0;
}

void insert(int num) {
    rear++;
    if (rear >= q) {
        rear = 0;
    }
    queue[rear] = num;
}
void delete() {
    front++;
    if (front >= q) {
        front = 0;
    }
    queue[front] = 0;
}
void Print() {
    for (int i = 0; i < q; i++) {
        printf(" %d", queue[i]);
    }
    printf("\n");
}
int overflow() {
    if (front - 1 == rear || (front == 0 && rear == q - 1)) {
        return 1;
    }
    return 0;
}
int underflow() {
    if (front == rear) {
        return 1;
    }
    return 0;
}