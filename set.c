#include <stdio.h>
#include <stdlib.h>
#include "set.h"

int IN_SET(struct set *S, int data) {
    for (struct set *p = S->next; p; p = p->next)
        if (p->data == data)
            return 1;
    return 0;
}

int INSERT_SET(struct set *S, int data) {
    struct set *p, *q = (struct set *) malloc(sizeof(struct set));
    q->data = data;
    if (!S->next) {
        S->next = q;
        q->next = NULL;
    } else if (S->next->data > data) {
        q->next = S->next;
        S->next = q;
    } else {
        for (p = S->next; ; p = p->next) {
            if (p->data == data) {
                free(q);
                return 0;
            }
            if (!p->next || p->next->data > data)
                break;
        }
        q->next = p->next;
        p->next = q;
    }
    return 1;
}

struct set *create_set() {
    int data;
    struct set *S = (struct set *) malloc(sizeof(struct set));
    S->next = NULL;
    while (scanf("%d", &data) == 1)
        if (data)
            INSERT_SET(S, data);
        else {
            printf("是否退出输入?(y/n)");
            getchar();
            if (getchar() == 'y')
                break;
        }
    return S;
}

struct set *difference_set(struct set *A, struct set *B) {
    struct set *Sd = (struct set *) malloc(sizeof(struct set));
    Sd->next = NULL;
    for (struct set *p = A->next; p; p = p->next)
        if (!IN_SET(B, p->data))
            INSERT_SET(Sd, p->data);
    for (struct set *p = B->next; p; p = p->next)
        if (!IN_SET(A, p->data))
            INSERT_SET(Sd, p->data);
    return Sd;
}

struct set *intersection(struct set *A, struct set *B) {
    struct set *Si = (struct set *) malloc(sizeof(struct set));
    Si->next = NULL;
    for (struct set *p = A->next; p; p = p->next)
        if (IN_SET(B, p->data))
            INSERT_SET(Si, p->data);
    return Si;
}

struct set *union_set(struct set *A, struct set *B) {
    struct set *Su = (struct set *) malloc(sizeof(struct set));
    Su->next = NULL;
    for (struct set *p = A->next; p; p = p->next)
        INSERT_SET(Su, p->data);
    for (struct set *p = B->next; p; p = p->next)
        INSERT_SET(Su, p->data);
    return Su;
}

void print(struct set *S) {
    if (!S) return;
    if (S->next)
        print(S->next);
    printf("%d ", S->data);
}

void free_set(struct set *S) {
    while (S) {
        struct set *next = S->next;
        free(S);
        S = next;
    }
}
