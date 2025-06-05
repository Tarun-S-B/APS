#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<strings.h>


//ERRORS ARE COMMENTED

struct student
{
    int rNo;
    char name[20];
};
struct node
{
    struct student data;
    struct node *next;
};


struct student delAtBegin(struct node **head);
void read(struct student * p);
void addAtBegin(struct node **head,struct student e);
void display(struct student *p);
void displayList(struct node *head);
int search(struct node *head,char name[20]);


int main()
{
    struct node *head=NULL;
    int ch;
    struct student e, p;

    char name[20];

    while(1)
    {
        printf("1.Add node at the beginning of list\n");
        printf("2.Delete node at the beginning of list\n");
        printf("3.Search student's detail by name\n");
        printf("4.Display student's list\n");
        printf("5.exit\n");

        printf("Enter your choice\n");
        scanf("%d",&ch);

        switch(ch)
        {   case 1:read(&e);
                    addAtBegin(&head,e);
                    break;

            case 2:if(head==NULL)
                    printf("List Empty");
                    else
                    {
                        p=delAtBegin(&head);
                        display(&p);
                    }
                    break;

            case 3:printf("Enter name to be searched:");
                    scanf("%s",name);

                    int f=search(head,name);
                    if(f==1)
                        printf("Name found");
                    else
                        printf("Name not found");
                    break;

            case 4:displayList(head);
                    break;


            case 5:printf("Exited");
                    exit(0);
        }
    }
}

void read(struct student * p)
{

        printf("Enter student's roll no:");
        scanf("%d",&p->rNo);
        printf("Enter student's name:");
        scanf("%s",p->name);
}



void addAtBegin(struct node **head,struct student e)
{
        struct node *p;
        p=(struct node *)malloc(sizeof(struct node));

        if(p==NULL)
        {

            perror("");
            return ;
        }

    p->data=e;
    p->next=*head;
    *head=p;
}

void display(struct student *p)
{
        printf("Student's roll number:%d",p->rNo);
        printf("Student's Name:%s",p->name);
}

void displayList(struct node *head)
{
    struct node *cur=head;
        printf("Displaying Complete list\n");
    while(cur!=NULL)
    {
        printf("|rNo=%d |",cur->data.rNo);
        printf("Name=%s|\n",cur->data.name);
        cur=cur->next;
    }
}

struct student delAtBegin(struct node **head)
{
    struct student e;
    struct node *p=*head;

   e=p->data;

   *head=(*head)->next;
   free(p);
   return e;

}

int search(struct node *head,char name[20])
{

    struct node *cur=head;

    while(cur!=NULL)
    {
        int c=strcasecmp(cur->data.name,name);
        if(c==0)
            return 1;
            cur=cur->next;
    }
    return 0;
}
