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
    return t;
}
List *create()
{
    List *last = input();
    List *temp = last;
    last->next = temp;
    for(int i = 1;i<5;i++)
    {
      List *t = input();
      t->next = temp;
      temp = t;
      last->next = t;
    }
    return last;
}
int display(List *last)
{
   List *temp = last->next; 
  while(temp != last)
  {
      printf("%d ",temp->data);
      temp = temp->next;
  }
  printf("%d",temp->data);
}
int main()
{
  List *last = create();
  display(last);
}