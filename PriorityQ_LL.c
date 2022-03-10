#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    int priority;
    struct Node *next;
}Que;
Que *head,*tail,*trav;
Que* input()
{
        Que *t = (Que*)malloc(sizeof(Que));
        printf("Enter a number and its priority\n");
        scanf("%d%d",&t->data,&t->priority);
         t->next = NULL;
         return t;
}
Que* Node_Q(int n)
{
    head = input();   
    Que *t = head;
    for(int i = 2;i<=n;i++)
    {
      t->next = input();
      t = t->next;
    }
    tail = t;
    return head;
}
Que* prority()
{
    Que* t = head->next;
    Que* s;
    int p = trav->priority;
    trav = head;
    s = head;
    while(trav != NULL)
    {
        if(trav->next->priority < p)
        {
            p = trav->next->priority;
            s = trav;
        }
        trav = trav->next;
    }
    return s;
}
int push()
{
   tail->next = input();
   tail = tail->next;
}
int pop()
{
    Que* popped = prority();
  popped->next = popped->next->next;
  printf("DATA : %d Freed", popped->next->data);
  free(popped->next);
}
int display(Que* head)
{
    Que *t = head;
    while(t != NULL)
    {
        printf("DATA : %d  PRIORITY : %d\n",t->data,t->priority);
        t = t->next;
    }
}
int main()
{
    head = Node_Q(5);
    display(head);
    pop();
    display(head);
}