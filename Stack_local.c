#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int top;
    int n;
    int *a;
}Stk;
Stk* arr(Stk *s)
{
    s = (Stk*)malloc(sizeof(Stk));
    printf("Enter the limit\n");
    scanf("%d",&s->n);
    s->a = (int*)malloc(s->n * sizeof(int));
    s->top = -1;
    return s;
}
Stk* push(Stk *s)
{
   if(s->top == s->n)
   printf("STACK FULL");
   else
   {
       (s->top)++;
       printf("Enter a number\n");
       scanf("%d",&s->a[s->top]);
   }
   return s;
}
Stk* pop(Stk *s)
{
    if(s->top == -1)
    printf("STACK EMPTY\n");
    else
    {
        int t = s->a[s->top];
        printf("%d",t);
        s->top--;
    }
    return s;
}
int print(Stk *s)
{
    for(int i=0;i<=s->top;i++)
    printf("%d ",s->a[i]);
}
int main()
{
    Stk *s;  
    int p = 1;
    s = arr(s);
    while (p != 0)
    {
        printf("\nEnter 1 to PUSH\n");
        printf("Enter 2 to POP\n");
        if(s->top!=-1)
        printf("Enter 3 to Print the Stack\n");
        printf("Enter 0 to Stop\n");
        scanf("%d", &p);
        switch (p)
        {
        case 1:
            s = push(s);
            break;
        case 2:
            s = pop(s);
            break;
        case 3:
            print(s);
            break;
        case 0:
             continue;
        default:
            printf("INVALiD CHOICE\n");
        }
    }
    return 0;
}

    
