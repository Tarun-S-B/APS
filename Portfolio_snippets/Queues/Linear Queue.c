#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

struct Queue
{
    int elements[SIZE];
    int front, rear;
};


int isFull(const struct Queue *q);

int main()
{
    struct Queue q;
    initQueue(&q);
    int e,ch,m;

    while(1)
    {
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.get Front\n");
        printf("4.Display\n");
        printf("5.Size\n");
        printf("6.Exit\n");

        printf("Enter Choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: if(isFull(&q))
                        printf("Queue is Full\n");
                    else
                    {
                        printf("Enter data: ");
                        scanf("%d",&e);
                        EnQueue(&q, e);
                    }
                    break;

            case 2: if(isEmpty(&q))
                        printf("Queue is Empty\n");
                    else
                    {
                        e = DeQueue(&q);
                        printf("%d",e);
                    }
                    break;

            case 3: if(isEmpty(&q))
                        printf("Queue is Empty\n");
                    else
                    {
                        e = getFront(&q);
                        printf("%d",e);
                    }
                    break;

            case 4: display(&q);
                    break;
            case 5: e = sizeQ(&q);
                    printf("%d",e);
                    break;
            case 6: exit(0);
        }
    }

}

void initQueue(struct Queue *q)
{
    q->front = 0;
    q->rear = -1;
}


void EnQueue(struct Queue *q, int e)
{
    q->rear ++;
    q->elements[q->rear] = e;
}


int isFull(const struct Queue *q)
{
    return q->rear == SIZE - 1;
}


int DeQueue(struct Queue *q)
{
    int e = q->elements[q->front];
    q->front++;
    return e;
}


int isEmpty(const struct Queue *q)
{
    if (q->front > q->rear)
        return 1;
    else
        return 0;
}


int getFront(const struct Queue *q)
{
    return (q->elements[q->front]);
}


void display(const struct Queue *q)
{
    for (int i=q->front; i<=q->rear; i++)
    {
        printf("%d\n", q->elements[i]);
    }
}


int sizeQ(const struct Queue *q)
{
    return ((q->rear)-(q->front)+1);
}









