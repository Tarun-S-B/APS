#include<stdio.h>
#define SIZE 20

struct Queue
{
    int elements[SIZE];
    int front, rear;
};

struct Stack
{
    int elements[SIZE];
    int top;
};

void EnQueue(struct Queue *q, int e);
void reverseK(int n, int k);

int main()
{
    int n, k;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    printf("Enter no of elements to skip: ");
    scanf("%d",&k);

    reverseK(n, k);



}


void reverseK(int n, int k)
{
    struct Queue q;
    q.front = q.rear = -1;
    struct Stack s;
    s.top = -1;
    int e;
    int i;

    printf("Enter the elements:\n");
    for (i=0; i<n; i++)
    {
        scanf("%d",&e);
        EnQueue(&q, e);
    }

    for(i=0; i<k; i++)
    {
        push(&s,DeQueue(&q));
    }

    while(!isEmpty(&s))
        {printf("In while\n");
            EnQueue(&q,pop(&s));
        }
printf("out while");
    for (int i=1; i<=n-k; i++)
        EnQueue(&q,DeQueue((&q)));


    displayQ(&q);
}


void EnQueue(struct Queue *q, int e)
{
    q->rear = (q->rear + 1) % SIZE;
    q->elements[q->rear] = e;
    if (q->front == -1)
        q->front++;
}

int DeQueue(struct Queue *q)
{
    int e = q->elements[q->front];

    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
    {
        q->front = (q->front + 1 ) % SIZE;
    }
    return e;
}


void push(struct Stack *s, int e)
{
    s->top++;
    s->elements[s->top] = e;
}

int pop(struct Stack *s)
{
    int e = s->elements[s->top];
    s->top--;
    return e;
}

int isEmpty(struct Stack *s)
{
    return s->top == -1;
}

int displayQ(struct Queue *q)
{
    int i;
    for (i=q->front; i!=q->rear; i = (i+1)%SIZE)
        printf("%d\n",q->elements[i]);

    if (i!=-1)
        printf("%d\n",q->elements[i]);
}
