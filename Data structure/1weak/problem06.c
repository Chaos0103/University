#include <stdio.h>

struct studentInfo {
    char studentName[10];
    int finalTestScore;
};

int main() {
    struct studentInfo data[5], *p;

    for (int i = 0; i < 5; i++) {
        scanf("%s %d", data[i].studentName, &data[i].finalTestScore);
        getchar();
    }
    int totalFinalTestScore = 0;
    for (p = data; p < data + 5; p++) {
        totalFinalTestScore += p->finalTestScore;
    }
    totalFinalTestScore /= 5;
    for (p = data; p < data + 5; p++) {
        if(p->finalTestScore <= totalFinalTestScore) {
            printf("%s\n", p->studentName);
        }
    }
}
