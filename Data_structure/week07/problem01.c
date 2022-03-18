#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int elem;
    struct node *next;
} Node;
Node *setA;
Node *setB;
Node *cur;

void init();
void append(int elem);
int subset(Node *A, Node *B);

int main() {
    int n, elem;

    init();
    scanf("%d", &n);
    cur = setA;
    for (int i = 0; i < n; i++) {
        scanf("%d", &elem);
        append(elem);
    }

    scanf("%d", &n);
    cur = setB;
    for (int i = 0; i < n; i++) {
        scanf("%d", &elem);
        append(elem);
    }

    int result = subset(setA, setB);

    printf("%d\n", result);

}

void init() {
    setA = (Node *) malloc(sizeof(Node));
    setB = (Node *) malloc(sizeof(Node));
    setA->next = NULL;
    setB->next = NULL;
}
void append(int elem) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->elem = elem;
    cur->next = newNode;
    cur = newNode;
}
int subset(Node *A, Node *B) {
    Node *curA = A->next, *curB = B->next;
    while (curA != NULL && curB != NULL) {
        if (curA->elem == curB->elem) {
            curA = curA->next;
        }
        curB = curB->next;
    }
    if (curA == NULL) {
        return 0;
    } else {
        return curA->elem;
    }
}
