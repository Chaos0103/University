#include <stdio.h>

int targetCount(char target, char *ch);

int main() {
    char str[101];
    char target;
    scanf("%s", str);
    getchar();
    scanf("%c", &target);

    int result = targetCount(target, str);
    printf("%d\n", result);
}

int targetCount(char target, char *ch) {
    if (*ch == 0) {
        return 0;
    }
    if (*ch == target) {
        return 1 + targetCount(target, ch + 1);
    } else {
        return targetCount(target, ch + 1);
    }
}