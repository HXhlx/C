#include <stdio.h>
#include <stdlib.h>
#include "set.h"

struct set *create(int flag) {
    char ch[2] = {'A', 'B'};
    printf("(按0退出)%c=", ch[flag - 1]);
    struct set *S = create_set();
    printf("创建成功,%c=", ch[flag - 1]);
    print(S->next);
    return S;
}

int main() {
    struct set *A = NULL, *B = NULL, *C = NULL, *D = NULL, *E = NULL;
    int change = 1;
    do {
        switch (change) {
            case 1:
                if (C) { free_set(C); C = NULL; }
                if (D) { free_set(D); D = NULL; }
                if (E) { free_set(E); E = NULL; }
                if (A) { free_set(A); A = NULL; }
                if (B) { free_set(B); B = NULL; }
                A = create(1);
                B = create(2);
                break;
            case 2:
                if (C) { free_set(C); C = NULL; }
                C = intersection(A, B);
                printf("C=");
                print(C->next);
                break;
            case 3:
                if (D) { free_set(D); D = NULL; }
                D = union_set(A, B);
                printf("D=");
                print(D->next);
                break;
            case 4:
                if (E) { free_set(E); E = NULL; }
                E = difference_set(A, B);
                printf("E=");
                print(E->next);
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
    free_set(A);
    free_set(B);
    free_set(C);
    free_set(D);
    free_set(E);
    return 0;
}
