#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int *num1 = malloc(sizeof(int) * n);
    int *num2 = malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &num1[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &num2[i]);
    }
    for (int i = 0; i < n; i++) {
        printf(" %d", num1[i] + num2[n - 1 - i]);
    }
    free(num1);
    free(num2);
}
