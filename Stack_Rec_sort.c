#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct stack
{
    int top;
    int *arr;
    int n;
}Stack;
int push(Stack *s, int num)
{
    s->arr[++s->top] = num;
}
int pop(Stack *s)
{
    return s->arr[s->top--];
}
int stack(Stack *s)
{
    int num;
  printf("Enter %d numbers\n",s->n);
    for(int i = 0;i<s->n;i++)
     {
         scanf("%d",&num);
         push(s,num);
     }
}
int *arr(Stack *s, int *a)
{
    for(int i = 0;i<s->n;i++)
      a[i] = pop(s);
    return a;
}
int min(int *a, Stack *s)
{
   int min = INT_MAX,p = 0;
   for(int i=0;i<s->n;i++)
     if(min > a[i] && a[i] != INT_MAX)
       {
           min = a[i];
           p = i;
       }
    a[p] = INT_MAX;
    return min;
}
void sort(Stack *s, int *a)
{
    if(s->top != s->n)
       {
           int n = min(a,s);
           push(s,n);
           return sort(s,a);
       }
    else
       return;
}
void display(Stack *s)
{
    for(int i = 0;i<s->n;i++)
    printf("%d ",s->arr[i]);
}
int main()
{
    Stack s;
    s.top = -1;
    printf("Enter the number of elements in the stack\n");
    scanf("%d",&s.n);
    s.arr = (int*)malloc(sizeof(int)*s.n);
    stack(&s);
    int *a = (int*)malloc(sizeof(int)*s.n);
    a = arr(&s,a);
    sort(&s,a);
    display(&s);
}