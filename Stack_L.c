#include<stdio.h>
#include<stdlib.h>

void push(int *top,int *arr,int n)
{
    if(*top == n)
    {
        printf("stack overflow\n");
        return;
    }
    else
    {
        int data;
        printf("Enter a number\n");
        scanf("%d",&data);
        ++*top;
        printf("TOP:%d\n",*top);
        arr[*top]= data;
    }
}

void pop(int *top, int *arr)
{
    if(*top==-1)
    {
        printf("stack underflow\n"); return;
    }
    printf("%d\n",arr[(*top)--]);
}

void display(int *top, int *arr)
{
    if(*top==-1)
    {
        printf("nothing inside the stack.\n");
        return;
    }

    for(int i=*top;i>=0;i--)
    {
        printf("%d",arr[i]);
    }
    printf("\n");
}


int main()
{
    
    int n,m=1;
    printf("Size:\n");
    scanf("%d",&n);
    int arr[n];
    int top=-1;
    
    while(1)
    {
        printf("CHOICE:\n");
        scanf("%d",&m);
        switch(m)
        {
            case 1:
                push(&top,arr,n);
                break;
            case 2:
                pop(&top,arr);
                break;
            case 3:
                display(&top,arr);
                break;
            case 4:
                exit(1);
        }
    }

    return 0;
}