#include <stdio.h>
#define N 4

static struct man {
    int id;
    char name[20];
    int age;
};

struct man person[N] = {1,"li",18, 2,"wang",23, 3,"zhang",20, 4,"sun",22};

int main()
{
    struct man *q, *p;
    int i, m=0;
    p=person;
    for (i=0; i<N; i++)
        printf("%d: %s,%d\n", (person+i)->id, (*(person+i)).name, person[i].age);
    for (i=0; i<N; i++)
        if (m < p->age) { q = p++; m=q->age;}
    printf("Oldest: %d,%s,%d", q[0].id, q->name, (*q).age);
    return 0;
}
