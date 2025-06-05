#include<stdio.h>

struct node
{
    int data;
    struct node * next;
};

void addAtBeginning(struct node **, int);
int deleteAtBeginning(struct node **);
void addAtEnd(struct node **, int);
int deleteAtEnd(struct node **);
void displayList(struct node *);
int lengthList(struct node *);
int searchElement(struct node *, int);
int frequencyElement(struct node *, int);
void addAtPos(struct node **, int, int);
int delAtPos(struct node **, int);
void reverseList(struct node **);


int main()
{
    struct node *head = NULL;
    int e, ch, l, f, pos;

    while(1)
    {
        printf("1. Add at beginning\n");
        printf("2. Delete at Beginning\n");
        printf("3. Add at End\n");
        printf("4. Delete at End\n");
        printf("5. Display List\n");
        printf("6. Length of List\n");
        printf("7. Search an Element\n");
        printf("8. Frequency of Element\n");
        printf("9. Add at given position\n");
        printf("10.Delete at given position\n");
        printf("11.Reverse the List\n");
        printf("12.Delete First Occurence\n");

        printf("14.Delete All Occurence\n");


        printf("Enter Choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: printf("Enter data: ");
                    scanf("%d",&e);
                    addAtBeginning(&head, e);
                    break;

            case 2: if(head==NULL)
                        printf("List is empty\n");
                    else
                    {
                        e = deleteAtBeginning(&head);
                        printf("%d\n",e);
                        break;
                    }


            case 3: printf("Enter data: ");
                    scanf("%d",&e);
                    addAtEnd(&head, e);
                    break;

            case 4: if(head==NULL)
                        printf("List is empty\n");
                    else
                    {
                        e = deleteAtEnd(&head);
                        printf("%d\n",e);
                        break;
                    }

            case 5: displayList(head);
                    break;

            case 6: l = lengthList(head);
                    printf("Length: %d\n",l);
                    break;

            case 7: printf("Enter the Element to search: ");
                    scanf("%d",&e);
                    if(searchElement(head, e))
                        printf("Element found\n");
                    else
                        printf("Element Not found\n");
                    break;

            case 8: printf("Enter the Element to search: ");
                    scanf("%d",&e);
                    f = frequencyElement(head, e);
                    printf("Frequency: %d\n",f);
                    break;

            case 9: printf("Enter data: ");
                    scanf("%d",&e);
                    printf("Enter Position: ");
                    scanf("%d",&pos);
                    addAtPos(&head, e, pos);
                    break;

            case 10:printf("Enter Position: ");
                    scanf("%d",&pos);
                    e = delAtPos(&head, pos);
                    printf("%d",e);
                    break;

            case 11:reverseList(&head);
                    break;

            case 12:printf("Enter Element: ");
                    scanf("%d",&e);
                    if(delFirstOcc(&head, e))
                        printf("Key Found and Deleted\n");
                        printf("Key Not Found\n");
                    break;

            case 14:printf("Enter Element:");
                    scanf("%d",&e);
                    delAllOcc(&head, e);
                    break;

            default: exit(0);
        }
        printf("\n");
    }
}


void sortList(struct node *head)
{
    struct node *i;
    struct node *min;
    struct node *j;

    int temp;

    for (i=head; i!=NULL; i=i->next)
    {
        for (j = i->next; j!=NULL; j=j->next)
        {
            if (j->data < min->data)
                min = j;

        }

        temp = i->data;
        i->data = min->data;
        min->data = temp;
    }

}



int delAllOcc(struct node **head, int e)
{
    struct node *curr = *head;
    struct node *prev = NULL;

    int flag = 0;

    while(curr)
    {
        if (curr->data == e)
        {
            if (curr == *head)
            {
                *head = (*head)->next;
                free(curr);
                curr = (*head);
                flag = 1;
            }
            else
            {
                prev->next = curr->next;
                free(curr);
                curr = prev->next;
                flag = 1;
            }
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }
    return flag;
}



int delFirstOcc(struct node **head, int e)
{
    struct node *curr = *head;
    struct node *prev = NULL;

    while(curr && curr->data!=e)
    {
        prev = curr;
        curr = curr->next;
    }

    if (curr==NULL)
        return 0;

    if (curr==*head)
    {
        *head = (*head)->next;
        free(curr);
        return 1;
    }

    prev->next = curr->next;
    free(curr);
    return 1;
}


void reverseList(struct node **head)
{
    struct node *p, *q, *r;

    p = *head;
    if (p!=NULL)
        q = p->next;
    if (q!=NULL)
        r = q->next;

    while(q)
    {
        q->next = p;
        p = q;
        q = r;
        if (r!=NULL)
            r = r->next;
    }

    if ((*head)!=NULL)
        (*head)->next = NULL;

    *head = p;
}


int delAtPos(struct node **head, int pos)
{
    struct node *curr = *head;
    struct node *prev = NULL;

    int e;

    if (pos<=0 || *head == NULL)
    {
        e = curr->data;
        *head = (*head)->next;
        free(curr);
        return e;
    }


    for (int i=0; i<pos && curr->next!=NULL; i++)
    {
        prev = curr;
        curr = curr->next;
    }

    prev->next = curr->next;
    e = curr->data;
    free(curr);
    return e;
}




void addAtPos(struct node **head, int e, int pos)
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));

    if(p==NULL)
    {
        perror("No Memoery");
        return;
    }

    p->data = e;
    p->next = NULL;

    if(pos<=0 || *head==NULL)
    {
        p->next = *head;
        *head = p;
        return;
    }


    struct node *curr = *head;
    struct node *prev = NULL;

    for (int i=0; i<pos; i++)
    {
        prev = curr;
        curr = curr->next;
    }

    prev->next = p;
    p->next =  curr;
}



int frequencyElement(struct node *head, int e)
{
    int f = 0;
    struct node *curr = head;
    while(curr)
    {
        if(curr->data == e)
            f++;
        curr = curr->next;
    }
    return f;
}


int searchElement(struct node *head, int e)
{
    struct node *p = head;
    while(p)
    {
        if(p->data == e)
            return 1;
        p = p->next;
    }
    return 0;
}



int lengthList(struct node *head)
{
    int count = 0;
    struct node *p = head;
    while(p)
    {
        count++;
        p = p->next;
    }
    return count;
}


int deleteAtEnd(struct node **head)
{
    struct node *curr = *head;
    struct node *prev = NULL;

    while(curr->next)
    {
        prev = curr;
        curr = curr->next;
    }

    int e = curr->data;
    free(curr);
    prev->next = NULL;
    return e;

}



void addAtEnd(struct node **head, int e)
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));

    if(p==NULL)
    {
        perror("No Memory");
        return;
    }

    p->data = e;
    p->next = NULL;


    if(*head==NULL)
        *head = p;
    else
    {
        struct node *curr = *head;
        while(curr->next)
            curr = curr->next;

        curr->next = p;
    }





}



int deleteAtBeginning(struct node **head)
{
    struct node *curr = *head;

    int e = curr->data;
    *head = (*head)->next;
    free(curr);
    return e;

}


void displayList(struct node *head)
{
    struct node * curr = head;
    while(curr)
    {
        printf("%d\n",curr->data);
        curr = curr->next;
    }
}


void addAtBeginning(struct node **head, int e)
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));

    if (p==NULL)
    {
        perror("No memory");
        return 0;
    }

    p->data = e;
    p->next = *head;


    *head = p;


}
