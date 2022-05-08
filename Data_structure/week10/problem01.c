#include <stdio.h>

char stack[100];
int size = 0;

void push(char ch);
char pop();
char top();
int isEmpty();

int isAlpha(char ch);
int priority(char operation);

int main() {

    int n;
    char str[101], ch;

    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        getchar();

        for (char *p = str; *p != 0; p++) {
            if (isAlpha(*p)) {
                printf("%c", *p);
            } else if (*p == '(') {
                push(*p);
            } else if (*p == ')') {
                while (top() != '(') {
                    ch = pop();
                    if (ch == 'p') ch = '+';
                    else if (ch == 'm') ch = '-';
                    printf("%c", ch);
                }
                pop();
            } else {
                if (*p == '+' && !isAlpha(*(p - 1)) && isAlpha(*(p + 1)) && *(p-1) != ')') {
                    *p = 'p';
                } else if (*p == '-' && !isAlpha(*(p - 1)) && isAlpha(*(p + 1)) && *(p-1) != ')') {
                    *p = 'm';
                }
                while (!isEmpty() && (priority(*p) <= priority(top()))) {
                    ch = pop();
                    if (ch == 'p') ch = '+';
                    else if (ch == 'm') ch = '-';
                    printf("%c", ch);
                }
                if (*p == '&' || *p == '|') {
                    push(*p);
                    p++;
                }
                push(*p);
            }
        }
        while (!isEmpty()) {
            ch = pop();
            if (ch == 'p') ch = '+';
            else if (ch == 'm') ch = '-';
            printf("%c", ch);
        }
    }

    return 0;
}

void push(char ch) {
    stack[size++] = ch;
}
char pop() {
    return stack[--size];
}
char top() {
    return stack[size - 1];
}
int isEmpty() {
    if (size == 0) {
        return 1;
    }
    return 0;
}

int isAlpha(char ch) {
    if ('A' <= ch && ch <= 'Z') {
        return 1;
    }
    return 0;
}
int priority(char operation) {
    switch (operation) {
        case '(':
            return 0;
        case '|':
            return 1;
        case '&':
            return 2;
        case '<':
        case '>':
            return 3;
        case '+':
        case '-':
            return 4;
        case '*':
        case '/':
            return 5;
        case '!':
        case 'p':
        case 'm':
            return 6;
    }
}
