#include <stdio.h>

int mostOnes(int bitArr[100][100], int n);

int main() {
    int n;
    int arr[100][100];

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    printf("%d\n", mostOnes(arr, n));
}

int mostOnes(int bitArr[100][100], int n) {
    int idx = 0;
    int result = 0;
    for (int i = 0; i < n; i++) {
        int j;
        for (j = idx; j < n; j++) {
            if (bitArr[i][j] == 0) {
                if (idx != j) {
                    result = i;
                }
                idx = j;
                break;
            }
        }
        if (i != n - 1 && j == n) {
            return i;
        }
    }
    return result;
}
