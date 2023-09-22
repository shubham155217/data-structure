#define newalloc (struct node *)malloc(sizeof(struct node));
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next, *prev;
} node;

node *doubly_circular_create(node *list)
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
            newnode->prev = NULL;
            newnode->next = list;
            list->prev = newnode;
        }
        else
        {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
            newnode->next = list;
            list->prev = newnode;
        }
    }
    return list;
}

void doubly_circular_display(node *list)
{
    node *temp;
    temp = list;
    do
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    } while (temp != list);
}

node *doubly_circular_insertbeg(node *list)
{
    node *newnode, *temp;
    newnode = newalloc;
    printf("\nenter value to insert a beg:");
    scanf("%d", &newnode->data);
    if (list == NULL)
    {
        list = newnode;
        temp = newnode;
        newnode->prev = NULL;
        newnode->next = list;
        list->prev = newnode;
    }
    else
    {
        newnode->next = list;
        list->prev = newnode;
        list->next = newnode;
        newnode->prev = list;
        list = newnode;
    }

    return list;
}

node *doubly_circular_insertend(node *list)
{
    node *newnode, *temp;
    newnode = newalloc;
    printf("\nenter value to insert at end:");
    scanf("%d", &newnode->data);
    if (list == NULL)
    {
        list = newnode;
        temp = newnode;
        newnode->prev = NULL;
        newnode->next = list;
        list->prev = newnode;
    }
    else
    {
        for (temp = list; temp->next != list; temp = temp->next)
            ;
        temp->next = newnode;
        newnode->prev = temp;
        newnode->next = list;
        list->prev = newnode;
    }
    return list;
}

node *doubly_circular_insertmid(node *list)
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
            newnode->next = list;
        list->prev = newnode;
        list = newnode;
        list->prev = temp;
        temp->next = list;
    }
    else
    {
        for (i = 1, temp = list; i < pos - 1 && temp->next != list; temp = temp->next, i++)
            ;
        temp1 = temp->next;
        temp->next = newnode;
        newnode->prev = temp1;
        newnode->next = temp1;
        temp1->prev = newnode;
    }
    return list;
}

node *doubly_circular_deletebeg(node *list)
{

    node *temp1, *temp;
    for (temp1 = list; temp1->next != list; temp1 = temp1->next)
        ;
    temp = list;
    list = list->next;
    temp1->next = list;
    list->prev = temp1;
    free(temp);
    return list;
}
node *doubly_circular_deleteend(node *list)
{
    node *temp1, *temp;
    for (temp = list; temp->next->next != list; temp = temp->next)
        ;
    temp1 = temp->next;
    temp->next = list;
    list->prev = temp;
    free(temp1);
    return list;
}
node *doubly_circular_deletemid(node *list)
{
    node *temp1, *temp;
    int i, pos;
    printf("enter position to delete:");
    scanf("%d", &pos);
    if (pos == 1)
    {
        for (temp1 = list; temp1->next != list; temp1 = temp1->next)
            ;
        temp = list;
        list = list->next;
        temp1->next = list;
        list->prev = temp1;
        free(temp);
    }
    else
    {
        for (i = 1, temp = list; i < pos - 1 && temp->next != list; temp = temp->next, i++)
            ;
        temp1 = temp->next;
        temp->next = temp1->next;
        temp1->next->prev = temp;
        free(temp1);
    }
    return list;
}
node *doubly_circular_delete_by_value(node *list)
{
    node *temp1, *temp;
    int i, val, flag = 0;
    printf("enter value to delete:");
    scanf("%d", &val);
    temp1 = list;

    if (list->data == val)
    {
        for (temp = list; temp->next != list; temp = temp->next)
            ;
        temp1 = list;
        list = list->next;
        temp->next = list;
        list->prev = temp;

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
            temp1->next->prev = temp;
            free(temp1);
        }
    }
    return list;
}
void *doubly_circular_search_by_value(node *list)
{
    node *temp;
    int flag = 0, val;
    printf("enter value to search:");
    scanf("%d", &val);
    if (list->data == val)
    {
        printf("\n value is found");
    }
    else
    {

        for (temp = list->next; temp != list; temp = temp->next)
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
}

int main()
{
    int ch;
    node *list = NULL;
    do
    {
        printf("\n1:create\n2:display\n3:insertbeg\n4:insertend\n5:insertmid\n6:deletebeg\n7:deleteend\n8:deletemid\n9:delete_by_value\n10: search_by_value");

        printf("\n enter choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            list = doubly_circular_create(NULL);
            break;
        case 2:
            doubly_circular_display(list);
            break;
        case 3:
            list = doubly_circular_insertbeg(list);
            break;
        case 4:
            list = doubly_circular_insertend(list);
            break;
        case 5:
            list = doubly_circular_insertmid(list);
            break;
        case 6:
            list = doubly_circular_deletebeg(list);
            break;
        case 7:
            list = doubly_circular_deleteend(list);
            break;
        case 8:
            list = doubly_circular_deletemid(list);
            break;
        case 9:
            list = doubly_circular_delete_by_value(list);
            break;
        case 10:
            list = doubly_circular_search_by_value(list);
            break;
        default:
            printf("\n enter valid choice");
        }
    } while (ch <= 20);
}
