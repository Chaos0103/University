#include <stdio.h>

void swap(int *a, int *b);

int main() {
    int n, a, b;
    int arr[50];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d %d", &a, &b);

    swap(&arr[a], &arr[b]);

    for (int i = 0; i < n; i++) {
        printf(" %d", arr[i]);
    }
}

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
