#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *stack;
int stackSize;
int topPos;

void push(char elem);
char pop();
void peek();
void duplicate();
void upRotate(int n);
void downRotate(int n);
void print();

int fullCheck();
int emptyCheck();


int main() {
    int n, on;
    char order[10], ch;
    scanf("%d", &stackSize);
    stack = (char *) malloc(sizeof(char) * stackSize);
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++) {
        gets(order);
        if (strncmp(order, "POP", 3) == 0) {
            if(emptyCheck()) {
                ch = pop();
            }
        } else if (strncmp(order, "PUSH", 4) == 0) {
            if (fullCheck()) {
                push(order[5]);
            }
        } else if (strncmp(order, "PEEK", 4) == 0) {
            if (emptyCheck()) {
                peek();
            }
        } else if (strncmp(order, "DUP", 3) == 0) {
            if (fullCheck()) {
                duplicate();
            }
        } else if (strncmp(order, "UpR", 3) == 0) {
            on = order[4] - '0';
            if (topPos >= on) {
                upRotate(on);
            }
        } else if (strncmp(order, "DownR", 5) == 0) {
            on = order[6] - '0';
            if (topPos >= on) {
                downRotate(on);
            }
        } else if (strncmp(order, "PRINT", 5) == 0) {
            print();
        }
    }
}

void push(char elem) {
    stack[topPos++] = elem;
}
char pop() {
    char ch = stack[--topPos];
    return ch;
}
void peek() {
    printf("%c\n", stack[topPos - 1]);
}
void duplicate() {
    char ch = pop();
    push(ch);
    push(ch);
}
void upRotate(int n) {
    char ch = stack[topPos - 1];
    for (int i = 1; i < n; i++) {
        stack[topPos - i] = stack[topPos - i - 1];
    }
    stack[topPos - n] = ch;
 }
void downRotate(int n) {
    char ch = stack[topPos - n];
    for (int i = topPos - n; i < topPos; i++) {
        stack[i] = stack[i + 1];
    }
    stack[topPos - 1] = ch;
}
void print() {
    for (int i = topPos - 1; i >= 0; i--) {
        printf("%c", stack[i]);
    }
    printf("\n");
}

int fullCheck() {
    if (topPos == stackSize) {
        printf("Stack FULL\n");
        return 0;
    }
    return 1;
}
int emptyCheck() {
    if (topPos == 0) {
        printf("Stack Empty\n");
        return 0;
    }
    return 1;
}
