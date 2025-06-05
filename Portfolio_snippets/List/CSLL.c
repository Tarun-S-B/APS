#include<stdio.h>

struct node
{
    int data;
    struct node *next;
};


int main()
{
    struct node *tail = NULL;
    int ch, e;

    while(1)
    {
        printf("1. Add at Beginning\n");
        printf("2. Add at End\n");
        printf("3. Delete at Beginning\n");
        printf("4. Delete at End\n");
        printf("5. Add node at given position\n");
        printf("6. Display List\n");
        printf("7. Length of List\n");
        printf("8. Search the key\n");

        printf("Enter choice: ");
        scanf("%d",&ch);

        switch (ch)
        {
            case 1: printf("Enter data: ");
                    scanf("%d",&e);
                    addAtBegin(&tail, e);
                    break;

            case 2: printf("Enter data: ");
                    scanf("%d",&e);
                    addAtEnd(&tail, e);
                    break;

            case 3: if(tail == NULL)
                        printf("List is Empty");
                    else
                    {
                        e = delAtBegin(&tail);
                        printf("%d",e);
                        break;
                    }

            case 4: if(tail == NULL)
                        printf("List is Empty");
                    else
                    {
                        e = delAtEnd(&tail);
                        printf("%d",e);
                        break;
                    }

            case 6: displayList(tail);
                    break;
        }

    printf("\n");
    }

}



void displayList(struct node *tail)
{
    struct node *curr = (tail);

    do
    {
        printf("%d\n",curr->data);
        curr = curr->next;
    }
    while (curr != tail);
}



int delAtEnd(struct node **tail)
{
    struct node *curr = (*tail)->next;
    struct node *prev = NULL;

    while(curr!=*tail)
    {
        prev = curr;
        curr = curr->next;
    }
    int e = curr->data;

    if (prev!=NULL)
        prev->next = (*tail)->next;

    *tail = prev;
    free(curr);
    return e;

}



int delAtBegin(struct node **tail)
{
    struct node *curr = (*tail)->next;

    (*tail)->next = curr->next;

    int e = curr->data;

    if (curr == *tail)
        *tail == NULL;
    free(curr);
    return e;

}


void addAtEnd(struct node **tail, int e)
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));

    if (p==NULL)
    {
        perror("No Memory");
        return;
    }

    p->data = e;
    p->next = p;

    if ((*tail)==NULL)
        (*tail) = p;
    else
    {
        p->next = (*tail)->next;
        (*tail)->next = p;
        (*tail) = p;
    }
}


void addAtBegin(struct node **tail, int e)
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));

    if (p==NULL)
    {
        perror("No Memory");
        return;
    }

    p->data = e;
    p->next = NULL;

    if ((*tail)==NULL)
    {
        *tail=p;
    }
    else
    {
        p->next = (*tail)->next;
        (*tail)->next = p;
    }
}
