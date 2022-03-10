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
struct List *reverse(struct List *l)
{
    struct List *ptr = (struct List *)malloc(sizeof(ptr));
    struct List *pptr = (struct List *)malloc(sizeof(ptr));
    ptr = l->next;
    pptr = l;
    l->next = NULL;
    int *t;
    while (ptr != NULL)
    {
        t = ptr->next;
        ptr->next = pptr;
        pptr = ptr;
        ptr = t;
    }
    return pptr;
}
struct List print_ll(struct List *l)
{
    while (l != NULL)
    {
        printf("%d ", l->data);
        l = l->next;
    }
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
    print_ll(LL);
    LL = reverse(LL);
    print_ll(LL);
}