#include <stdio.h>

int main() {
    int n, m;
    int arr[100][100] = {0};
    scanf("%d %d", &n, &m);

    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    int dist = 0, num = 1, x = 0, y = -1;


    while (num <= n * m) {
        int nx = x + dx[dist];
        int ny = y + dy[dist];
        if (0 <= nx && nx < n && 0 <= ny && ny < m && arr[nx][ny] == 0) {
            arr[nx][ny] = num++;
            x = nx;
            y = ny;
            continue;
        }
        dist++;
        dist %= 4;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf(" %d", arr[i][j]);
        }
        printf("\n");
    }

}
