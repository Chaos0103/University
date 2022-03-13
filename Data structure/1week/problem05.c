#include <stdio.h>

struct time {
    int hour, min, sec;
};

int main() {
    struct time first, second;

    scanf("%d %d %d", &first.hour, &first.min, &first.sec);
    scanf("%d %d %d", &second.hour, &second.min, &second.sec);

    int hour = second.hour - first.hour;
    int min = second.min - first.min;
    if (min < 0) {
        hour--;
        min += 60;
    }
    int sec = second.sec - first.sec;
    if (sec < 0) {
        min--;
        sec += 60;
    }
    printf("%d %d %d\n", hour, min, sec);
}
