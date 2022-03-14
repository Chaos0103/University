#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int coef;
    int exp;
    struct node *next;
} Node;

Node *head1;
Node *head2;
Node *result;
Node *cur;

void init();
Node *append(Node *tail, int coef, int exp);
void add();

int main() {
    init();

    int n;
    int coef, exp;
    scanf("%d", &n);
    cur = head1;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coef, &exp);
        cur = append(cur, coef, exp);
    }

    scanf("%d", &n);
    cur = head2;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coef, &exp);
        cur = append(cur, coef, exp);
    }

    add();

    cur = result->next;
    while (cur != NULL) {
        if (cur->coef != 0) {
            printf(" %d %d", cur->coef, cur->exp);
        }
        cur = cur->next;
    }

}

void init() {
    head1 = (Node *) malloc(sizeof(Node));
    head2 = (Node *) malloc(sizeof(Node));
    head1->next = NULL;
    head2->next = NULL;
}

Node *append(Node *tail, int coef, int exp) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->coef = coef;
    newNode->exp = exp;
    newNode->next = NULL;
    tail->next = newNode;
    tail = newNode;
    return tail;
}

void add() {
    result = (Node *) malloc(sizeof(Node));
    result->next = NULL;
    Node *x = head1->next;
    Node *y = head2->next;
    cur = result;
    while (x != NULL && y != NULL) {
        if (x->exp > y->exp) {
            cur = append(cur, x->coef, x->exp);
            x = x->next;
        } else if (x->exp < y->exp) {
            cur = append(cur, y->coef, y->exp);
            y = y->next;
        } else {
            cur = append(cur, x->coef + y->coef, x->exp);
            x = x->next;
            y = y->next;
        }
    }
    while (x != NULL) {
        cur = append(cur, x->coef, x->exp);
        x = x->next;
    }
    while (y != NULL) {
        cur = append(cur, y->coef, y->exp);
        y = y->next;
    }
}