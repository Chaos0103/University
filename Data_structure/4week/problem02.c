#include <stdio.h>

int main() {
    int n, t;
    int data[100];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }
    scanf("%d", &t);
    int buffer = 0;
    for (int i = 0; i < t; i++) {
        int now;
        scanf("%d", &now);
        int tmp = data[now];
        data[now] = buffer;
        buffer = tmp;
    }
    for (int i = 0; i < n; i++) {
        printf(" %d", data[i]);
    }
}
