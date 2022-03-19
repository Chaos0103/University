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
Node *Union(Node *A, Node *B);
Node *intersect(Node *A, Node *B);

int main() {
    int n, elem;
    Node *UHead, *IHead;

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

    UHead = Union(setA, setB);
    IHead = intersect(setA, setB);

    UHead = UHead->next;
    if (UHead == NULL) {
        printf(" 0");
    } else {
        while (UHead != NULL) {
            printf(" %d", UHead->elem);
            UHead = UHead->next;
        }
    }
    printf("\n");
    IHead = IHead->next;
    if (IHead == NULL) {
        printf(" 0");
    } else {
        while (IHead != NULL) {
            printf(" %d", IHead->elem);
            IHead = IHead->next;
        }
    }
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
Node *Union(Node *A, Node *B) {
    Node *curA = A->next, *curB = B->next;
    Node *unionHead = (Node *) malloc(sizeof(Node));
    unionHead->next = NULL;
    cur = unionHead;
    while (curA != NULL && curB != NULL) {
        if (curA->elem < curB->elem) {
            append(curA->elem);
            curA = curA->next;
        } else if (curA->elem > curB->elem){
            append(curB->elem);
            curB = curB->next;
        } else {
            append(curA->elem);
            curA = curA->next;
            curB = curB->next;
        }
    }
    while (curA != NULL) {
        append(curA->elem);
        curA = curA->next;
    }
    while (curB != NULL) {
        append(curB->elem);
        curB = curB->next;
    }

    return unionHead;
}
Node *intersect(Node *A, Node *B) {
    Node *curA = A->next, *curB = B->next;
    Node *intersectHead = (Node *) malloc(sizeof(Node));
    intersectHead->next = NULL;
    cur = intersectHead;
    while (curA != NULL && curB != NULL) {
        if (curA->elem > curB->elem) {
            curB = curB->next;
        } else if (curA->elem < curB->elem) {
            curA = curA->next;
        } else {
            append(curA->elem);
            curA = curA->next;
            curB = curB->next;
        }
    }
    return intersectHead;
}
