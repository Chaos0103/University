#include <stdio.h>
#include <stdlib.h>

struct studentInfo {
    char studentName[8];
    int korScore, engScore, mathScore;
    double avgScore;
};

int main() {
    int n;
    scanf("%d", &n);

    struct studentInfo *data = malloc(sizeof(struct studentInfo) * n);
    struct studentInfo *p;

    for (p = data; p < data + n; p++) {
        scanf("%s %d %d %d", p->studentName, &p->korScore, &p->engScore, &p->mathScore);
        getchar();
        p->avgScore = (p->korScore + p->engScore + p->mathScore) / 3.0;
    }

    for (p = data; p < data + n; p++) {
        printf("%s %.1lf", p->studentName, p->avgScore);
        if (p->korScore >= 90 || p->engScore >= 90 || p->mathScore >= 90) {
            printf(" GREAT");
        }
        if (p->korScore < 70 || p->engScore < 70 || p->mathScore < 70) {
            printf(" BAD");
        }
        printf("\n");
    }

    free(data);
}
