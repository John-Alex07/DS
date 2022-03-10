//JOHN ALEXANDER E 20011896
#include <stdio.h>
int c = -1;
int push(int *p, int n)
{
    int v;
    if (c == (n-1))
        printf("Stack Filled!!\n");
    else
    {
        printf("Enter a number\n");
        scanf("%d", &v);
        c++;
        printf("Pushed : %d\n\n", v,c);
        p[c] = v;
    }
}
int pop(int *p)
{
    if (c == -1)
        printf("Stack Empty!!\n");
    else
    {
        int t = p[c];
        p[c] = 0;
        printf("Popped : %d\n\n", t);
        c--;
    }
}
int print_stack(int *a,int n)
{
    for(int i=0;i<=c;i++)
    printf("%d ",a[i]);
}
int main()
{
    int n;
    printf("Enter the size:\n");
    scanf("%d", &n);
    int a[n];
    int p;
    while (p != 0)
    {
        printf("\nEnter 1 to PUSH\n");
        printf("Enter 2 to POP\n");
        if(c!=-1)
        printf("Enter 3 to Print the Stack\n");
        printf("Enter 0 to Stop\n");
        scanf("%d", &p);
        switch (p)
        {
        case 1:
            push(a, n);
            break;
        case 2:
            pop(a);
            break;
        case 3:
            print_stack(a,n);
            break;
        case 0:
             continue;
        default:
            printf("INVALiD CHOICE\n");
        }
    }
    return 0;
}
