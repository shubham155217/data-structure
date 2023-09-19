#define newalloc (struct node *)malloc(sizeof(struct node))
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *singly_circular_create(node *list)
{
    node *newnode, *temp;
    int n, i;
    printf("enter limit:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        newnode = newalloc;
        printf("\n enter value:");
        scanf("%d", &newnode->data);
        if (list == NULL)
        {
            list = newnode;
            temp = newnode;
            newnode->next = list;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
            newnode->next = list;
        }
    }
    return list;
}

void singly_circular_display(node *list)
{
    node *temp;
    temp = list;
    do
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    } while (temp != list);
}

node *singly_circular_insertbeg(node *list)
{
    node *newnode, *temp;
    newnode = newalloc;
    printf("\nenter value to insert a beg:");
    scanf("%d", &newnode->data);
    if (list == NULL)
    {
        list = newnode;
        newnode->next = list;
    }
    else
    {
        for (temp = list; temp->next != list; temp = temp->next)
            ;
        temp->next = newnode;
        newnode->next = list;
        list = newnode;
    }
    return list;
}

node *singly_circular_insertend(node *list)
{
    node *newnode, *temp;
    newnode = newalloc;
    printf("\nenter value to insert at end:");
    scanf("%d", &newnode->data);
    if (list == NULL)
    {
        list = newnode;
        newnode->next = list;
    }
    else
    {
        for (temp = list; temp->next != list; temp = temp->next)
            ;
        temp->next = newnode;
        newnode->next = list;
    }
    return list;
}

node *singly_circular_insertmid(node *list)
{
    node *newnode, *temp, *temp1;
    int pos, i;
    printf("enter position to insert:");
    scanf("%d", &pos);
    newnode = newalloc;
    printf("\nenter value to insert at mid:");
    scanf("%d", &newnode->data);
    if (pos == 1)
    {
        for (temp = list; temp->next != list; temp = temp->next)
            ;
        newnode->next = list;
        list = newnode;
        temp->next = list;
    }
    else
    {
        for (i = 1, temp = list; i < pos - 1 && temp->next != list; temp = temp->next, i++)
            ;
        temp1 = temp->next;
        temp->next = newnode;
        newnode->next = temp1;
    }
    return list;
}

node *singly_circular_deletebeg(node *list)
{

    node *temp1, *temp;
    for (temp = list; temp->next != list; temp = temp->next)
        ;
    temp1 = list;
    list = list->next;
    temp->next = list;
    free(temp1);
    return list;
}
node *singly_circular_deleteend(node *list)
{
    node *temp1, *temp;
    for (temp = list; temp->next->next != list; temp = temp->next)
        ;
    temp1 = temp->next;
    temp->next = list;
    free(temp1);
    return list;
}
node *singly_circular_deletemid(node *list)
{
    node *temp1, *temp;
    int i, pos;
    printf("enter position to delete:");
    scanf("%d", &pos);
    if (pos == 1)
    {
        for (temp = list; temp->next != list; temp = temp->next)
            ;
        temp1 = list;
        list = list->next;
        temp->next = list;
        free(temp1);
    }
    else
    {
        for (temp = list, i = 1; temp->next != list && i < pos - 1; temp = temp->next, i++)
            ;
        temp1 = temp->next;
        temp->next = temp1->next;
        free(temp1);
    }
    return list;
}
node *singly_circular_delete_by_value(node *list)
{
    node *temp1, *temp;
    int i, val, flag = 0;
    printf("enter value to delete:");
    scanf("%d", &val);
    temp1 = list;
    if (temp1->data == val)
    {
        for (temp = list; temp->next != list; temp = temp->next)
            ;
        list = list->next;
        temp->next = list;
        free(temp1);
    }
    else
    {

        for (temp = list; temp->next != list; temp = temp->next)
        {
            if (temp->next->data == val)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
        {

            temp1 = temp->next;
            temp->next = temp1->next;
            free(temp1);
        }
    }

    return list;
}
void *singly_circular_search_by_value(node *list)
{
    node *temp;
    int flag = 0, val;
    printf("enter value to search:");
    scanf("%d", &val);
    for (temp = list; temp->next != list; temp = temp->next)
    {
        if (temp->data == val)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        printf("\nvalue is found in the list");
    }
    else
    {
        printf("\nvalue is not found in the list");
    }
}


int main()
{
    node *list = NULL;
    int ch;
    do
    {
        printf("\n1:create\n2:display\n3:insertbeg\n4:insertend\n5:insertmid\n6:deletebeg\n7:deleteend\n8:deletemid\n9:delete_by_value\n10: search_by_value");

        printf("\n enter choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            list = singly_circular_create(NULL);
            break;
        case 2:
            singly_circular_display(list);
            break;
        case 3:
            list = singly_circular_insertbeg(list);
            break;
        case 4:
            list = singly_circular_insertend(list);
            break;
        case 5:
            list = singly_circular_insertmid(list);
            break;
        case 6:
            list = singly_circular_deletebeg(list);
            break;
        case 7:
            list = singly_circular_deleteend(list);
            break;
        case 8:
            list = singly_circular_deletemid(list);
            break;
        case 9:
            list = singly_circular_delete_by_value(list);
            break;
        case 10:
            list = singly_circular_search_by_value(list);
            break;
        default:printf("\n enter valid choice");
        }
    } while (ch < 15);
}
