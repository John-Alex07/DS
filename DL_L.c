#include <stdio.h>
#include <malloc.h>
typedef struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
}List;
List *create(List *head,List *tail)
{
    printf("Enter 5 numbers\n");
    head = (List*)malloc(sizeof(head));
    head->prev = NULL;
    scanf("%d",&head->data);
    head->next = NULL;
    tail = (List*)malloc(sizeof(tail));
    tail = head;
    for(int i = 1;i<5;i++)
    {
       List *t = (List*)malloc(sizeof(t));
       t->prev = tail;
       scanf("%d",&t->data);
       tail->next = t;
       tail = tail->next;
       t->next = NULL;
    }
}
void display_head(List *h)
{
   List *t = h;
   while(t != NULL)
   {
       printf("%d ",t->data);
       t = t->next;
   }
}
void display_tail(List *t)
{
    List *tp =t;
    while(tp != NULL)
    {
        printf("%d",tp->data);
        tp = tp->prev;
    }

}
int main()
{
    List *L,*TL;
    create(L,TL);
    display_head(L);
    display_tail(TL);
}