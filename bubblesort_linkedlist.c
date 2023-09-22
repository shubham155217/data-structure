#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *create(struct node *list)
{
    int i, n;
    struct node *newnode, *temp;
    printf("Enter limit:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter value:");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        if (list == NULL)
        {
            list = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }
    return list;
}
void disp(struct node *list)
{
    struct node *temp;
    for (temp = list; temp != NULL; temp = temp->next)
    {
        printf("%d\t", temp->data);
    }
}


struct node *bubble(struct node *list)
{
    struct node *temp,*temp1;
    int t;

    for(temp=list;temp->next!=NULL;temp=temp->next)
    {
        for(temp1=list;temp1->next!=NULL;temp1=temp1->next)
        {
            if(temp1->data>temp1->next->data)
            {
                t=temp1->data;
                temp1->data=temp1->next->data;
                temp1->next->data=t;
            }
        }
    }
    return list;
}

int main()
{
    int ch, num;
    struct node *list1 = NULL;
    list1 = create(list1);
    disp(list1);
    printf("\n sorted list:");
    bubble(list1);
    disp(list1);

    
}