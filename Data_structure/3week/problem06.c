#include <stdio.h>

int gcd(int a, int b);

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    int result = gcd(a, b);
    printf("%d\n", result);
}

int gcd(int a, int b) {
    int first = a > b ? b : a;
    int second = a > b ? a : b;
    if (first == 0) {
        return second;
    }
    return gcd(first, second % first);
}