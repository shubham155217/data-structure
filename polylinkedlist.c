#include <stdio.h>
#include <math.h>
#include <stdlib.h>
struct node
{
    int coeff;
    int expo;
    struct node *next;
};

struct node *create(struct node *list)
{
    struct node *newnode, *temp;\
    int n,i;
    printf("\n enter limit:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {

        newnode = (struct node *)malloc(sizeof(struct node));
        printf("\n enter coeff:");
        scanf("%d", &newnode->coeff);
        printf("\n enter expo:");
        scanf("%d", &newnode->expo);
        newnode->next = NULL;
        if (list == NULL)
        {
            list = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }
    return list;
}

void *disp(struct node *list)
{
    struct node *temp;
    for (temp = list; temp!= NULL; temp = temp->next)
    {
        printf("%d*%d\t+\t", temp->coeff, temp->expo);
    }
}

int  *eva(struct node *list)
{
 int ans=0,x;
 printf("\n enter value of  x:");
 scanf("%d",&x);
struct node *temp;
for(temp=list;temp!=NULL;temp=temp->next)
{
    ans=ans+temp->coeff*pow(x,temp->expo);
}  
printf("\n ans=%d",ans);
 
}

int main()
{
    struct node *list = NULL;
    list = create(list);
    disp(list);
    eva(list);
    return 0;
}