#include <stdio.h>
#include <string.h>

int main() {
    char str[101];

    scanf("%s", str);

    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        printf("%s\n", str);
        char ch = str[0];
        for (int j = 1; j < len; j++) {
            str[j - 1] = str[j];
        }
        str[len - 1] = ch;
    }

}
