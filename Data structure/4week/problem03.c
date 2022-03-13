#include <stdio.h>

int main() {
    int n, num;
    int arr[100][100];
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            num = i * n + 1;
            for (int j = 0; j < n; j++) {
                arr[i][j] = num++;
            }
        } else {
            num = (i + 1) * n;
            for (int j = 0; j < n; j++) {
                arr[i][j] = num--;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf(" %d", arr[i][j]);
        }
        printf("\n");
    }
}
