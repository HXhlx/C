struct set {
    int data;
    struct set *next;
};

int IN_SET(struct set *, int);

int INSERT_SET(struct set *, int);

void print(struct set *);

struct set *create_set();

struct set *difference_set(struct set *A, struct set *B);

struct set *intersection(struct set *A, struct set *B);

struct set *union_set(struct set *A, struct set *B);