#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

struct Queue
{
    int elements[SIZE];
    int front, rear;
};


int main()
{
    struct Queue q;
    initQueue(&q);
    int ch,e;

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
    q->front = q->rear = -1;
}


int isFull(const struct Queue *q)
{
    if((q->rear+1)%SIZE == q->front)
        return 1;
    else
        return 0;
}

void EnQueue(struct Queue *q, int e)
{
    q->rear = (q->rear + 1) % SIZE;
    q->elements[q->rear] = e;
    if (q->front == -1)
        q->front++;

}

int isEmpty(const struct Queue *q)
{
    return (q->rear==-1);
}


int DeQueue(struct Queue *q)
{
    int e = q->elements[q->front];

    if(q->front == q->rear)
        q->front = q->rear = -1;
    else
    {
        q->front = (q->front + 1) % SIZE;
    }
    return e;
}


int getFront(const struct Queue *q)
{
    return q->elements[q->front];
}


int sizeQ(const struct Queue *q)
{
    int s;
    if(q->rear == -1)
        s=0;
    else if (q->front < q->rear)
        s = (q->rear) - (q->front) + 1;
    else
        s = (SIZE - q->front) + (q->rear + 1);
    return s;
}


void display(const struct Queue *q)
{
    int i;
    for (i=q->front; i!=q->rear; i = (i+1)%SIZE)
    {
        printf("%d\n",q->elements[i]);
    }
    if(q->front!=-1)
        printf("%d\n",q->elements[i]);
}













