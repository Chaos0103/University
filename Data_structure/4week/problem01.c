#include <stdio.h>

void reverse(int *start, int *end);

int main() {
    int data[100];
    int n, t;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        int startIdx, endIdx;
        scanf("%d %d", &startIdx, &endIdx);
        reverse(data + startIdx, data + endIdx);
    }
    for (int j = 0; j < n; j++) {
        printf(" %d", data[j]);
    }
}

void reverse(int *start, int *end) {
    while (start <= end) {
        int tmp = *start;
        *start = *end;
        *end = tmp;
        start++;
        end--;
    }
}