#include <stdio.h>
int stack[100];
int size = 0;

void push(int num);
int pop();
int calculation(int num1, int num2, char operation);
int charToInt(char num);
int isDigit(char ch);

int main() {
    
    int n;
    char str[100];

    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        getchar();

        for (char *p = str; *p != 0; p++) {
            if (isDigit(*p)) {
                push(charToInt(*p));
            } else {
                int num1 = pop();
                int num2 = pop();
                int result = calculation(num2, num1, *p);
                push(result);
            }
        }
        printf("%d\n", pop());
    }

    return 0;
}

void push(int num) {
    stack[size++] = num;
}
int pop() {
    return stack[--size];
}
int calculation(int num1, int num2, char operation) {
    switch (operation) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            return num1 / num2;
        default:
            return 0;
    }
}
int charToInt(char num) {
    return num - '0';
}
int isDigit(char ch) {
    if ('0' <= ch && ch <= '9') {
        return 1;
    }
    return 0;
}
