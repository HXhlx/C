#include <stdio.h>
#include <malloc.h>
#include "set.h"

struct set *create(int flag) {
    char ch[2] = {'A', 'B'};
    printf("(��0�˳�)%c=", ch[flag - 1]);
    struct set *S = create_set();
    printf("�����ɹ�,%c=", ch[flag - 1]);
    print(S->next);
    putchar('\n');
    return S;
}

int main() {
    char ch;
    int data, flag;
    struct set *A, *B, *C, *D, *E, a, b;
    unsigned change = 1;
    do {
        switch (change) {
            case 1:
                A = create(1);
                B = create(2);
                break;
            case 2:
                C = intersection(A, B);
                printf("C=");
                print(C->next);
                putchar('\n');
                break;
            case 3:
                D = union_set(A, B);
                printf("D=");
                print(D->next);
                putchar('\n');
                break;
            case 4:
                E = difference_set(A, B);
                printf("E=");
                print(E->next);
                putchar('\n');
                break;
            default:
                printf("�¹��ܿ�����,�����ڴ�!");
                break;
        }
        printf("------------��ѡ����-------------\n"
               "1.�½�����Ԫ��  2.�󼯺�A,B�Ľ�\n"
               "3.�󼯺�A,B�Ĳ� 4.�󼯺�A,B�ĶԳƲ�\n"
               "q.�˳�\n");
    } while (scanf("%d", &change));
    return 0;
}