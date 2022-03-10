#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
}List;
List *input()
{
    List *t = (List*)malloc(sizeof(t));
    printf("Enter a number\n");
    scanf("%d",&t->data);
    t->next = NULL;
    return t;
}
List *create(int n)
{
    List *head = input();
    List *t = head;
    for(int i = 1;i<n;i++)
    {
        t->next = input();
        t = t->next;
    }
    t->next = head;
    return head;
}
List display(List *head)
{
    int c = 0;
    List *t = head;
    while(c != 1)
    { 
      printf("%d ",t->data);
      t = t->next;
      if(t->data == head->data)
      c++;
    }
}
int main()
{
    List *head = create(5);
    display(head);
}