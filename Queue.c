#include <stdio.h>
#include <stdlib.h>
typedef struct mem
{
    int *arr;
    int top;
    int rear;
    int n;
}Queue;
Queue *ini(Queue *Que)
{
    printf("Enter the size of Queue\n");
    scanf("%d",&(Que->n));
    printf("%d",Que->n);
    Que->arr = (int*)malloc(sizeof(int));
    Que->rear = -1;
    Que->top = -1;
    return Que;
}
Queue *enqueue(Queue *Que)
{
    if(Que->rear == Que->n)
    printf("Queue OVERFLOW\n");
    else
    {
        int t;
        printf("Enter a number\n");
        scanf("%d",&t);
        if(Que->top == -1)
         Que->top = 0;
         (Que->rear)++;
         Que->arr[Que->rear] = t;
         printf("PUSHED : %d at %d",Que->arr[Que->rear],Que->rear);
         Que->arr = realloc(Que->arr, Que->rear+1);
    }
    return Que;
}
Queue *dequeue(Queue *Que)
{
    if(Que->top == Que->rear)
        printf("Queue EMPTY\nRESET QUEUE\n");
    else
    {
        printf("POPPED : %d from %d\n",Que->arr[Que->top],Que->top);
        (Que->top)++;
    }
    return Que;
}
Queue display(Queue *Que)
{
    for(int i = Que->top; i<=Que->rear; i++)
      printf("%d ",Que->arr[i]);
}
int main()
{
    Queue *Q;
    Q = (Queue*)malloc(sizeof(Queue));
    Q = ini(Q);
     int p = -2;
    while (p != 0)
    {
        printf("\nEnter 1 to Input to the Queue\n");
        printf("Enter 2 to Delete from Queue\n");
        printf("Enter 3 to Print the Queue\n");
        printf("Enter -1 to RESET QUEUE\n");
        printf("Enter 0 to Stop\n");
        scanf("%d", &p);
        switch (p)
        {
        case 1:
           Q = enqueue(Q);
            break;
        case 2:
            Q = dequeue(Q);
            break;
        case 3:
            display(Q);
            break;
        case -1 :
            Q = ini(Q);
            break;
        case 0:
             continue;
        default:
            printf("INVALiD CHOICE\n");
        }
    }
    return 0;
}