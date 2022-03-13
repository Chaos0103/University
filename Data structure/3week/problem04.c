#include <stdio.h>

int max(int a, int b);
int maxValue(int arr[], int n);

int main() {
    int n;
    int data[20];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }

    int result = maxValue(data, n);
    printf("%d\n", result);
}

int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}
int maxValue(int arr[], int n) {
    if(n==1) {
        return arr[0];
    } else {
        return max(arr[n - 1], maxValue(arr, n - 1));
    }
}