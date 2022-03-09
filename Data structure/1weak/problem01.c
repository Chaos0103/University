#include <stdio.h>

int sum(int n);

int main() {
    int n;
    scanf("%d", &n);

    int result = 0;
    for (int i = 1; i <= n; i++) {
        result += sum(i);
    }
    printf("%d\n", result);
    return 0;
}

int sum(int n) {
    int result = 0;
    for (int i = 1; i <= n; i++) {
        result += i;
    }
    return result;
}
