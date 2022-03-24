#include <stdio.h>
#include <string.h>
#define STACK_SIZE 1000;

char stack[1000];
int topPos;

void push(char elem);
char pop();

int main() {
    char str[1000];
    char *p, ch;
    int result = 1;
    int cnt = 0;
    gets(str);

    for (p = str; p < str + strlen(str); p++) {
        if (*p == '(' || *p == '{' || *p == '[') {
            push(*p);
            cnt++;
        } else if (*p == ')') {
            if (pop() != '(') {
                result = 0;
            }
            cnt++;
        } else if (*p == '}') {
            if (pop() != '{') {
                result = 0;
            }
            cnt++;
        } else if (*p == ']') {
            if (pop() != '[') {
                result = 0;
            }
            cnt++;
        }
    }

    if (result == 1 && topPos == 0) {
        printf("OK_%d\n", cnt);
    } else {
        printf("Wrong_%d\n", cnt);
    }
}

void push(char elem) {
    stack[topPos++] = elem;
}
char pop() {
    char ch = stack[--topPos];
    return ch;
}
