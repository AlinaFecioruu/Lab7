
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void display(struct node *head)
{
    if(head != NULL)
    {
        printf("%d ", head -> data);
        display(head->next);
    }
}

void copy(struct node *x,struct node **y)
{
    if(x!=NULL)
    {
        *y=malloc(sizeof(struct node));
        (*y)->data=x->data;
        (*y)->next=NULL;
        copy(x->next,&((*y)->next));
    }
}

void reverse(struct Node** head_ref)
{
    struct node* prev   = NULL;
    struct node* current = *head_ref;
    struct node* next;
    while (current != NULL)
    {
        next  = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

int main()
{
    struct node *prev,*a, *b, *p;
    int n,i;

    a=NULL;
    for(i=0; i<10; i++)
    {
        p=malloc(sizeof(struct node));
        scanf("%d",&p->data);
        p->next=NULL;
        if(a==NULL)
            a=p;
        else
            prev->next=p;
        prev=p;
    }

    copy(a,&b);
    reverse(&b);
    display(b);
    return 0;
}

