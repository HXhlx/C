#include <stdio.h>
#include "set.h"
void create(struct set *S, int flag)
{
    char ch[2] = {'A', 'B'};
    printf("(按q退出)%c=", ch[flag - 1]);
    S = create_set();
    printf("创建成功,%c=", ch[flag - 1]);
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
            printf("新功能开发中,敬请期待!");
            break;
        }
        printf("------------请选择功能-------------\n"
               "1.新建集合元素  2.求集合A,B的交\n"
               "3.求集合A,B的并 4.求集合A,B的对称差\n"
               "q.退出\n");
    } while (scanf("%d", &change));
    return 0;
}