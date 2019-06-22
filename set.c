#include <stdio.h>
#include <stdlib.h>
#include "set.h"
int IN_SET(struct set S, int data)
{
    for (struct set *p = &S; p; p = p->next)
        if (p->data == data)
            return 0;
    return 1;
}
int INSERT_SET(struct set *S, int data)
{
    struct set *p, *q = (struct set *)malloc(sizeof(struct set));
    q->data = data;
    if (!S->next)
        S->next = q;
    else
    {
        for (p = S->next; p; p = p->next)
        {
            if (p->data == data)
                return 0;
            if (!p->next || p->next->data > data)
                break;
        }
        q->next = p->next;
        p->next = q;
    }
    return 1;
}
void sort(struct set *S)
{
    struct set *s, *p;
}
struct set *create_set()
{
    int data;
    struct set *S = (struct set *)malloc(sizeof(struct set));
    while (scanf("%d", &data))
        printf("%d", INSERT_SET(S, data));
    return S;
}
struct set *difference_set(struct set *A, struct set *B)
{
    struct set *Sd = (struct set *)malloc(sizeof(struct set));
    for (struct set *p = A; p; p = p->next)
        if (!IN_SET(*B, p->data))
            INSERT_SET(Sd, p->data);
    for (struct set *p = B; p; p = p->next)
        if (!IN_SET(*A, p->data))
            INSERT_SET(Sd, p->data);
    return Sd;
}
struct set *intersection(struct set *A, struct set *B)
{
    struct set *Si = (struct set *)malloc(sizeof(struct set));
    for (struct set *p = A; p; p = p->next)
        if (IN_SET(*B, p->data))
            INSERT_SET(Si, p->data);
    return Si;
}
struct set *union_set(struct set *A, struct set *B)
{
    struct set *Su = (struct set *)malloc(sizeof(struct set)), *Si = intersection(A, B), *Sd = difference_set(A, B);
    for (struct set *p = Si; p; p = p->next)
        INSERT_SET(Su, p->data);
    for (struct set *p = Sd; p; p = p->next)
        INSERT_SET(Su, p->data);
    return Su;
}
void print(struct set *S)
{
    if (S && S->next)
        print(S->next);
    printf("%d ", S->data);
}