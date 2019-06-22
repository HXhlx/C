#include <stdio.h>
#include "set.h"
void create(struct set *S, int flag)
{
    char ch[2] = {'A', 'B'};
    printf("(��q�˳�)%c=", ch[flag - 1]);
    S = create_set();
    printf("�����ɹ�,%c=", ch[flag - 1]);
    print(S);
    putchar('\n');
}
int main()
{
    char ch;
    int data, flag;
    struct set *A, *B, *C, *D, *E;
    unsigned change = 1;
    do
    {
        switch (change)
        {
        case 1:
            create(A, 1);
            create(B, 2);
            break;
        case 2:
            C = intersection(A, B);
            print(C);
            break;
        case 3:
            D = union_set(A, B);
            print(D);
            break;
        case 4:
            E = difference_set(A, B);
            print(E);
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