#include <stdio.h>
#include <stdlib.h>
struct List
{
    int data;
    struct List *next;
} * first;
struct List *create_ll(int n, int *a)
{
    first = (struct List *)malloc(sizeof(first));
    struct List *last = (struct List *)malloc(sizeof(last));
    first->data = a[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {
        struct List *t = (struct List *)malloc(sizeof(t));
        t->data = a[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
    return first;
}
int arr_inp(int *a, int n)
{
    printf("Enter the numbers\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
}
struct List print_ll(struct List *l)
{
    //struct List *temp = (struct List*)malloc(sizeof(temp));
    while (l != NULL)
    {
        printf("%d ", l->data);
        l = l->next;
    }
}
struct List sum(struct List *l)
{
    int s = 0;
    while (l != NULL)
    {
        s = s + l->data;
        l = l->next;
    }
    printf("SUM : %d\n", s);
}
int main()
{
    int n;
    printf("Enter the size\n");
    scanf("%d", &n);
    int a[n];
    struct List *LL = (struct List*)malloc(sizeof(LL));
    arr_inp(a, n);
    LL = create_ll(n, a);
    sum(LL);
    print_ll(LL);
}