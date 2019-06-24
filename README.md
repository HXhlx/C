#集合运算
##描述
设有两个用单链表表示的集合A, B, 其元素类型是int且以非递减方式存储, 其头结点分别为a, b。要求下面各问题中的结果集合同样以非递减方式存储, 结果集合不影响原集合。
##要求
    1.编写集合元素测试函数IN_SET, 如果元素已经在集合中返回0, 否则返回1;
```
int IN_SET(struct set *S, int data) {
    for (struct set *p = S->next; p; p = p->next)
        if (p->data == data)
            return 0;
    return 1;
}
```
    2.编写集合元素输入并插入到单链表中的函数INSERT_SET, 保证所输入的集合中的元素是唯一且以非递减方式存储在单链表中;
```
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
        for (p = S->next; p->next; p = p->next) {
            if (p->data == data)
                return 0;
            if (p->next->data > data)
                break;
        }
        q->next = p->next;
        p->next = q;
    }
    return 1;
}
```
    3.编写集合元素输出函数, 对建立的集合链表按非递增方式输出;
```
void print(struct set *S) {
    if (S && S->next)
        print(S->next);
    if (S)
        printf("%d ", S->data);
}
```
    4.编写求集合A, B的交C=A∩B的函数, 并输出集合C的元素;
```
struct set *intersection(struct set *A, struct set *B) {
    struct set *Si = (struct set *) malloc(sizeof(struct set));
    Si->next = NULL;
    for (struct set *p = A->next; p; p = p->next)
        if (!IN_SET(B, p->data))
            INSERT_SET(Si, p->data);
    return Si;
}
```
    5.编写求集合A, B的并D=AUB的函数, 并输出集合D的元素;
```
struct set *union_set(struct set *A, struct set *B) {
    struct set *Su = (struct set *) malloc(sizeof(struct set)), *Si = intersection(A, B), *Sd = difference_set(A, B);
    Su->next = NULL;
    for (struct set *p = Si->next; p; p = p->next)
        INSERT_SET(Su, p->data);
    for (struct set *p = Sd->next; p; p = p->next)
        INSERT_SET(Su, p->data);
    return Su;
}
```
    6.编写求集合A与B的对称差E=(A-B)U(B-A)的函数, 并输出集合E的元素;
```
struct set *difference_set(struct set *A, struct set *B) {
    struct set *Sd = (struct set *) malloc(sizeof(struct set));
    Sd->next = NULL;
    for (struct set *p = A->next; p; p = p->next)
        if (IN_SET(B, p->data))
            INSERT_SET(Sd, p->data);
    for (struct set *p = B->next; p; p = p->next)
        if (IN_SET(A, p->data))
            INSERT_SET(Sd, p->data);
    return Sd;
}
```
    7.设计一个菜单, 具有输入元素、求集合A, B的交C、求集合A, B的并D、求集合A与B的对称差E、退出等基本的功能。
```
printf("------------请选择功能-------------\n"
       "1.新建集合元素  2.求集合A,B的交\n"
       "3.求集合A,B的并 4.求集合A,B的对称差\n"
       "q.退出\n");
```