#include <stdio.h>
#include <stdlib.h>

struct node
{
   int data;
   struct node *next;
};

struct node *the_list = NULL;
struct node *current = NULL;


void print_the_list()
{
  struct node *ptr = the_list;

   printf("\nthe list ->");

   while(ptr != NULL) {
      printf(" %d ->",ptr->data);
      ptr = ptr->next;
   }

   printf(" NULL\n");
    }

void insert_link(int data)
{
    struct node *link = (struct node*) malloc(sizeof(struct node));
    link->data = data;
    link->next = the_list;
    the_list = link;
}


int main()
 {
    int n;
    int i;
    int v[100];

    printf("number of components:\n");
    scanf("%d",&n);

    for(i=1;i<=n;i++)
   {
        printf("the value: ");
        scanf("%d",&v[i]);
        insert_link(v[i]);
    }

   print_the_list();
   return 0;
}

