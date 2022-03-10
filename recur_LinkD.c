#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
}List;
List *l;
List *create(List *rL,int n)
{
    List *ptr = (List*)malloc(sizeof(ptr));
    if(n > 0)
    {

        List *t = (List*)malloc(sizeof(t));
        printf("Enter a number : ");
        scanf("%d",&t->data);
        t->next = NULL;
        create(t,n-1);
        rL = rL ->next;
    }
    else
    return l;
}
List print(List *ll)
{
    while(ll != NULL)
    {
        printf("%d",ll->data);
        ll = ll->next;
    }
}
int main()
{
   int n;
   l = (List*)malloc(sizeof(l));
   l->next = NULL;
   printf("Enter the length of the list : ");
   scanf("%d",&n);
   create(l,n);
   print(l);
}