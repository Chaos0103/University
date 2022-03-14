#include<stdio.h>
#include <stdlib.h>

int prefixAverages1(int arr[], int n);
int prefixAverages2(int arr[], int n);

int main() {
    int n;
    scanf("%d", &n);

    int *arr = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", prefixAverages1(arr, i));
    }

    printf("\n");

    for (int i = 0; i < n; i++) {
        arr[i] = prefixAverages2(arr, i);
        double avg = (double) arr[i] / (i + 1);
        avg += 0.5;
        printf("%d ", (int)avg);
    }

    free(arr);
}

int prefixAverages1(int arr[], int n) {
    double sum = 0;
    for (int i = 0; i <= n; i++) {
        sum += arr[i];
    }
    sum /= (n + 1);
    sum += 0.5;
    return (int)sum;
}

int prefixAverages2(int arr[], int n) {
    if (n == 0) {
        return arr[0];
    }
    return arr[n - 1] + arr[n];
}
