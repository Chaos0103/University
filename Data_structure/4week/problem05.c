#include <stdio.h>

int main() {
    int n, m;
    int arr[100][100];

    scanf("%d %d", &n, &m);

    int num = 1;

    for (int i = 0; i < m; i++) {
        int x = 0, y = i;
        while (1) {
            if (!(0 <= x && x < n && 0 <= y && y < m)) {
                break;
            }
            arr[x][y] = num++;
            x++;
            y--;
        }
    }
    for (int i = 1; i < n; i++) {
        int x = i, y = m - 1;
        while (1) {
            if (!(0 <= x && x < n && 0 <= y && y < m)) {
                break;
            }
            arr[x][y] = num++;
            x++;
            y--;
        }
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf(" %d", arr[i][j]);
        }
        printf("\n");
    }

}
