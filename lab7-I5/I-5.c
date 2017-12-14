
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

void push(struct node** head_ref, int new_data)
{
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
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

void sort(struct node **h)
{
    int i,j,a;
    struct node *temp1;
    struct node *temp2;

    for(temp1=*h;temp1!=NULL;temp1=temp1->next)
      {
        for(temp2=temp1->next;temp2!=NULL;temp2=temp2->next)
          {
            if(temp2->data < temp1->data)
              {
                a = temp1->data;
                temp1->data = temp2->data;
                temp2->data = a;
              }
           }
       }
}

int main()
{
    struct node *prev,*a, *b, *p;
    int n,i;

    a=NULL;
    for(i=0; i<25; i++)
    {
        scanf("%d",&n);
        push(&a,n);
    }
    reverse(&a);
    sort(&a);
    display(a);
    int s=0;
    while(a!=NULL)
    {
        s=s+a->data;
        a=a->next;
    }
    float m=(float) s/25;
    printf("\nThe sum is: %d and the average is: %.2f",s,m);
    return 0;
}
