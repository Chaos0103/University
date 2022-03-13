#include <stdio.h>

void part(int n);

int main() {
    int n;
    scanf("%d", &n);

    part(n);
}

void part(int n) {
    if (n == 0) return;
    int num = n % 10;
    n /= 10;
    printf("%d\n", num);
    part(n);
}