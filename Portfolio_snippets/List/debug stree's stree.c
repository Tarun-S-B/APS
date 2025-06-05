#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node*next;
};

void addAtEnd(struct node** ,int);
int joshephus(int,int);

int main()
{
    int n,k,e;

    printf("Enter  n:");
    scanf("%d",&n);

    printf("Enter k:");
    scanf("%d",&k);

    e = joshephus(n,k);

    printf("%d\n",e);
    return 0;
}

int joshephus(int n,int k)
{
    struct node*tail = NULL;

    for(int i=0;i<=n;i++)
    {
        addAtEnd (&tail , i);
        struct node* cur = (tail)->next;
        struct node* prev = NULL;

        while(tail -> next!=tail)
        {
            for(int i=1;i<k;i++)
            {
              prev = cur;
              cur = cur -> next;
            }
        }
            prev -> next = cur -> next;
            if(cur == tail)
            {
                tail = prev;
                free(cur);
                cur = prev -> next;

            }
            return tail -> data;
        }
    }

void addAtEnd(struct node **tail ,int e)
{
    struct node*p;
    p=(struct node*)malloc(sizeof (struct node));

    if(p==NULL)
    {
        perror("not found\n");
        return;
    }

    p -> data = e;
    p -> next = p;

    if(*tail == NULL)
    {
        (*tail) = p;
    }

    else
    {
        p -> next = (*tail) -> next;

        (*tail) -> next = p;

        (*tail) = p;

    }
}
