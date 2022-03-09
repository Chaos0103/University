#include <stdio.h>

void ABC(int arr[], int k);

int main() {
    int num[10];
    for (int i = 0; i < 10; i++) {
        scanf("%d", &num[i]);
    }
    for (int i = 0; i < 9; i++) {
        ABC(num, i);
    }
    for (int i = 0; i < 10; i++) {
        printf(" %d", num[i]);
    }
}

void ABC(int arr[], int k) {
    int max_idx = k, max_value = arr[k];
    for (int i = k + 1; i < 10; i++) {
        if (max_value < arr[i]) {
            max_value = arr[i];
            max_idx = i;
        }
    }
    int tmp = arr[k];
    arr[k] = arr[max_idx];
    arr[max_idx] = tmp;
}
