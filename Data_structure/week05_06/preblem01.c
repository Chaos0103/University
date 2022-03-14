#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char elem;
    struct node *prev;
    struct node *next;
} Node;
Node *head;
Node *tail;
int listSize = -1;

void init();
void add(int rank, char elem);
void delete(int rank);
char get(int rank);
void print();

int main() {
    init();
    int n, rank;
    char order, elem;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++) {
        scanf("%c", &order);
        getchar();
        if (order == 'A') {
            scanf("%d %c", &rank, &elem);
            getchar();
            if (rank > listSize + 1) {
                printf("invalid position\n");
                continue;
            }
            add(rank, elem);
        } else if (order == 'D') {
            scanf("%d", &rank);
            getchar();
            if (rank > listSize) {
                printf("invalid position\n");
                continue;
            }
            delete(rank);
        } else if (order == 'G') {
            scanf("%d", &rank);
            getchar();
            if (rank > listSize) {
                printf("invalid position\n");
                continue;
            }
            char ch = get(rank);
            printf("%c\n", ch);
        } else if (order == 'P') {
            print();
        }
    }
}

void init() {
    head = (Node *) malloc(sizeof(Node));
    tail = (Node *) malloc(sizeof(Node));
    head->next = tail;
    tail->prev = head;
    listSize = 0;
}
void add(int rank, char elem) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    Node *now = head;
    for (int i = 0; i < rank; i++) {
        now = now->next;
    }
    newNode->elem = elem;
    newNode->next = now;
    newNode->prev = now->prev;
    now->prev->next = newNode;
    now->prev = newNode;
    listSize++;
}
void delete(int rank) {
    Node *now = head;
    for (int i = 0; i < rank; i++) {
        now = now->next;
    }
    now->next->prev = now->prev;
    now->prev->next = now->next;
    free(now);
    listSize--;
}
char get(int rank) {
    Node *now = head;
    for (int i = 0; i < rank; i++) {
        now = now->next;
    }
    return now->elem;
}
void print() {
    Node *now = head;
    for (int i = 0; i < listSize; i++) {
        now = now->next;
        printf("%c", now->elem);
    }
    printf("\n");
}