#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * next;
};


void addAtBeg(struct node **, int);
int deleteAtBeg(struct node **);
void displayList(struct node *);


int main()
{
    struct node *head = NULL;
    int e, key, f, pos, ch=100;
    struct node *p;


    while(ch!=0)
    {
        printf("1. Add Data at the beginning of the list\n");
        printf("2. Delete at the Beginning\n");
        printf("3. Add at End\n");
        printf("4. Delete at End\n");
        printf("5. Display List\n");
        printf("6. Length of list\n");
        printf("7. Search an element in list\n");
        printf("8. Frequency of an element\n");
        printf("9. Add node at given position\n");
        printf("10.Delete node from given position\n");
        printf("11.Reverse a list\n");
        printf("12.Delete First Occurence\n");
        printf("13.Delete Last Occurence\n");
        printf("14.Reverse every K nodes\n");
        printf("***********************************************\n");


        printf("Enter choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: printf("Enter Data: ");
                    scanf("%d",&e);
                    addAtBeg(&head, e);
                    break;

            case 2: if (head==NULL)
                    {
                        printf("List is Empty\n");
                    }
                    e = deleteAtBeg(&head);
                    printf("Deleted Data: %d\n",e);
                    break;

            case 3: printf("Enter data to be added: ");
                    scanf("%d",&e);
                    addAtEnd(&head, e);
                    break;

            case 4: e = deleteAtEnd(&head);
                    printf("Deleted data: %d\n",e);
                    break;

            case 5: printf("Displaying the list:\n");
                    displayList(head);
                    break;

            case 6: e = lengthOfList(head);
                    printf("Length of List: %d\n",e);
                    break;

            case 7: printf("Enter element to be searched: ");
                    scanf("%d",&e);
                    e = searchElement(head, e);
                    if (e)
                        printf("Element Found\n");
                    else
                        printf("Element not found\n");
                    break;

            case 8: printf("Enter Key: ");
                    scanf("%d",&key);
                    f = frequency(head, key);
                    printf("Frequency = %d\n",f);
                    break;

            case 9: printf("Enter data: ");
                    scanf("%d",&e);
                    printf("Enter position: ");
                    scanf("%d",&key);
                    addAtPos(&head, e, key);
                    break;

            case 10: if (head == NULL)
                        printf("List if empty\n");
                    else
                    {
                        printf("Enter position: ");
                        scanf("%d",&pos);
                        e = deleteAtPos(&head, pos);
                        printf("Deleted data: %d\n",e);
                    }
                    break;

            //case 11:reverseList(&head);
                    //break;

            case 12:printf("Enter key: ");
                    scanf("%d",&key);
                    //e = delFirstOcc(&head,key);
                    break;

            case 14:printf("Enter k: ");
                    scanf("%d",&key);
                    reverseKNodes(&head,key);
                    break;


        }
        printf("\n");

    }
}


void reverseKNodes(struct node **head,int k)
{
    struct node *cur=*head;
    struct node *prev=NULL;

    int n=lengthlist(*head)/k;

    struct node *p=*head;
    struct node *q=NULL;
    struct node *r=NULL;

    if(p!=NULL)
        q=p->next;

        if(q!=NULL)
        r=q->next;

        int i,count;

        for( i=1;i<=n;i++)
        {
            for(count=1;count<k;count++)
            {
                q->next=p;
                p=q;
                q=r;
                r=r->next;
            }

            if(i==1)
                *head=p;
            else
            prev->next=p;

            cur->next=q;
            prev=cur;
            cur=q;
            p=q;
            q=r;
            if(r!=NULL)
                r=r->next;

        }


}


int lengthlist(struct node *head)
{
    struct node *cur=head;

    int count=0;

    while(cur!=NULL)
    {
        count++;
        cur=cur->next;
    }
    return count;

}


int deleteAtPos(struct node **head, int pos)
{
    struct node *curr = *head;
    struct node *prev = NULL;
    int e;

    if (pos<=0 || (*head)->next==NULL)
    {
        e = (*head)->data;
        free(*head);
        (*head) = NULL;
        return;
    }

    for (int i=0; i<pos && curr->next!=NULL; i++)
    {
        prev = curr;
        curr = curr->next;
    }

    e = curr->data;
    prev->next = curr->next;
    free(curr);
    return e;

}



void addAtPos(struct node **head, int e, int pos)
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));

    if (p==NULL)
    {
        perror("No memory available");
        return;
    }

    p->data = e;
    p->next = NULL;

    if(pos<=0 || (*head)==NULL)
    {
        p->next = *head; //NULL
        *head = p;
        return;
    }

    struct node *curr = *head;
    struct node *prev = NULL;

    for (int i=0; i<pos && curr!=NULL; i++)
    {
        prev = curr;
        curr = curr->next;
    }

    prev->next = p;
    p->next = curr;

    return;
}




int frequency(struct node *head, int key)
{
    int count = 0;
    struct node *p = head;

    while(p)
    {
        if (p->data == key)
            count ++;

        p = p->next;
    }
    return count;

}




int searchElement(struct node *head, int key)
{
    struct node *p = head;

    while(p)
    {
        if(p->data == key)
            return 1;


        p = p->next;
    }

    return 0;
}




int lengthOfList(struct node *head)
{
    int c=0;
    while(head)
    {
        c++;
        head = head->next;
    }
    return c;
}


int deleteAtEnd(struct node **head)
{
    struct node *curr;
    struct node *prev;
    int e;

    prev = NULL;
    curr = *head;

    while(curr->next)
    {
        prev = curr;
        curr = curr->next;
    }

    e = curr->data;
    prev->next = NULL;
    free(curr);
    return e;
}



void addAtEnd(struct node **head, int e)
{
    struct node *p, *q;

    p = (struct node *)malloc(sizeof(struct node));

    if (p==NULL)
    {
        perror("Np memory available\n");
        return;
    }

    p->data = e;
    p->next = NULL;

    if(*head==NULL)
    {
        (*head) = p;
    }
    else
    {
        q = *head;
        while(q->next)
        {
            q = q->next;
        }

        q->next = p;
    }


}




int deleteAtBeg(struct node **head)
{
    struct node *p = head;
    int e;

    e = (*head)->data;
    *head = (*head)->next;

    free(p);
    return e;
}



void displayList(struct node *head)
{
    struct node *p = head;

    if(head==NULL)
    {
        perror("List is Empty");
        return;
    }

    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}


void addAtBeg(struct node **head, int e)
{
    struct node *p;

    p = (struct node *)malloc(sizeof(struct node));

    if (p==NULL)
    {
        perror("No memory available.\n");
        return;
    }

    p->data = e;
    p->next = *head;
    *head = p;
}
